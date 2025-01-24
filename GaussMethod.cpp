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
    // cout << "BACK SUB" << endl;
    float* unknowns = new float[mat.numRows];
    for (int i=mat.numRows; i>0; --i) {
        if (i == mat.numRows) {
            cout << "X" << i << endl; 
            // base case
            float constant = mat.grid[mat.numRows-1][mat.numCols-1].value;
            float unknown = mat.grid[mat.numRows-1][mat.numRows-1].value;
            // cout << "Const: " << constant << endl;
            // cout << "Unk: " << unknown << endl; 
            float solvedUnkown = constant / unknown;
            // cout << "Solved: " << solvedUnkown << endl;
            Counter::multDivCounter += 1;
            unknowns[i-1] = solvedUnkown;
            Counter::DisplayCounters();
            Counter::ResetCounters();

        }

        else {
            cout << "X" << i << endl;
            // cout << "NEW UNKNOWN DISCOVERY" << endl;
            // recursion
            float divisor = mat.grid[i-1][i-1].value;
            float constant = mat.grid[i-1][mat.numCols-1].value;
            int numTermsToSubtract = mat.numRows - i;
            // cout << "Divisor " << divisor << endl;
            // cout << "Constant " << constant << endl;
            // cout << "Terms to add: " << numTermsToSubtract << endl;
            float termSum = 0;
            for (int j=0; j<numTermsToSubtract; j++) {
                float term = mat.grid[i-1][mat.numRows-(j+1)].value * unknowns[mat.numRows - (1+j)];
                Counter::multDivCounter += 1;
                // cout << "Coefficient is " << mat.grid[i-1][mat.numRows-(j+1)].value << " with solved unk " << unknowns[mat.numRows - (1+j)] << endl;
                // cout << "Term is " << term << endl;
                if (termSum == 0) {
                    termSum += term;
                    continue; // We don't count adding a number to zero as an addSub operation
                }
                termSum += term;
                Counter::addSubCounter +=1;
            }
            // cout << "Term sum: " << termSum << endl;
            // subtract termSum from constant then divide with divisor
            float unknown = (constant - termSum) / divisor;
            // cout << "Unk: " << unknown << endl;
            Counter::addSubCounter += 1;
            Counter::multDivCounter += 1;
            unknowns[i-1] = unknown;
            Counter::DisplayCounters();
            Counter::ResetCounters();
            
        }
    }
    // (T) print out all unknowns
    for (int i=mat.numRows; i>0; i--) {
        cout << "x" << i << "=" << unknowns[i-1] << endl; 
    }
}
