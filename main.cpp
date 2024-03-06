#include <iostream>
#include <iomanip>
#include "SudokuGame.h"

using namespace std;

void test(){
    SudokuGame gameInstance;

    gameInstance.printBoardSize();

    gameInstance.setBoardValue(2,2,3);

    gameInstance.setBoardValue(2,3,6);
    gameInstance.setBoardValue(9,9,5);
    gameInstance.setBoardValue(1,1,8);

    gameInstance.printBoard();
}

void pre(int length){
    /* Time function returns the time since the
        Epoch(jan 1 1970). Returned time is in seconds. */
    time_t start, end;

    /* You can call it like this : start = time(NULL);
    in both the way start contain total time in seconds
    since the Epoch. */
    time(&start);

    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);


    for (int i = 0; i < length; ++i) {
        for (int i = 0; i < length; ++i) {
            printf("");
        }
    }

    // Recording end time.
    time(&end);

    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
}

void post(int length){
    /* Time function returns the time since the
        Epoch(jan 1 1970). Returned time is in seconds. */
    time_t start, end;

    /* You can call it like this : start = time(NULL);
    in both the way start contain total time in seconds
    since the Epoch. */
    time(&start);

    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);


    for (int i = 0; i < length; i++) {
        for (int i = 0; i < length; i++) {
            printf("");
        }
    }

    // Recording end time.
    time(&end);

    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
}

int main() {
//    int len = 35000;
//
//    pre(len);
//    post(len);

    char a = 0b11111111;
    printf("%d",a);

    return 0;
}


