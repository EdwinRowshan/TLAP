#include <iostream>

using namespace std;

/*
    4-9
    Imagine a linked list where instead of the node storing a character, the node
    stores a digit: an int in the range 0–9.

    We could represent positive numbers
    of any size using such a linked list; the number 149, for example, would be a
    linked list in which the first node stores a 1, the second a 4, and the third and
    last a 9.

    Write a function intToList that takes an integer value and produces a
    linked list of this sort. Hint: You may find it easier to build the linked list
    backward, so if the value were 149, you would create the 9 node first.

    4-10
    For the digit list of the previous exercise, write a function that takes two such
    lists and produces a new list representing their sum.
 */

typedef struct intList {
    int digit;
    intList *next;
} intList;


intList *createList(int n) {
    intList *head = nullptr;

    while (n != 0) {
        intList *temp = head;
        head = new intList;
        head->digit = n % 10;
        head->next = temp;
        n /= 10;
    }
    return head;
}

int trueInt(intList *head) {
    int num = 0;
    while (head != nullptr) {
        num = head->digit + num * 10;
        head = head->next;
    }
    return num;
}

intList *sum(intList *l1, intList *l2) {
    return createList(trueInt(l1) + trueInt(l2));
}

void displayDigits(intList *head) {
    while (head != nullptr) {
        cout << head->digit;
        head = head->next;
    }
    cout << endl;
}

int main() {

    intList *l1 = createList(149);
    intList *l2 = createList(84);
    //displayDigits(l1);
    //displayDigits(l2);
    displayDigits(sum(l1, l2));

    return 0;
}
