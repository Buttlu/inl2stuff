#include <ctime>
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int winMultiplier(int wins);
char getRandomCharacter();
void writeGrid(int rows, int columns, char grid[3][3]); //want 'rows' and 'columns' instead of fixed num
int countWinningRows(int rows, int columns, char grid[3][3]); //read pointer array works, but idk hot to do that. This will do 

int main() {
    int const rows = 3, columns = 3;
    char grid[rows][columns];
    int totalWins = 0;
    int moneyWon, bet;

    bet = 10;
    cout << "\nYou're betting " << bet << " kr" << endl << endl;
    //maybe add a "press any key to start"
    system("pause");

    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            grid[i][j] = getRandomCharacter();
    }

    writeGrid(rows, columns, grid);

    /*<testing>
    grid[0][0] = 'X';
    grid[0][1] = 'X';
    grid[0][2] = 'X';
    grid[1][0] = 'X';
    grid[1][1] = 'X';
    grid[1][2] = 'X';
    grid[2][0] = 'X';
    grid[2][1] = 'X';
    grid[2][2] = 'X';
    </testing>*/
  
    totalWins = countWinningRows(rows, columns, grid);
    cout << "\nTotal winning rows: " << totalWins << endl;
    moneyWon = bet * winMultiplier(totalWins);
    if (moneyWon != bet) cout << "You got " << moneyWon << " kr"; //only writes if won
    
    cout << "end" << endl; //temporary to see if end is reached
}

//<winning olutions>
//#1: 
/*
make check for every posibility. Not coding that here
*/
//-----------------------------------------------------------------------------------
//#2:
/*
  // only counting top row, why? Because threeInARow never reset to true
//checks rows from top to bottom
  bool threeInARow = true;
  for (int i = 0; i < rows; i++) { // goes down
    threeInARow = true;
    for (int j = 0; j < columns - 1; j++) { // goes right
      if (grid[i][j] != grid[i][j + 1])
        threeInARow = false;
    }
    if (threeInARow)
      totalWins++;
  }

  // for columns
//checks columns from left to right
  for (int i = 0; i < columns; i++) { // goes right
    threeInARow = true;
    for (int j = 0; j < rows - 1; j++) { // goes down
      if (grid[j][i] != grid[j + 1][i])
        threeInARow = false;
    }
    if (threeInARow)
      totalWins++;
  }

  // field has to be square for this to work. Guess u can't really do diagonal
  // if not sqaure
  // for \-diagonal
//checks diagonal from top-left (0,0) to bottom-right (2,2)
  threeInARow = true;
  for (int i = 0; i < rows - 1; i++) {
    if (grid[i][i] != grid[i + 1][i + 1])
      threeInARow = false;
  }
  if (threeInARow)
    totalWins++;

  // for /-diagonal
//checks diagonal from bottom-left (0,2) to top-right (2,0)
  threeInARow = true;
  for (int i = 1; i < rows; i++) {
    if (grid[0][rows - 1] != grid[i][rows - 1 - i])
      threeInARow = false;
  }
  if (threeInARow)
    totalWins++;

*/
//-----------------------------------------------------------------------------------
//#3:
/*

*/
//</winning olutions>

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

void writeGrid(int rows, int columns, char grid[3][3]) {
    for (int i = 0; i < rows; i++) {
        cout << "--------------" << endl; 
        this_thread::sleep_for(chrono::seconds(1));
        for (int j = 0; j < columns; j++) {
            cout << "| ";
            cout << grid[i][j] << " ";
        }
        cout << " |" << endl;
    }
    cout << "--------------" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
}

// for counting winnings
int countWinningRows(int const rows, int const columns, char grid[3][3]) {
    int totalWins = 0;

    // only counting top row, why? Because threeInARow never reset to true
    bool threeInARow = true;
    for (int i = 0; i < rows; i++) { // goes down
        threeInARow = true;
        for (int j = 0; j < columns - 1; j++) { // goes right
            if (grid[i][j] != grid[i][j + 1])
                threeInARow = false;
        }
        if (threeInARow)
            totalWins++;
    }

    // for columns
    for (int i = 0; i < columns; i++) { // goes right
        threeInARow = true;
        for (int j = 0; j < rows - 1; j++) { // goes down
            if (grid[j][i] != grid[j + 1][i])
                threeInARow = false;
        }
        if (threeInARow)
            totalWins++;
    }

    // field has to be square for this to work. Guess u can't really do diagonal
    // if not sqaure
    // for \-diagonal
    threeInARow = true;
    for (int i = 0; i < rows - 1; i++) {
        if (grid[i][i] != grid[i + 1][i + 1])
            threeInARow = false;
    }
    if (threeInARow)
        totalWins++;

    // for /-diagonal
    threeInARow = true;
    for (int i = 1; i < rows; i++) {
        if (grid[0][rows - 1] != grid[i][rows - 1 - i])
            threeInARow = false;
    }
    if (threeInARow)
        totalWins++;

    return totalWins;
}