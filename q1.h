#include <stdio.h>
#include <stdlib.h>

// define a struct
// contains row and column count
// and a 2D float array
struct matrixDimension{
    int row, column;
    float **el;
};

typedef struct matrixDimension MD;

// convert file content to
// the data structure of MD
MD readMatrix(FILE *);

// check whether matrix multiplication is possible
int checkMatrices(MD, MD);

// do the multiplication
MD innerProduct(MD, MD);

// write matrix content to file
void writeMatrix(FILE *, MD);
