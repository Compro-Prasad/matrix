#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <math.h>
#include <conio.h>

#define DATATYPE float

#include "basic_checkings.c"
#include "row_operations.c"
#include "col_operations.c"
#include "str.c"


#define Row_operation_convert_element_to_one(A, mRows, nCols, i, j) { \
	DATATYPE x;                                                     \
	int k;                                                          \
	if (A[i][j] != 1.0) {                                           \
		if ((k = find_one_in_col(A, mRows, nCols, j)) >= 0)       \
			swap_xthRow_and_ythRow(A, mRows, nCols, i, k);      \
		else if ((x = nthCol_has_factor(A, mRows, nCols, j)))     \
			k_X_nthCol(A, mRows, nCols, j, 1 / x);              \
		if (A[i][j] != 1.0 && A[i][j])                            \
			k_X_nthRow(A, mRows, nCols, i, 1 / A[i][j]);        \
	}                                                               \
}

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
int main()
{
	DATATYPE **A;
	int m, n, i, j;
	printf("Enter number of rows of matrix: ");
	scanf("%d", &m);
	printf("Enter number of cols of matrix: ");
	scanf("%d", &n);
	assert(m > 0 && n > 0);
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
	char c[]="A0<=>A1";*/
	row_echilon(A, m, n);
	disp_matrix(A, m, n);
	//printf("%f", nthRow_has_factor(A, m, n, 1));
	return 0;
}
