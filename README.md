# **TicTacToe**

My project `Tic-Tac-Toe` is a game where the user plays against an algorithm. The game is implemented in the console and runs on Replit.
The console game "Tic-Tac-Toe" is usually implemented using functions and data structures that model the game board, players, and game rules. One important function in such an implementation is the one that determines the computer's move. Here is a code snippet with comments that shows how the computer places the symbol 'O' on the game board. If the cell is occupied, the user or the algorithm cannot place their symbol in the same spot.
```c++
void computerMove(char board[], char computerSymbol, char playerSymbol) {
    // Проходим по всем ячейкам доски и пытаемся поставить символ компьютера в каждую свободную ячейку
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            board[i] = computerSymbol;
            // Если компьютер может выиграть на следующем ходу, то ставим символ компьютера в эту ячейку и выходим из функции
            if (isWinner(board, computerSymbol)) {
                return;
            }
                // Иначе, если игрок может выиграть на следующем х оду, то ставим символ игрока в эту ячейку, чтобы предотвратить его победу, и выходим из функции
            else if (isWinner(board, playerSymbol)) {
                board[i] = playerSymbol;
                return;
            }
            else {
                board[i] = ' ';
            }
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
```
Before starting the game, with a 50% chance, this snippet of code (\033[1;34m \033[0m is a command that colors the text in the console):
```c++
if (rand() % 2 == 0) {    //Кто будет ходить первым
    cout << "\033[1;34mComputer start the first.\033[0m" << endl;
    computerMove(board, computerSymbol, playerSymbol);
}
else {
    cout << "\033[1;34mYou start the first.\033[0m" << endl;
}
```
Another important function for the program to work is the function to create the game board:
```c++
void drawBoard(char board[]) {
    cout << " " << board[0] << " \033[1;36m┃\033[0m " << board[1] << " \033[1;36m┃\033[0m " << board[2] << endl;
    cout << "\033[1;36m━━━╋━━━╋━━━\033[0m" << endl;
    cout << " " << board[3] << " \033[1;36m┃\033[0m " << board[4] << " \033[1;36m┃\033[0m " << board[5] << endl;
    cout << "\033[1;36m━━━╋━━━╋━━━\033[0m" << endl;
    cout << " " << board[6] << " \033[1;36m┃\033[0m " << board[7] << " \033[1;36m┃\033[0m " << board[8] << endl;
}
```
It is clear that I refer to each sector of the game board as an array element from 0 to 8. The player’s or algorithm's move is also implemented. To make it easier for the user to play, I created a table that shows which game board sector is represented by which array index. Also, for aesthetic purposes, I used symbols from the Unicode table, which are equivalent to the symbols '|' and '-'.

![image](https://github.com/pro-parzi/tic_tac_toe/assets/128066686/c4fae0a8-095b-4509-a381-f0762732958a)

After creating the game board and the computer's move algorithm, I needed to write the win function. To do this, I used an array to check all possible cases:
```c++
bool isWinner(char board[], char symbol) {
    // Все возможные комбинации, которые могут привести к победе
    if ((board[0] == symbol && board[1] == symbol && board[2] == symbol) ||
        (board[3] == symbol && board[4] == symbol && board[5] == symbol) ||
        (board[6] == symbol && board[7] == symbol && board[8] == symbol) ||
        (board[0] == symbol && board[3] == symbol && board[6] == symbol) ||
        (board[1] == symbol && board[4] == symbol && board[7] == symbol) ||
        (board[2] == symbol && board[5] == symbol && board[8] == symbol) ||
        (board[0] == symbol && board[4] == symbol && board[8] == symbol) ||
        (board[2] == symbol && board[4] == symbol && board[6] == symbol)) {
        return true;
    }
    return false;
}
```

