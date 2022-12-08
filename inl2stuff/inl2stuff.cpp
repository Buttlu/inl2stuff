#include <ctime>
#include <iostream>
#include "Misc.h"
using namespace std;

int winMultiplier(int wins);
char getRandomCharacter();
void writeGrid(char grid[3][3]); 
int countWinning3(char grid[3][3]);

int main() {
    char grid[3][3];
    int totalWins = 0;
    int moneyWon, bet;

    bet = 10;
    cout << "\nYou're betting " << bet << " kr" << endl << endl;
    system("pause");
    srand(time(0));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            grid[i][j] = getRandomCharacter();
    }

    /*//<testing>
    grid[0][0] = 'X';
    grid[0][1] = 'X';
    grid[0][2] = 'X';
    grid[1][0] = 'X';
    grid[1][1] = 'X';
    grid[1][2] = 'X';
    grid[2][0] = 'X';
    grid[2][1] = 'X';
    grid[2][2] = 'X';
    *///</testing>
    writeGrid(grid);
  
    totalWins = countWinning3(grid);
    cout << "\nTotal winning rows: " << totalWins << endl;
    moneyWon = bet * winMultiplier(totalWins);
    if (totalWins > 0) cout << "You got " << moneyWon << " kr" << endl; //only writes if won
}

int winMultiplier(int wins) {
    int winMult;
    switch (wins) {
    case 0:
        cout << "You didn't win this time." << endl;
        return 1;            
    case 1:
        winMult = 2;
        break;
    case 2:
        winMult = 3;
        break;
    case 3:
        winMult = 4;
        break;
    case 4:
        winMult = 5;
        break;
    case 5:
        winMult = 7;
        break;
    case 8:
        winMult = 10;
        break;
    default:
        winMult = 0;
        break;
    }
    cout << "You got a win-multiplier of " << winMult << "!" << endl;
    return winMult;
}

char getRandomCharacter() {
    char symbols[3] = { 'A', 'O', 'X' };
    return symbols[rand() % sizeof(symbols)]; 
}

//version for writing entire grid (3x3) and then the real grid 1 row at a time from top to bottom.
void writeGrid(char grid[3][3]) {
    char symbols[3] = { 'A', 'O', 'X' };
    int deleteRows = 7, writeRandomRows = 0, actualRow = 0,  randomRows = 69; //randomRows has to be divisible by 3
    bool done = false;

    for (int i = 0; i < randomRows; i++) {
        if (deleteRows == 1) break; //cursor jumps up and down a little bit and delays the result w/o this
        //writes out the random grid. The random characters don't change the actual grid so they just get
        //overwritten by the actual grid when their time comes
        cout << "-------------" << endl;
        for (int j = writeRandomRows; j < 3; j++) {
            cout << "| " << symbols[rand() % 3] << " | " << symbols[rand() % 3] << " | " << symbols[rand() % 3] << " |" << endl;
            cout << "-------------" << endl;
        }
        
        //delay for extra suspencion and so the player sees what happens
        delay(50);
        for (int j = 0; j < deleteRows; j++) {
            cout << "\x1b[A"; //moves up the needed number of lines
        }
        cout << "\x1b[J"; //removes all lines below the cursor

        //writes out the actual rows roughly whenever a third of the main loop is done 
        //doesn't enter here to write 3rd actual row. Last dash-row can be fixed other way
        if ((i - 2) % (randomRows / 3) == 0 && i > 1) {
            cout << "-------------" << endl;
            cout << "| " << grid[actualRow][0] << " | " << grid[actualRow][1] << " | " << grid[actualRow][2] << " |" << endl;
            //changes values as to not overwrite the actual grid lines
            actualRow++;
            writeRandomRows++;
            deleteRows -= 2;
        }
    }
    cout << "-------------" << endl;
}

/*//works but want to try to make a version where entire grid randomizes
//randomizes and writes 1 row at a time
void writeGrid(char grid[3][3]) {
    char symbols[3] = { 'A', 'O', 'X' };
    for (int i = 0; i < 3; i++) {
        cout << "-------------" << endl;
        srand(time(0));
        for (int j = 0; j < 20; j++) {
            //writes out random row
            cout << "| " << symbols[rand() % 3] << " | " << symbols[rand() % 3] << " | " << symbols[rand() % 3] << " |";
            this_thread::sleep_for(chrono::milliseconds(50));
            cout << "\x1b[2K\r"; //deletes previous line
        }
        //writes out actual line
        for (int c = 0; c < 3; c++) {
            cout << "| ";
            cout << grid[i][c] << " ";
        }
        cout << "|" << endl;
    }
    cout << "-------------" << endl;
}*/

// for counting winnings
int countWinning3(char grid[3][3]) {
    int totalWins = 0;

    // only counting top row, why? Because threeInARow never reset to true
    //checks rows from top to bottom
    bool threeInARow = true;
    for (int i = 0; i < 3; i++) { // goes down
        threeInARow = true;
        for (int j = 0; j < 3 - 1; j++) { // goes right
            if (grid[i][j] != grid[i][j + 1])
                threeInARow = false;
        }
        if (threeInARow)
            totalWins++;
    }

    // for columns
    //checks columns from left to right
    for (int i = 0; i < 3; i++) { // goes right
        threeInARow = true;
        for (int j = 0; j < 3 - 1; j++) { // goes down
            if (grid[j][i] != grid[j + 1][i])
                threeInARow = false;
        }
        if (threeInARow)
            totalWins++;
    }

    // for \-diagonal
    //checks diagonal from top-left (0,0) to bottom-right (2,2)
    threeInARow = true;
    for (int i = 0; i < 3 - 1; i++) {
        if (grid[i][i] != grid[i + 1][i + 1])
            threeInARow = false;
    }
    if (threeInARow)
        totalWins++;

    // for /-diagonal
    //checks diagonal from bottom-left (0,2) to top-right (2,0)
    threeInARow = true;
    for (int i = 1; i < 3; i++) {
        if (grid[0][3 - 1] != grid[i][3 - 1 - i])
            threeInARow = false;
    }
    if (threeInARow)
        totalWins++;

    return totalWins;
}