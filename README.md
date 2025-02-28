# **TicTacToe**

My project `Tic-Tac-Toe` is a game where the user plays against an algorithm. The game is implemented in the console and runs on Replit.
The console game "Tic-Tac-Toe" is usually implemented using functions and data structures that model the game board, players, and game rules. One important function in such an implementation is the one that determines the computer's move. Here is a code snippet with comments that shows how the computer places the symbol 'O' on the game board. If the cell is occupied, the user or the algorithm cannot place their symbol in the same spot.
```c++
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
    return ;
}
```
Before starting the game, with a 50% chance, this snippet of code (\033[1;34m \033[0m is a command that colors the text in the console):
```c++
if (rand() % 2 == 0) {
cout << BLUE << "Computer starts first." << RESET << endl;
computerMove(board, computerSymbol, playerSymbol);
} else {
    cout << BLUE << "You start first." << RESET << endl;
}
```
Another important function for the program to work is the function to create the game board:
```c++
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
```
It is clear that I refer to each sector of the game board as an array element from 0 to 8. The player’s or algorithm's move is also implemented. To make it easier for the user to play, I created a table that shows which game board sector is represented by which array index. Also, for aesthetic purposes, I used symbols from the Unicode table, which are equivalent to the symbols '|' and '-'.

![image](https://github.com/pro-parzi/tic_tac_toe/assets/128066686/c4fae0a8-095b-4509-a381-f0762732958a)

After creating the game board and the computer's move algorithm, I needed to write the win function. To do this, I used an array to check all possible cases:
```c++
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
```

