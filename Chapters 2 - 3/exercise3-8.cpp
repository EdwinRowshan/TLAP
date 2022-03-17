#include <iostream>
using namespace std;
#define endl "\n";

/*
*   Rewrite the code that finds the agent with the best monthly sales average, compensating for -1 (agents before / after hiring months)
*/

int compareTo(const void *voidA, const void *voidB)
{
    int *intA = (int *)voidA;
    int *intB = (int *)voidB;
    return *intA - *intB;
}

void printAgent(int arr[], int ARRAY_SIZE)
{
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

double maximum(double a, double b, double c)
{
    double max = (a < b) ? b : a;
    return ((max < c) ? c : max);
}

double newMedian(int arr[], const int NUM_MONTHS)
{
    int start = 0;
    int end = NUM_MONTHS - 1;

    while (arr[start] == -1 && start < NUM_MONTHS)
    {
        ++start;
    }
    /*  [-1, -1, -1, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434]
    *     0   1   2  3    4    5    6    7    8     9    10     11
    *     start = 3; 
    */
    while (arr[end] == -1 && end > 0)
    {
        --end;
    }
    /*  [-1, -1, -1, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434]
    *     0   1   2  3    4    5    6    7    8     9    10     11
    *   end = 8;
    */
   
   //true sales = 6; middle = 6 
   //arr[6-1] + arr[6] ) /2 

    const int true_sales = (end + 1) - start;
    const int middle = (true_sales / 2) + start;

    if (true_sales % 2 != 0)
    {
        return arr[middle];
    }
    else
    {
        return (arr[middle - 1] + arr[middle]) / 2.0;
    }
}

int main(void)
{
    const int NUM_AGENTS = 3;
    const int NUM_MONTHS = 12;
    int sales[NUM_AGENTS][NUM_MONTHS] = {
        {-1, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, -1, -1},
        {-1, -1, -1, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}};

    for (int i = 0; i < NUM_AGENTS; ++i)
    {
        qsort(sales[i], 12, sizeof(int), compareTo);
    }
    cout << endl;
    cout << "MEDIAN OF ALL AGENTS" << endl;

    for (int i = 0; i < NUM_AGENTS; ++i)
    {
        cout << "AGENT" << ' ' << i + 1 << ":" << ' ';
        cout << newMedian(sales[i], NUM_MONTHS) << endl;
    }
    cout << endl;
    cout << "HIGHEST MEDIAN"
         << ":" << ' ' << maximum(newMedian(sales[0], NUM_MONTHS), newMedian(sales[1], NUM_MONTHS), newMedian(sales[2], NUM_MONTHS));

    return 0;
}