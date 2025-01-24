#ifndef GAUSS_METHOD
#define GAUSS_METHOD
#include "Matrix.h"
class GaussMethod {
    public:
        static void ReduceToREF(Matrix mat);
        static void MakeAllEntriesBeneathThisPivotZero(Matrix mat, tuple<int,int> pivotPosition);
        static float FindCombinationScalar(float numToScale, float numToBeMadeZero);
        static void BackSub(Matrix mat);
};
#endif