#include <iostream>

using namespace std;

/*
    4-6
    Let’s create an implementation for strings that uses a linked list of characters
    instead of dynamically allocated arrays. So we’ll have a linked list where the
    data payload is a single char; this will allow strings to grow without having to recreate the entire string.
    We’ll start by implementing the append and characterAt functions.

    4-7
    Following up on the previous exercise, implement the concatenate function.

    Note that if we make a call concatenate(s1, s2), where both parameters are
    pointers to the first nodes of their respective linked lists, the function should
    create a copy of each of the nodes in s2 and append them to the end of s1.

    That is, the function should not simply point the next field of the last node in
    s1’s list to the first node of s2’s list

    4-8
    Add a function to the linked-list string implementation called removeChars to
    remove a section of characters from a string based on the position and length.

    For example, removeChars(s1, 5, 3) would remove the three characters starting
    at the fifth character in the string. Make sure the removed nodes are properly
    deallocated.
 */


typedef struct charNode {
    char letter;
    charNode *nextChar;
} charNode;

char characterAt(charNode *charList, int position) {
    int counter = 0;
    while (charList != nullptr && counter < position - 1) {
        ++counter;
        charList = charList->nextChar;
    }
    return charList->letter;
}

void addChar(charNode *&firstNode, char input) {
    charNode *newnode = new charNode;
    newnode->letter = input;
    newnode->nextChar = nullptr;

    if (firstNode == nullptr) {
        firstNode = newnode;
    } else {
        charNode *last = firstNode;
        while (last->nextChar != nullptr) {
            last = last->nextChar;
        }
        last->nextChar = newnode;
    }
}

void append(charNode *&firstNode, char input) {
    addChar(firstNode, input);
}

//function ripped from https://stackoverflow.com/questions/4984071/how-do-you-copy-a-linked-list-into-another-list
charNode *Clone(charNode *list) {
    if (list == NULL) return NULL;

    charNode *result = new charNode;
    result->letter = list->letter;
    result->nextChar = Clone(list->nextChar);
    return result;
}

void concatenate(charNode *&s1, charNode *s2) {
    charNode *s1Current = s1;
    charNode *s2Current = s2;
    while (s1Current->nextChar != nullptr) {
        s1Current = s1Current->nextChar;
    }
    s1Current->nextChar = Clone(s2Current);
}

void displayString(charNode *charList) {
    charNode *traverse = charList;
    while (traverse != nullptr) {
        cout << traverse->letter;
        traverse = traverse->nextChar;
    }
    cout << "\n";
}

void removeChars(charNode *&head, int start, int len) {
    charNode *current = head;
    charNode *prev = nullptr;

    int positionCounter = 0;
    while (current != nullptr && positionCounter != start) {
        prev = current;
        ++positionCounter;
        current = current->nextChar;
    }

    int eliminationCounter = 0;
    while (current != nullptr && eliminationCounter != len) {
        charNode * temp = current;
        current = current->nextChar;
        ++eliminationCounter;
        delete temp;
    }
    prev->nextChar = current;

}

int main() {

    charNode *head = nullptr;
    addChar(head, 't');
    addChar(head, 'e');
    addChar(head, 's');
    addChar(head, 't');
    displayString(head);

    //cout << characterAt(head, 3);
    //append(head, 'l');
    //displayString(head);

    charNode *s2 = nullptr;
    addChar(s2, 'b');
    addChar(s2, 'e');
    addChar(s2, 'd');
    concatenate(head, s2);
    removeChars(head, 1, 4);

    displayString(head);
    return 0;
}

