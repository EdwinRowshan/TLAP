#include <iostream>

using namespace std;

/*
    4-2
    For our dynamically allocated strings, create a function substring that takes
    three parameters: an arrayString, a starting position integer, and an integer
    length of characters.

    The function returns a pointer to a new dynamically
    allocated string array.

    This string array contains the characters in the original
    string, starting at the specified position for the specified length.

    The original string is unaffected by the operation.
    So if the original string was abcdefg, the position was 3, and the length was 4,
    then the new string would contain cdef.

    --------------------------------------------------------------------------------------------------------------------
    4-3
    For our dynamically allocated strings, create a function replaceString that takes
    three parameters, each of type arrayString: source, target, and replaceText.

    The function replaces every occurrence of target in source with replaceText.

    For example, if source points to an array containing abcdabee, target points to
    ab, and replaceText points to xyz, then when the function ends, source should
    point to an array containing xyzcdxyzee.

 */

typedef char *arrayString;

arrayString substring(arrayString as, int start, int len) {
    arrayString newString = new char[len + 1];

    int track = 0;
    for (int i = start - 1; i < start + len; ++i) {
        newString[track] = as[i];
        ++track;
    }
    newString[len + 1] = 0;
    delete[] as;
    return newString;
}

void substringTester() {
    arrayString test = new char[7];
    test[0] = 'a';
    test[1] = 'b';
    test[2] = 'c';
    test[3] = 'd';
    test[4] = 'e';
    test[5] = 'f';
    test[6] = 'g';
    test[7] = 0;
    cout << substring(test, 3, 4);
}

int length(arrayString as) {
    int count = 0;
    while (as[count] != 0) {
        ++count;
    }
    return count;
}

void replaceString(arrayString &source, arrayString target, arrayString replaceText) {

    int sourceLength = length(source);
    int targetLength = length(target);
    int replaceTextLength = length(replaceText);
    int targetPresent = 0;

    for (int i = 0; i < sourceLength; ++i) {
        if (source[i] == target[0]) {
            int count = 0;
            for (int k = 0; k < targetLength; ++k) {
                if (target[k] == source[i + k]) {
                    ++count;
                }
            }
            if (count == targetLength) {
                ++targetPresent;
            }
        }
    }

    int newStringLength = sourceLength + (replaceTextLength - targetLength) * targetPresent + 1;
    arrayString newString = new char[newStringLength];
    newString[newStringLength] = 0;

    int j = 0;
    int i = 0;

    while (j < newStringLength) {
        if (source[j] == target[0]) {
            bool targetAcquired = false;
            for (int k = 0; k < targetLength; ++k) {
                if (target[k] == source[j + k]) {
                    targetAcquired = true;
                } else {
                    targetAcquired = false;
                    break;
                }
            }
            if (targetAcquired) {
                for (int k = 0; k < replaceTextLength; ++k) {
                    newString[i] = replaceText[k];
                    ++i;
                }
                j += targetLength;
            }
            if (!targetAcquired) {
                newString[i] = source[j];
                ++j;
                ++i;
            }
        } else {
            newString[i] = source[j];
            ++j;
            ++i;
        }
    }

    delete[] source;
    source = newString;
}


void replaceStringTester() {
    arrayString test = new char[8];
    test[0] = 'a';
    test[1] = 'b';
    test[2] = 'c';
    test[3] = 'd';
    test[4] = 'a';
    test[5] = 'b';
    test[6] = 'e';
    test[7] = 'e';
    test[8] = 0;
    arrayString target = new char[3];
    target[0] = 'a';
    target[1] = 'b';
    target[3] = 0;
    arrayString replaceText = new char[4];
    replaceText[0] = 'x';
    replaceText[1] = 'y';
    replaceText[2] = 'z';
    replaceText[3] = 0;
    replaceString(test, target, replaceText);
    cout << test;
}

int main() {
    // substringTester();
    replaceStringTester();
    return 0;
}


