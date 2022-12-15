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

void clearConsoleLines(int deleteRows) {
    for (int j = 0; j < deleteRows; j++) {
        cout << "\x1b[A"; //moves up the needed number of lines. 7 (all 3 rows) -> 5 (exclude top row) -> 3 (only bottom row)
    }
    cout << "\x1b[J"; //removes all lines below the cursor
}

//temporary to check actual grid
void writeCorrectGrid(char grid[3][3]) {
    cout << endl << endl << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}