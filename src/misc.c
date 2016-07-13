#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#include <matrix_macros.h>
#include <basic_checkings.h>
#include <row_operations.h>
#include <col_operations.h>

void disp_matrix(DATATYPE **A, int mRows, int nCols)
{
  int i = 0, j;
  for (; i < mRows; i++)
    {
      for (j = 0; j < nCols; j++)
	printf("%.1f ", A[i][j]);
      printf("\n");
    }
}

void Row_operation_convert_element_to_one
(DATATYPE **A, int mRows, int nCols, int i, int j)
{
  DATATYPE x;
  int k;
  if (A[i][j] != 1.0)
    {
      if ((k = find_one_in_col(A, mRows, nCols, j)) >= 0)
	swap_xthRow_and_ythRow(A, mRows, nCols, i, k);
      else if ((x = nthCol_has_factor(A, mRows, nCols, j)))
	k_X_nthCol(A, mRows, nCols, j, 1 / x);
      if (A[i][j] != 1.0 && A[i][j])
	k_X_nthRow(A, mRows, nCols, i, 1 / A[i][j]);
    }
}

void Col_operation_convert_element_to_one
(DATATYPE **A, int mRows, int nCols, int i, int j)
{
  DATATYPE x;
  int k;
  if (A[i][j] != 1.0)
    {
      if ((k = find_one_in_row(A, mRows, nCols, i)) >= 0)
	swap_xthCol_and_ythCol(A, mRows, nCols, j, k);
      else if ((x = nthRow_has_factor(A, mRows, nCols, i)))
	k_X_nthRow(A, mRows, nCols, i, 1 / x);
      if (A[i][j] != 1.0 && A[i][j])
	k_X_nthCol(A, mRows, nCols, j, 1 / A[i][j]);
    }
}
