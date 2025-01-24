#include "GaussMethod.h"
#include "MatrixOperations.h"
#include "Counter.h"
#include <iostream>
using namespace std;
void GaussMethod::ReduceToREF(Matrix mat) { 
    for (int i=0;i<mat.numRows; ++i) {
        // cout << "BEGIN STEP " << i+1 << endl;
        // find pivot
        float currentPivot = mat.grid[i][i].value;
        // make zeroes beneath pivot
        MakeAllEntriesBeneathThisPivotZero(mat, mat.grid[i][i].position);
        // cout << "STEP " << i+1 << " M/D is " << Counter::multDivCounter << endl;
        // cout << "STEP " << i+1 << " A/S is " << Counter::addSubCounter << endl;
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
    float numToMakeZero = numToBeMadeZero;
    float numToAddToNumToMakeZero = numToScale;
    Counter::multDivCounter++;
    // cout << "Scalar computed, mult/div is: " << Counter::multDivCounter << endl;
    return (numToMakeZero/numToAddToNumToMakeZero) * -1;
}

void GaussMethod::BackSub(Matrix mat) {
    cout << "BACK SUB" << endl;
    float* unknowns = new float[mat.numRows];
    for (int i=mat.numRows; i>0; --i) {
        if (i == mat.numRows) {
            // base case
            float constant = mat.grid[mat.numRows-1][mat.numCols-1].value;
            float unknown = mat.grid[mat.numRows-1][mat.numRows-1].value;
            float solvedUnkown = constant / unknown;
            Counter::multDivCounter += 1;
            unknowns[0] = solvedUnkown;

        }

        else {
            // recursion
            float reciprocal = 1/mat.grid[i-1][i-1].value;
            Counter::multDivCounter += 1;
            float constant = mat.grid[i-1][mat.numCols-1].value;
            int numTermsToSubtract = mat.numRows - i;
            float termSum = 0;
            for (int j=0; j<numTermsToSubtract; j++) {
                float term = mat.grid[i-1][mat.numRows-(j+1)].value * unknowns[j];
                Counter::multDivCounter += 1;
                termSum += term;
                Counter::addSubCounter +=1;
            }
            // subtract termSum from constant then multiply by reciprocal
            float unknown = reciprocal * (constant - termSum);
            Counter::addSubCounter += 1;
            Counter::multDivCounter += 1;
            unknowns[mat.numRows - i] = unknown;

        
            
        }
    }
    // (T) print out all unknowns
    for (int i=0; i<mat.numRows; ++i) {
        cout << "x" << i+1 << "=" << unknowns[i] << endl; 
    }
}
