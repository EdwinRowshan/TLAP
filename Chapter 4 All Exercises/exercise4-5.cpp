#include <iostream>

using namespace std;

typedef struct listNode {
    int studentNum;
    int grade;
    listNode *next;
} listNode;

/*
    4-5
    Write a function removeRecord that takes a pointer to a studentCollection and a
    student number and that removes the record with that student number from
    the collection.
 */


void removeRecord(listNode *&sc, int targetNum) {
    listNode *prevNode = nullptr;
    listNode *currentNode = sc;

    if (currentNode->studentNum == targetNum) {
        sc = currentNode->next;
        delete currentNode;
    } else {
        while (currentNode != nullptr && currentNode->studentNum != targetNum) {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
        prevNode->next = currentNode->next;
        delete currentNode;
    }
}


void addRecord(listNode *&sc, int id, int grade) {
    listNode *newStudent = new listNode;
    newStudent->studentNum = id;
    newStudent->grade = grade;
    newStudent->next = sc;
    sc = newStudent;
}


void displayList(listNode *sc) {
    listNode *temp = sc;
    while (temp != nullptr) {
        cout << "STUDENT ID: " << temp->studentNum << "\n";
        cout << "GRADE: " << temp->grade << "\n";
        cout << "   ^\n"
                "   |\n"
                "   |\n";
        temp = temp->next;
    }
}

void flushList(listNode *&sc) {
    listNode *current = sc;
    sc = nullptr;
    while (sc) {
        listNode *next = current->next;
        delete current;
        current = next;
    }
}

int main() {

    listNode *head = nullptr;
    addRecord(head, 457912, 88);
    addRecord(head, 444578, 67);
    addRecord(head, 478892, 72);
    addRecord(head, 411234, 55);


    cout << "STUDENT REMOVED \n";
    removeRecord(head, 457912);

    displayList(head);
    flushList(head);

    return 0;
}

