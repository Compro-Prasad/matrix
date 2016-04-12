#include <stdio.h>
#include <malloc.h>
#include <assert.h>

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

DATATYPE determinant(DATATYPE **A, int order)
{
	assert(order > 0);
	if (order == 1)
		return A[0][0];
	DATATYPE **b = (float **)malloc(sizeof(float *) * (order - 1));
	DATATYPE x = 0.0;
	int i = 0, j, k, f1, f2 = -1;
	for (; i < order - 1; i++)
		b[i] = (float *)malloc(sizeof(float) * (order - 1));
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
