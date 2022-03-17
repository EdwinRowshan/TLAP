#include <iostream>
#define endl "\n";
using namespace std;

int main(void)
{

    for (int start = 0; start < 4; start++)
    {
        for (int i = 0; i < start; i++)
        {
            cout << ' ';
        }

        for (int i = 0; i < 8 - (2 * start); i++)
        {
            cout << "#";
        }
        cout << endl;
    }

    return 0;
}