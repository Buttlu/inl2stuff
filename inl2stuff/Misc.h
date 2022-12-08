#include <iostream>
#include <chrono>
#include <thread>
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
//function for delay
void delay(int delayTime) { this_thread::sleep_for(chrono::milliseconds(delayTime)); }