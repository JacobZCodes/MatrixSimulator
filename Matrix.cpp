#include "Matrix.h"
#include "Entry.h"
#include <math.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
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

