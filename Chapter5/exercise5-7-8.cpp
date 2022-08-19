#include <iostream>

using namespace std;


class studentCollection {
public:
    studentCollection();

    void addRecord(int id, float grade);

    float averageRecord();

    void displayList();

    studentCollection RecordsWithinRange(float low, float high);


private:
    struct listNode {
        int studentNum;
        float grade;
        listNode *next;
    };
    //typedef listNode *studentList;
    listNode *_head;
};


void studentCollection::addRecord(int id, float grade) {
    listNode *start = _head;
    listNode *newNode = new listNode;
    newNode->studentNum = id;
    newNode->grade = grade;
    newNode->next = start;
    _head = newNode;
}

studentCollection::studentCollection() {
    _head = NULL;
}

float studentCollection::averageRecord() {
    int count = 0;
    float sum = 0;
    listNode *loopPtr = _head;
    while (loopPtr != NULL) {
        sum += loopPtr->grade;
        ++count;
        loopPtr = loopPtr->next;
    }
    return sum / count;
}

void studentCollection::displayList() {
    listNode *currentNode = _head;
    while (currentNode != NULL) {
        cout << "Student ID" << " " << currentNode->studentNum << " " << ", grade" << " " << currentNode->grade << endl;
        currentNode = currentNode->next;
    }
}

studentCollection studentCollection::RecordsWithinRange(float low, float high) {
    studentCollection newRec = studentCollection();
    listNode *tmp = _head;
    while (tmp != NULL) {
        if(tmp->grade >= low && tmp->grade <= high) newRec.addRecord(tmp->studentNum, tmp->grade);
        tmp = tmp->next;
    }
    return newRec;
}


int main() {
    studentCollection sc = studentCollection();
    sc.addRecord(457912, 88);
    sc.addRecord(477821, 72);
    sc.addRecord(434451, 55);
    sc.addRecord(469912, 66);
    sc.addRecord(483111, 75);
    sc.displayList();
    cout << "STUDENT AVERAGE" << " " << sc.averageRecord();

    studentCollection scR = sc.RecordsWithinRange(55, 72);
    scR.displayList();

}

