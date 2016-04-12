#include <stdio.h>
#include <malloc.h>
#include <math.h>

#include <matrix_macros.h>
#include <basic_checkings.h>
#include "include/row_operations.h"
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
int main()
{
	DATATYPE **A;
	int m, n, i, j;
	printf("Enter number of rows of matrix: ");
	scanf("%d", &m);
	printf("Enter number of cols of matrix: ");
	scanf("%d", &n);
	printf("Enter the elements in the matrix:\n");
	A = (DATATYPE **)malloc(m * sizeof(DATATYPE *));
	for (i = 0; i < m; i++)
	{
		A[i] = (DATATYPE *)malloc(n * sizeof(DATATYPE));
		for (j = 0; j < n; j++)
			scanf("%f", A[i] + j);
	}
	/*k_X_nthRow(A, m, n, 1, 5);
	disp_matrix(A, m, n);
	char c[]="A0<=>A1";
	row_echilon(A, m, n);
	disp_matrix(A, m, n);*/
	printf("%f", determinant(A, m));
	return 0;
}
