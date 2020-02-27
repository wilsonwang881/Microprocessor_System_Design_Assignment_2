#include <q1.h>

int main(){
  
  FILE *fpA, *fpB, *fpC;
  
  fpA = fopen("inA.txt", "r");
  fpB = fopen("inB.txt", "r");

  MD infoA = readMatrix(fpA);
  MD infoB = readMatrix(fpB);

  if (checkMatrices(infoA, infoB) == 0)
  {
    // if multiplication is possible
    // do the multiplication then write to file
    fpC = fopen("outC.txt", "w");
    MD infoC = innerProduct(infoA, infoB);
    writeMatrix(fpC, infoC);
    fclose(fpA);
    fclose(fpB);
    fclose(fpC);
  }
  else
  {
    // if multiplication not possible
    // prompt then quit
    printf("Two matrices cannot be multiplied!\n");

    // set an error indicating operaton not permitted
    return 1;
  }

  return 0;
}

MD readMatrix(FILE *f){
  // read the first two integers
  // that represent the row and the column count
  int row = 0;
  fscanf(f, "%d", &row);
  int column = 0;
  fscanf(f, "%d", &column);

  // allocate memory for 2D float array
  float **matrix = (float **)malloc(sizeof(float **)*row);
  float floatRead;

  // populate the content in the 2D float array
  for (int i = 0; i < row; i++)
  {
    matrix[i] = (float *)malloc(sizeof(float *)*column);

    for (int j = 0; j < column; j++)
    {
      fscanf(f, "%f", &floatRead);
      matrix[i][j] = floatRead;
    }
  }
  
  // return a struct that contains row and column count
  // and the 2D matrix
  MD matrixInfo = {.row = row, .column = column, .el = matrix};

  return matrixInfo;
}

int checkMatrices(MD A, MD B){
  // essential condition for matrix multiplication
  if (A.column != B.row)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

MD innerProduct(MD A, MD B){
  int row = A.row;
  int column = B.column;

  float **matrix = (float **)malloc(sizeof(float **)*row);
  float el;

  for (int i = 0; i < row; i++)
  {
    matrix[i] = (float *)malloc(sizeof(float *)*column);

    for (int j = 0; j < column; j++)
    {
      // reset the inner product
      el = 0.0;

      // take the inner product between row i of A and column j of B
      for (int k = 0; k < A.column; k++)
      {
        // sum up the element-wise product
        el = el + A.el[i][k] * B.el[k][j];
      }
      matrix[i][j] = el;
    }
  }

  MD matrixInfo = {.row = row, .column = column, .el = matrix};

  return matrixInfo;
}

void writeMatrix(FILE *f, MD C){
  fprintf(f, "%d %d\n", C.row, C.column);

  for (int i = 0; i < C.row; i++)
  {
    for (int j = 0; j < C.column; j++)
    {
      fprintf(f, "%f ", C.el[i][j]);
    }
  }
}


