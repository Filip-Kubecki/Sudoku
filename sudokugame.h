//
// Created by kubec on 06.03.2024.
//

#include <iostream>
#include <time.h>

#ifndef SUDOKU_SUDOKUGAME_H
#define SUDOKU_SUDOKUGAME_H



namespace std {
const int BOARD_SIZE = 9;

class SudokuGame {
    //Variables
private:
    int board[BOARD_SIZE][BOARD_SIZE]{};
    int solutionBoard[BOARD_SIZE][BOARD_SIZE]{};
    int emptyIndexes[81];


    //Constructor
public:
    SudokuGame(){
        srand(time(0));
        for (int i = 0; i < BOARD_SIZE ; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                board[i][j] = 0;
            }
        }
    }

    //Methods
public:
    static void printBoardSize(){
        cout << BOARD_SIZE << endl;
    }
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
    void clearBoard(){
        for (int i = 0; i < BOARD_SIZE ; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                board[i][j] = 0;
            }
        }
    }
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

        if(!checkIfDoesntRepeat(Y-1,X-1,value)){
            printf("REPETITION");
            return false;
        }

        //Check if game won
        if (checkIfGameFinished()){
            return false;
        }

        //If everything all right set value on board
        board[Y-1][X-1] = value;
        return true;
    }
    bool checkIfGameFinished(){
        for (int i = 1; i < 10; ++i) {
            if(!checkIfColumnIsDone(i)){
                //                    printf("col %d",i);
                return false;
            }
        }
        for (int i = 1; i < 10; ++i) {
            if(!checkIfRowIsDone(i)){
                //                    printf("row %d",i);
                return false;
            }
        }
        for (int i = 1; i < 4; ++i) {
            for (int j = 1; j < 4; ++j) {
                if (!checkIfSquareIsDone(i,j)){
                    //                        printf("square %d,%d",i,j);
                    return false;
                }
            }
        }
        return true;
    }
    int getBoardValue(int x,int y){
        return board[x][y];
    }
    int generateBoard(int removeValues){
    milebegin:
        int steps = 0;
        int miles = 0;
        clearBoard();
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
            randomValue:
                int value = randomBoardValue();
                miles++;
                steps++;
                if(miles > 25000){
                    cout << "mile happ" << endl;
                    miles = 0;
                    goto milebegin;
                }
                if (steps > 11){
                    if (j!=0){
                        j--;
                        board[i][j] = 0;
                        steps = 0;
                        goto randomValue;
                    }else{
                        j=9;
                        i--;
                        board[i][j] = 0;
                        steps = 0;
                        goto randomValue;
                    }

                }
                if (checkIfDoesntRepeat(i,j,value)){
                    board[i][j] = value;
                }else{
                    goto randomValue;
                }
                //                    printBoard();
            }
        }
        // cout << miles << endl;

        //Set solutionBoard to generated Board
        copyArray(board,solutionBoard);

        //Removing values from board

        //Start by generating all indexes
        int boardPositions[81];
        int n = 0;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                boardPositions[n] = i+(10*j+1);
                n++;
            }
        }

        //Start removing random values based on array of indexes
        int rand;
        int size = 81;
        int y;
        int x;
        for (int i = 0; i < removeValues; ++i) {
            rand = randomValue(size);
            x = boardPositions[rand]/10;
            y = (boardPositions[rand]%10)-1;
            board[x][y] = 0;
            size--;
        }

        return miles;
    }
    int getSolutionValue(int x,int y){
        return solutionBoard[x][y];
    }
    int* getSolution(){
        return *solutionBoard;
    }

private:
    bool checkIfBoardFieldEmpty(int X, int Y){
        if(board[Y-1][X-1] == 0){
            return true;
        }
        return false;
    }
    bool checkIfColumnIsDone(int columnNumber){
        int sumOfAllValues = 0;

        for (int i = 0; i < BOARD_SIZE; ++i) {
            sumOfAllValues += board[i][columnNumber-1];
        }

        if(sumOfAllValues == 45)
            return true;

        return false;
    }
    bool checkIfRowIsDone(int rowNumber){
        int sumOfAllValues = 0;

        for (int i = 0; i < BOARD_SIZE; ++i) {
            sumOfAllValues += board[rowNumber-1][i];
        }

        if(sumOfAllValues == 45)
            return true;

        return false;
    }
    bool checkIfSquareIsDone(int squareRow,int squareCol){
        int sumOfAllValues = 0;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                sumOfAllValues += board[i+((squareRow-1)*3)][j+((squareCol-1)*3)];
                //For debugging
                //                    printf("%d ",board[i+((squareRow-1)*3)][j+((squareCol-1)*3)]);
            }
            //                printf("\n");
        }

        if(sumOfAllValues == 45)
            return true;

        return false;
    }
    bool checkIfDoesntRepeat(int x, int y, int value){
        // cout << "New test" << endl;
        //Check Column
        for (int i = 0; i < 9; ++i) {
            if (board[x][i] == value){
                // cout << "InternalCOL" << endl;
                return false;
            }
        }
        //Check Row
        for (int i = 0; i < 9; ++i) {
            if (board[i][y] == value){
                // cout << "InternalROW" << endl;
                return false;
            }
        }
        //Check Sqirtle
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i+(((x)/3)*3)][j+(((y)/3)*3)] == value){
                    // cout << "InternalSQRT" << endl;
                    return false;
                }
            }
        }
        return true;
    }
    int randomBoardValue(){
        return (rand()%9)+1;
    }
    int randomValue(int maxValue){
        return (rand()%maxValue)+1;
    }
    void copyArray(int copyInput[BOARD_SIZE][BOARD_SIZE],int copyOutput[BOARD_SIZE][BOARD_SIZE]){
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                copyOutput[i][j] = copyInput[i][j];
            }
        }
    }
};
}

#endif //SUDOKU_SUDOKUGAME_H
