#include "GaussMethod.h"
#include "MatrixOperations.h"
#include <iostream>
using namespace std;
void GaussMethod::ReduceToREF(Matrix mat) { 
    for (int i=0;i<mat.numRows; ++i) {
        // find pivot
        float currentPivot = mat.grid[i][i].value;
        // make zeroes beneath pivot
        MakeAllEntriesBeneathThisPivotZero(mat, mat.grid[i][i].position);
    }
        
}

void GaussMethod::MakeAllEntriesBeneathThisPivotZero(Matrix mat, tuple<int,int> pivotPosition) {
    int pivotRowIndex = get<0>(pivotPosition);
    int pivotColIndex = get<1>(pivotPosition);
    int pivot = mat.grid[pivotRowIndex][pivotColIndex].value;
    Entry* pivotRow = mat.grid[pivotRowIndex];

    int lastRowIndex = mat.numRows - 1;
    int numEntriesToMakeZero = lastRowIndex - pivotRowIndex;

    for (int i=1; i<numEntriesToMakeZero+1; i++) { 
        float numToMakeZero = mat.grid[pivotRowIndex+i][pivotColIndex].value;
        Entry* rowWithNumToMakeZero = mat.grid[pivotRowIndex+i];
        float scalar = FindCombinationScalar(pivot, numToMakeZero);
        MatrixOperations::CombineRowsWithScalar(mat, rowWithNumToMakeZero, pivotRow, scalar);
        mat.PrintMatrix();
    }
}

// void GaussMethod::MakeFirstPivotEntryInThisRowZero(Matrix mat, float* rowToAddTo, float* rowToScale, int pivotIndex) {
//     int rowLength = mat.getNumCols();
//     float numToMakeZero = rowToAddTo[pivotIndex];
//     float numToScale = rowToScale[pivotIndex];
//     float scalar = FindCombinationScalar(num);
//     MatrixOperations::CombineRowsWithScalar(mat, rowToBeAlteredIndex, alteringRowIndex, scalar);
// }

float GaussMethod::FindCombinationScalar(float numToScale, float numToBeMadeZero) {
    cout << "finding scalar between " << numToScale << " and " << numToBeMadeZero << endl;
    float numToMakeZero = numToBeMadeZero;
    float numToAddToNumToMakeZero = numToScale;
    cout << "combo scalar is " << (numToMakeZero/numToAddToNumToMakeZero) * -1 << endl;
    return (numToMakeZero/numToAddToNumToMakeZero) * -1;
}
