#include <iostream>
using namespace std;
#define endl "\n";

//Use qsort() to sort an array of student structs based on grade, then studentID.

typedef struct student
{
    int grade;
    int studentID;
    string name;
} student;

//COMPARE FUNCTION RETURN STATEMENTS CAN BE SWITCHED FOR DESCENDING OR ASCENDING

int compareGrades(const void *voidA, const void *voidB)
{
    const student *studentA = (const student *)voidA;
    const student *studentB = (const student *)voidB;

    if (studentA->grade < studentB->grade)
        return -1;
    else if (studentA->grade > studentB->grade)
        return 1; 
    else
        return 0;
}

int compareID(const void *voidA, const void *voidB)
{
    const student *studentA = (const student *)voidA;
    const student *studentB = (const student *)voidB;

    if (studentA->studentID < studentB->studentID)
        return -1;
    else if (studentA->studentID > studentB->studentID)
        return 1;
    else
        return 0;
}

int main(void)
{
    const int ARRAY_SIZE = 5;
    student studentArray[ARRAY_SIZE] =
        {
            {85, 457912, "Edwin"},
            {67, 462389, "Alex"},
            {100, 449822, "Robert"},
            {50, 431578, "Claudius"},
            {98, 448751, "Felipe"}};

    cout << "GRADES BEFORE SORTING" << endl;
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        cout << studentArray[i].name << ":" << ' ';
        cout << studentArray[i].grade << endl;
    }
    cout << endl;
    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareGrades);

    cout << "GRADES AFTER SORTING" << endl;
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        cout << studentArray[i].name << ":" << ' ';
        cout << studentArray[i].grade << endl;
    }
    cout << endl;
    cout << "ID BEFORE SORTING" << endl;
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        cout << studentArray[i].name << ":" << ' ';
        cout << studentArray[i].studentID << endl;
    }
    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareID);
    cout << "ID AFTER SORTING" << endl;
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        cout << studentArray[i].name << ":" << ' ';
        cout << studentArray[i].studentID << endl;
    }
    return 0;
}