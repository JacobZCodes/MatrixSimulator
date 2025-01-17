#ifndef MATRIX_OPERATIONS
#define MATRIX_OPERATIONS
#include "Matrix.h"
class MatrixOperations {
    public:
        static void ScaleRow(Matrix mat, int rowIndex, float scalar);
        static void SwapRows(Matrix mat, int row1Index, int row2Index);
        static void CombineRowsWithScalar(Matrix mat, Entry* rowToBeAddedTo, Entry* rowToBeScaled, float scalar);
        static void AddRows(Matrix mat, Entry* rowToBeAddedTo, float* rowToAdd) ;
        static void PrintRow(float* row, int rowLength);
        static bool HasFullRank(Matrix mat);
};
#endif