#ifndef MATRIX
#define MATRIX
#include "Entry.h"
class Matrix {
    public:
        Matrix();
        Matrix(int N);
        void Randomize(); // change all existing values to random nums 0-9
        void PrintMatrix();
        void Augment();
        Entry** grid;
        int numRows;
        int numCols;
        float* GenerateNaturalNumbersSet(int size); // vondemonde matrix
        bool hasNum(float num, float* arr, int spacesToCheck);
        float* generateBVector();
        
};
#endif