#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

/// @brief Draws the provided tic-tac-toe board to the screen
//  @param board is the tic-tac-toe board that should be drawn
void drawBoard(const vector < char >&gameBoard) {
    
    for (int i = 0; i < 9; i += 3) {
        cout << "  " << gameBoard.at(i) << "  |  " << gameBoard.at(i + 1) << "  |  "
            << gameBoard.at(i + 2) << "  " << endl;
        if (i < 6) {
            cout << "-----|-----|-----" << endl;
        }
    }
    cout << endl;

    return;
}



/// @brief Fills vector with characters starting at lower case a.
///
///     If the vector is size 3 then it will have characters a to c.
///     If the vector is size 5 then it will have characters a to e.
///     If the vector is size 26 then it will have characters a to z.
///
/// @param v the vector to initialize
/// @pre-condition the vector size will never be over 26
void initVector(vector <char> &v) {
    int i;
    if (v.size() <= 26) {
        for (i = 0; i < v.size(); ++i) {
            v.at(i) = 'a' + i;
        } 
    }
    return;
}


/// @brief Converts a character representing a cell to associated vector index
/// @param the position to be converted to a vector index
/// @return the integer index in the vector, should be 0 to (vector size - 1)
int convertPosition(char boardPosition) {
    int i;
    int size = 9;
    vector<char> v(size);
    initVector(v);
    for (i = 0; i < size; ++i) {
        if (v.at(i) == boardPosition) {
            return i;
        }
    }
}


/// @brief Predicate function to determine if a spot in board is available.
/// @param board the current tic-tac-toe board 
/// @param position is an index into vector to check if available
/// @return true if position's state is available (not marked) AND is in bounds
bool validPlacement(const vector<char>  &gameBoard, int positionIndex) { //no errors
    int i;
    if (positionIndex < gameBoard.size()) {
        if (gameBoard.at(positionIndex) != 'X' && gameBoard.at(positionIndex) != 'O') {
            return true;
        }
        } else {
            return false;
        }
    }

/// @brief Acquires a play from the user as to where to put her mark
///
///     Utilizes convertPosition and validPlacement functions to convert the
///     user input and then determine if the converted input is a valid play.
///
/// @param board the current tic-tac-toe board 
/// @return an integer index in board vector of a chosen available board spot
int getPlay(const vector<char> &gameBoard) { 
    int temp;
    
    char boardPosition = ' ';

    do {
    cout << "Please choose a position: " << endl;
    cin >> boardPosition;
    temp = convertPosition(boardPosition);
    } while (!validPlacement(gameBoard, temp));
        return temp;
    }


/// @brief Predicate function to determine if the game has been won
///
///     Winning conditions in tic-tac-toe require three marks from same 
///     player in a single row, column or diagonal.
///
/// @param board the current tic-tac-toe board 
/// @return true if the game has been won, false otherwise
bool gameWon(const vector<char> &gameBoard) { 
    int i;
    for (i = 0; i < 3; ++i) {
        if (gameBoard.at(i) == gameBoard.at(i + 3) && gameBoard.at(i) == gameBoard.at(i + 6)) { 
            return true;
        } else if (gameBoard.at(i * 3) == gameBoard.at(i * 3 + 1) && gameBoard.at(i * 3) == gameBoard.at(i * 3 + 2)) { 
            return true;    
        }
    }
    if (gameBoard.at(0) == gameBoard.at(4) && gameBoard.at(0) == gameBoard.at(8)) { //diagonals
    return true;
    } else if (gameBoard.at(2) == gameBoard.at(4) && gameBoard.at(6) == gameBoard.at(2)) {
        return true;
    }
    return false;
}


/// @brief Predicate function to determine if the board is full
/// @param board the current tic-tac-toe board 
/// @return true iff the board is full (no cell is available)
bool boardFull(const vector<char> &gameBoard) {
    int count = 0;
    int i;
    for (i = 0; i < gameBoard.size(); ++i) {
        if (gameBoard.at(i) == 'X') {
            ++count;
            //return false;
        }
        else if (gameBoard.at(i) == 'O') {
            ++count;
            //return false;
        }
    }
    if (count == 9) {
        return true;
    } else {
        return false;
    }
}
    


// Global constants for player representation
const int PLAYER1 = 0;
const int PLAYER2 = 1;

int main() {
    // Variables that you may find useful to utilize
    vector<char> gameBoard(9);
    int curPlay;
    int whosTurn = PLAYER1; // Player 1 always goes first and is 'X'
    int i;
    initVector(gameBoard); //fills board with characters a through i
    drawBoard(gameBoard);
    
    while (!boardFull(gameBoard) && !gameWon(gameBoard)) {
        curPlay = getPlay(gameBoard);
        if (whosTurn == PLAYER1) {
            gameBoard.at(curPlay) = 'X';
            whosTurn = PLAYER2;
        } else if (whosTurn == PLAYER2) {
            gameBoard.at(curPlay) = 'O';
            whosTurn = PLAYER1;
        }
        drawBoard(gameBoard);
        
    }
    if (whosTurn == PLAYER1 && gameWon(gameBoard)){
        cout << "Player 2 Wins!!" << endl;
    }
    else if (whosTurn == PLAYER2 && gameWon(gameBoard)){
        cout << "Player 1 Wins!!" << endl;
    }
    else {
        cout << "No one wins" << endl;
    }
 
    return 0;
    
    
    

    
}

