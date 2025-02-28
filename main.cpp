#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// ANSI-коды для цветов
#define ORANGE "\033[38;5;208m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

void drawBoard(char board[]) {
    cout << ORANGE << " " << BLUE << board[0] << ORANGE << " | " << BLUE << board[1] << ORANGE << " | " << BLUE << board[2] << ORANGE << " " << RESET << endl;
    cout << ORANGE << "-----------" << RESET << endl;
    cout << ORANGE << " " << BLUE << board[3] << ORANGE << " | " << BLUE << board[4] << ORANGE << " | " << BLUE << board[5] << ORANGE << " " << RESET << endl;
    cout << ORANGE << "-----------" << RESET << endl;
    cout << ORANGE << " " << BLUE << board[6] << ORANGE << " | " << BLUE << board[7] << ORANGE << " | " << BLUE << board[8] << ORANGE << " " << RESET << endl;
}

bool isWinner(char board[], char symbol) {
    const int winPatterns[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };
    for (const auto &pattern : winPatterns) {
        if (board[pattern[0]] == symbol && board[pattern[1]] == symbol && board[pattern[2]] == symbol) {
            return true;
        }
    }
    return false;
}

bool isBoardFull(char board[]) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') return false;
    }
    return true;
}

void computerMove(char board[], char computerSymbol, char playerSymbol) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            board[i] = computerSymbol;
            if (isWinner(board, computerSymbol)) return;
            board[i] = ' ';
        }
    }
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            board[i] = playerSymbol;
            if (isWinner(board, playerSymbol)) {
                board[i] = computerSymbol;
                return;
            }
            board[i] = ' ';
        }
    }
    do {
        int move = rand() % 9;
        if (board[move] == ' ') {
            board[move] = computerSymbol;
            break;
        }
    } while (true);
}

void playerMove(char board[], char playerSymbol) {
    int move;
    do {
        cout << BLUE << "Enter your move (0-8): " << RESET;
        cin >> move;
    } while (move < 0 || move >= 9 || board[move] != ' ');
    board[move] = playerSymbol;
}

void playGame() {
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char playerSymbol = 'X';
    char computerSymbol = 'O';

    if (rand() % 2 == 0) {
        cout << BLUE << "Computer starts first." << RESET << endl;
        computerMove(board, computerSymbol, playerSymbol);
    } else {
        cout << BLUE << "You start first." << RESET << endl;
    }

    while (!isBoardFull(board)) {
        drawBoard(board);
        playerMove(board, playerSymbol);
        if (isWinner(board, playerSymbol)) {
            drawBoard(board);
            cout << BLUE << "You win!" << RESET << endl;
            return;
        }
        computerMove(board, computerSymbol, playerSymbol);
        if (isWinner(board, computerSymbol)) {
            drawBoard(board);
            cout << BLUE << "Computer wins!" << RESET << endl;
            return;
        }
    }
    drawBoard(board);
    cout << BLUE << "Draw!" << RESET << endl;
}

int main() {
    srand(time(NULL));
    playGame();
    return 0;
}
