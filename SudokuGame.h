//
// Created by kubec on 06.03.2024.
//

#include <iostream>

#ifndef SUDOKU_SUDOKUGAME_H
#define SUDOKU_SUDOKUGAME_H

namespace std {
    const int BOARD_SIZE = 9;

    class SudokuGame {
    private:
        int board[BOARD_SIZE][BOARD_SIZE]{};

    //Constructor
    public:
        SudokuGame(){
            for (int i = 0; i < BOARD_SIZE ; ++i) {
                for (int j = 0; j < BOARD_SIZE; ++j) {
                    board[i][j] = 0;
                }
            }
        }

    public:
        static void printBoardSize(){
            cout << BOARD_SIZE << endl;
        }

    public:
        void printBoard(){
            int currentHeight = 0;
            int currentWidth = 0;
            for (auto & i : board) {
                for (int j : i) {
                    if(currentWidth % 3 == 0 && currentWidth != 0)
                        printf("| ");

                    printf("%d ",j);

                    currentWidth++;
                }
                cout << endl;
                currentHeight++;
                if(currentHeight % 3 == 0 && currentHeight != 9){
                    for (int j = 0; j < (BOARD_SIZE*2)+3; ++j) {
                        printf("-");
                    }
                    cout << endl;
                }
                currentWidth = 0;
            }
            cout << endl;
        }

    public:
        bool setBoardValue(int X,int Y,int value){
            //Check if field value is in bounds
            if(value < 1 || value > 9){
                printf("ERROR - WRONG FIELD VALUE\n");
                return false;
            }

            //Check if Y value is in bounds
            if(Y < 1 || Y > 9){
                printf("ERROR - WRONG Y VALUE\n");
                return false;
            }

            //Check if X value is in bounds
            if(X < 1 || X > 9){
                printf("ERROR - WRONG Y VALUE\n");
                return false;
            }

            //Check if board field empty
            if(!checkIfBoardFieldEmpty(X,Y)){
                printf("ERROR - FIELD IS NOT EMPTY\n");
                return false;
            }

            //If everything all right set value on board
            board[Y-1][X-1] = value;
            return true;
        }

    private:
        bool checkIfBoardFieldEmpty(int X, int Y){
            if(board[Y-1][X-1] == 0){
                return true;
            }
            return false;
        }

    private:
        bool chceckIfColumnIsDone(int columnNumber){
            int sumOfAllValues = 0;

            for (int i = 0; i < BOARD_SIZE; ++i) {
                sumOfAllValues += board[columnNumber-1][i];
            }

            if(sumOfAllValues == 45)
                return true;

            return false;
        }
    };
}

#endif //SUDOKU_SUDOKUGAME_H
