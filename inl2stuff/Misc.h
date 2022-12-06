#include <iostream>
using namespace std;
string stringToLower(string str) {
    string emptyStr("");
    char tempChar;
    for (int i = 0; i < str.string::length(); i++) {
        tempChar = (char)tolower(str[i]);
        emptyStr.append(1, tempChar);
    }
    return emptyStr;
}

int min(int num1, int num2) { return num1 < num2 ? num1 : num2; }
int max(int num1, int num2) { return num1 > num2 ? num1 : num2; }

