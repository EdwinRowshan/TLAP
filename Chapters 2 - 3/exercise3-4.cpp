#include <iostream>
using namespace std;
#define endl "\n";

/*
*   Substitution cipher problem
*   All messages are made of uppercase, lowercase letters and punctuation.
*   The original message is called the 'plaintext'
*   The cipher is created by substituting each letter with another letter.
*   Hard code a const array of 26 char elements for the cipher.
*   Read a plaintext message and output ciphertext.
*   
*   Then we decipher the encoded message again to check it's validity.
*/

//B T N M X W E V L K P Q C R J Y Z D A F H I G S U O from https://www.dcode.fr/deranged-alphabet-generator

const int ARRAY_SIZE = 26; //10
char reverseCipher[ARRAY_SIZE];

const string decodingCipher = "BTNMXWEVLKPQCRJYZDAFHIGSUO";

string encodeText(string plaintext, const char ciph[])
{
    for (int i = 0; i <= plaintext.length(); ++i)
    {
        plaintext[i] = toupper(plaintext[i]);
        if ((plaintext[i] >= ('A')) && (plaintext[i] <= ('Z')))
            plaintext[i] = ciph[plaintext[i] - ('A')];
    }
    return plaintext;
}

string decodeText(string encodedText, const char ciph[])
{
    for (int i = 0; i < encodedText.length(); ++i)
    {
        encodedText[i] = 'A' + reverseCipher[encodedText[i] - 'A'];
    }
    return encodedText;
}

int main(void)
{
    const char cipher[ARRAY_SIZE] = {'B', 'T', 'N', 'M', 'X', 'W', 'E', 'V', 'L', 'K', 'P', 'Q', 'C', 'R', 'J', 'Y', 'Z', 'D', 'A', 'F', 'H', 'I', 'G', 'S', 'U', 'O'};

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        reverseCipher[i] = decodingCipher.find('A' + i);
    }

    cout << "Enter plaintext string" << endl;
    string plaintext;
    getline(cin, plaintext);
    string encoded = encodeText(plaintext, cipher);
    cout << "The encoded text is:" << ' ' << encoded << endl;

    cout << "Please enter the encoded text to verify if it is correct or not" << endl;
    string encodedText;
    getline(cin, encodedText);
    string decoded = decodeText(encodedText, cipher);
    cout << "The decoded text is" << ' ' << decoded << endl;

    return 0;
}