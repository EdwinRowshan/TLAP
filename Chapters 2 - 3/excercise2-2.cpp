#include <iostream>
#define endl "\n";
using namespace std;

int main(void)
{
    for (int start = 1; start <= 4; start++)
    {
        for (int space = 0; space < 4 - start; space++)
        {
            cout << ' ';
        }
        for (int first = 1; first <= 2 * start; first++)
        {
            cout << "#";
        }
        cout << endl;
    }

    for (int startTwo = 1; startTwo <= 4; startTwo++)
    {
        for (int spaceTwo = 0; spaceTwo < startTwo - 1; spaceTwo++)
        {
            cout << ' ';
        }
        for (int second = 1; second <= 10 - (2 * startTwo); second++)
        {
            cout << "#";
        }
        cout << endl;
    }

    return 0;
}