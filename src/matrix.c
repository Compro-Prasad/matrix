#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <assert.h>

#include <matrix_macros.h>
#include <basic_checkings.h>
#include <row_operations.h>
#include <col_operations.h>
#include <misc.h>

void row_echilon(DATATYPE **A, int mRows, int nCols)
{
  int i = 0, j;
  for (; i < mRows; i++)
    {
      Row_operation_convert_element_to_one(A, mRows, nCols, i, i);
      for (j = i + 1; j < mRows; j++)
	sub_xthRow_k_X_ythRow(A, mRows, nCols, j, i, A[j][i]);
    }
}

void col_echilon(DATATYPE **A, int mRows, int nCols)
{
  int i = 0, j;
  for (; i < nCols; i++)
    {
      Col_operation_convert_element_to_one(A, mRows, nCols, i, i);
      for (j = i + 1; j < nCols; j++)
	sub_xthCol_k_X_ythCol(A, mRows, nCols, j, i, A[j][i]);
    }
}

DATATYPE determinant(DATATYPE **A, int order)
{
  assert(order > 0);
  if (order == 1)
    return A[0][0];
  DATATYPE **b = (DATATYPE **)malloc(sizeof(DATATYPE *) * (order - 1));
  DATATYPE x = 0.0;
  int i = 0, j, k, f1, f2 = -1;
  for (; i < order - 1; i++)
    b[i] = (DATATYPE *)malloc(sizeof(DATATYPE) * (order - 1));
  for (i = 0; i < order; i++)
    {
      for (j = 1; j < order; j++)
	{
	  f1 = 0;
	  for (k = 0; k < order; k++)
	    if (k != i)
	      b[j - 1][k - f1] = A[j][k];
	    else
	      f1 = 1;
	}
      x += (f2 = f2 == 1 ? -1 : 1) * determinant(b, order - 1) * A[0][i];
    }
  for (i = 0; i < order - 1; i++)
    free(b[i]);
  free(b);
  return x;
}

DATATYPE **inverse(DATATYPE **A, int order)
{
  assert(order > 0);
  DATATYPE **B = (DATATYPE **)malloc(sizeof(DATATYPE *) * order);
  DATATYPE **I = (DATATYPE **)malloc(sizeof(DATATYPE *) * order);
  DATATYPE temp;
  int i = 0, j;
  for (; i < order; i++)
    {
      B[i] = (DATATYPE *)malloc(sizeof(DATATYPE) * order);
      I[i] = (DATATYPE *)malloc(sizeof(DATATYPE) * order);
      for (j = 0; j < order; j++)
	{
	  if (i == j)
	    I[i][j] = 1;
	  else
	    I[i][j] = 0;
	  B[i][j] = A[i][j];
	}
    }
  for (i = 0; i < order; i++)
    {
      temp = A[i][i];
      Row_operation_convert_element_to_one(B, order, order, i, i);
      if (A[i][i] != temp)
	Row_operation_convert_element_to_one(I, order, order, i, i);
      for (j = 0; j < order; j++)
	if (A[j][i] != 0)
	  {
	    sub_xthRow_k_X_ythRow(B, order, order, j, i, A[j][i]);
	    sub_xthRow_k_X_ythRow(I, order, order, j, i, A[j][i]);
	  }
    }
  for (i = 0; i < order; i++)
    free(B[i]);
  free(B);
  return I;
}
