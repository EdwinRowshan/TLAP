#include <iostream>

using namespace std;


/*
    4-4. Change the implementation of our strings such that location[0] in the array
    stores the size of the array (and therefore location[1] stores the first actual
    character in the string), rather than using a null-character terminator.

    Implement each of the three functions, append, concatenate, and charactertAt,
    taking advantage of the stored size information whenever possible.

    Because we’ll no longer be using the null-termination convention expected by the
    standard output stream, you’ll need to write your own output function that
    loops through its string parameter, displaying the characters.

 */

typedef char *arrayString;


char numlength(arrayString s) {
    return s[0];
}

char lastChar(arrayString s) {
    int i = 0;
    while (i != numlength(s)) {
        ++i;
    }
    cout << "Out of bounds, displaying last char: \n";
    return s[i];
}

void displayString(arrayString s) {
    for (int i = 1; i < numlength(s); ++i) {
        cout << s[i];
    }
}

char characterAt(arrayString s, int position) {
    if (position == 0) return s[1];
    if (position > 0 && position < numlength(s)) {
        return s[position];
    } else {
        return lastChar(s);
    }
}

void append(arrayString &s, char c) {
    arrayString newString = new char[numlength(s) + 1];
    newString[0] = numlength(s) + 1;
    for (int i = 1; i < numlength(newString); ++i) {
        newString[i] = s[i];
    }
    newString[numlength(s) + 1] = c;
    delete[] s;
    s = newString;
}


void concatenate(arrayString &s1, arrayString s2) {
    arrayString newString = new char[numlength(s1) + numlength(s2)];
    newString[0] = numlength(s1) + numlength(s2);

    for (int i = 1; i <= numlength(s1); ++i) {
        newString[i] = s1[i];
    }
    for (int i = 1; i <= numlength(s2); ++i) {
        newString[i + numlength(s1)] = s2[i];
    }

    delete[] s1;
    s1 = newString;
}

void testcharAt() {
    arrayString a = new char[5];
    a[0] = 4;
    a[1] = 't';
    a[2] = 'e';
    a[3] = 's';
    a[4] = 't';
    cout << characterAt(a, 2);
}

void testAppend() {
    arrayString a = new char[5];
    a[0] = 4;
    a[1] = 't';
    a[2] = 'e';
    a[3] = 's';
    a[4] = 't';
    char c = 'c';
    append(a, c);
    cout << a;
}


void concatenateTester() {
    arrayString a = new char[5];
    a[0] = 4;
    a[1] = 't';
    a[2] = 'e';
    a[3] = 's';
    a[4] = 't';
    arrayString b = new char[4];
    b[0] = 3;
    b[1] = 'b';
    b[2] = 'e';
    b[3] = 'd';
    concatenate(a, b);
    cout << a;
}

int main() {
    testcharAt();
    testAppend();
    concatenateTester();
    return 0;
}

