#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void drawBoard(char board[]) {
    cout << " " << board[0] << " \033[1;36m?\033[0m " << board[1] << " \033[1;36m?\033[0m " << board[2] << endl;
    cout << "\033[1;36m???????????\033[0m" << endl;
    cout << " " << board[3] << " \033[1;36m?\033[0m " << board[4] << " \033[1;36m?\033[0m " << board[5] << endl;
    cout << "\033[1;36m???????????\033[0m" << endl;
    cout << " " << board[6] << " \033[1;36m?\033[0m " << board[7] << " \033[1;36m?\033[0m " << board[8] << endl;
}
// Функция, которая проверяет, является ли данный символ победным

bool isWinner(char board[], char symbol) {
    // Проверяем все возможные комбинации, которые могут привести к победе
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
// Функция, которая проверяет, остались ли еще свободные ячейки на игровой доске
bool isBoardFull(char board[]) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            return false;
        }
    }
    return true;
}
// Функция, которая реализует ход компьютера
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
    void playerMove(char board[], char playerSymbol) {
        int move;
        do {
            cout << "\033[1;34mEnter your move (0-8): \033[0m";
            cin >> move;
            }
        while (board[move] != ' ');
            board[move] = playerSymbol;
}
void playGame() {
    char board[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
    char playerSymbol = 'X';
    char computerSymbol = 'O';

    if (rand() % 2 == 0) {    // Определяем, кто будет ходить первым случайным образом
        cout << "\033[1;34mComputer start the first.\033[0m" << endl;
        computerMove(board, computerSymbol, playerSymbol);
    }
    else {
        cout << "\033[1;34mYou start the first.\033[0m" << endl;
    }
    while (!isBoardFull(board)) {    // Игра продолжается до тех пор, пока не закончится доска или кто-то не выиграет
        drawBoard(board);
        playerMove(board, playerSymbol);
        if (isWinner(board, playerSymbol)) {
            drawBoard(board);
            cout << "\033[1;34mYou win!\033[0m" << endl;
            return;
        }
        computerMove(board, computerSymbol, playerSymbol);
        if (isWinner(board, computerSymbol)) {
            drawBoard(board);
            cout << "\033[1;34mComputer wins!\033[0m" << endl;
            return;
        }
    }
    drawBoard(board);
    cout << "\033[1;34mDraw\033[0m" << endl;
}

int main() {
    srand(time(NULL));    // Инициализация генератора случайных чисел
    playGame();    // Запуск игры
    return 0;
}
