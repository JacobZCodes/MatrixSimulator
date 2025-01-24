#include "Matrix.h"
#include "Entry.h"
#include "Counter.h"
#include <math.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <tuple>
using namespace std;

Matrix::Matrix(int N) {
    grid = new Entry*[N];
    float* naturalNumbersSet = Matrix::GenerateNaturalNumbersSet(N);
    for (int i=0; i<N; ++i) {
        grid[i] = new Entry[N];
        for (int j=0; j<N; j++) {
            tuple<int,int> position = make_tuple(i,j);
            grid[i][j].position = position;
            
            // Col 0 is all 1's
            if (j == 0) {
                grid[i][j].value = 1;
            }

            // Col 1 is all numbers from naturalNumbersSet
            if (j == 1) {
                grid[i][j].value = naturalNumbersSet[i];
            }

            // Col 2...i is all powers
            if (j>1) {
                grid[i][j].value = (float) pow (grid[i][1].value, (j));
            }

        }
    }
    numCols = N;
    numRows = N;

}
Matrix::Matrix() {

}
float* Matrix::GenerateNaturalNumbersSet(int size) {
    float* numbers = new float[size];
    for (int i=size; i>0; i--) {
        numbers[i-1] = i;
    }
    return numbers;

}
void Matrix::PrintMatrix() {
    for (int i=0; i<numRows; ++i) {
        for (int j=0; j<numCols; j++) {
            cout << fixed << setprecision(1) << grid[i][j].value << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Matrix::Randomize() {
    srand(time(0));
    for (int i=0; i<numRows; ++i) {
        for (int j=0; j<numCols; j++) {
            grid[i][j].value = (rand() % 9) + 1;
        }
    }
}
bool Matrix::hasNum(float num, float* arr, int spacesToCheck) {
    for (int i=0; i<spacesToCheck; ++i) {
        if (arr[i] == num) {
                // cout << "Num alr in vector" << endl;
                return true;
            }
        }
    // cout << "Num NOT in vecotr" << endl;
    return false;
}

float* Matrix::generateBVector() {
    float* bVector = new float[numRows];
    for (int i=0; i<numRows; ++i) {
        float val = (rand() % 99) + 1;
        while (hasNum(val,bVector,i)) {
            val = (rand() % 99) + 1;
            // cout << "val is " << val << endl;
            // cout << "i is " << i << endl;
            // if (i!=0) {
            //     cout << "b vector is currently ";
            //     for (int j=0; j<i+1; j++) {
            //         cout << bVector[j] << " ";
            //     }
            // }
            
        }
        bVector[i] = val;
        // print vector up tot his point
        // cout << "b vector is now ";
        // for (int j=0; j<i+1; j++) {
        //     cout << bVector[j] << " ";
        // }
    }
    return bVector;
}
void Matrix::Augment() {
    float* bVectorVals = generateBVector();
    for (int i=0; i<numRows; ++i) {
        // (1) Create ptr to old grid row
        Entry* oldRow = grid[i];
        // (2) Allocate memory for new grid row
        Entry* newRow = new Entry[numRows+1];
        // (3) Populate new grid row w/ old grow, last element comes from float* col
        for (int j=0; j<numRows+1; ++j) {
            tuple<int,int> position = make_tuple(i,j);
            newRow[j].position = position;
            if (j == numRows) {
                newRow[j].value = bVectorVals[i];
            }

            else {
                newRow[j].value = oldRow[j].value;
            }
        }
        // (4) Reassign grid[i] to new grid row
        grid[i] = newRow;
        // (5) Delete ptr & bVector
        delete[](oldRow);
        delete[](bVectorVals);
    }
    // (6) update num cols
    numCols++;

}
