#include <iostream>
#define endl "\n";
using namespace std;

/*
2 8 
4 6
6 4
8 0 <- spaces
-
8
6
4
2
*/

int main(void)
{

    /*for(int i = 1; i <= 4; i++) {
        cout << 2 * i << endl;
    }

    for(int i = 1; i <= 4; i++) {
        cout << 10 - (2 * i) << endl;
    }*/

    /*for (int i = 0; i < 3; i++)
    {
        cout << 8 - 2 * i << endl;
    }*/

    for (int topHalf = 1; topHalf <= 4; topHalf++)
    {
        for (int spaceOne = 0; spaceOne < topHalf - 1; spaceOne++)
        {
            cout << ' ';
        }
        for (int i = 1; i <= topHalf; i++)
        {
            cout << "#";
        } // 14 space across - occupied space
        for (int spaceTwo = 0; spaceTwo < 14 - 2 * (topHalf + topHalf - 1); spaceTwo++)
        {
            cout << ' ';
        }
        for (int i = 1; i <= topHalf; i++)
        {
            cout << "#";
        }
        cout << endl;
    }
    for (int bottomHalf = 1; bottomHalf <= 4; bottomHalf++)
    {
        for (int spaceThree = 0; spaceThree < 4 - bottomHalf; spaceThree++)
        {
            cout << ' ';
        }
        for (int i = 1; i <= 5 - bottomHalf; i++)
        {
            cout << '#';
        }// 14 - occupied
        for (int spaceThree = 0; spaceThree < 14 - 2 * ((5 - bottomHalf) + 4 - bottomHalf) ; spaceThree++)
        {
            cout << ' ';
        }
        for (int i = 1; i <= 5 - bottomHalf; i++)
        {
            cout << '#';
        }

        cout << endl;
    }

    return 0;
}