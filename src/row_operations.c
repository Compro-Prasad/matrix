#include <assert.h>

#ifdef DEBUG
#include <stdio.h>
#endif

#include <matrix_macros.h>
#include <misc.h>

void swap_xthRow_and_ythRow
(DATATYPE **A, int mRows, int nCols, int x, int y)
{
	assert(x < mRows && y < mRows);
	int i = 0, temp;
	for (; i < nCols; i++)
		SWAP(A[x][i], A[y][i], temp);
#ifdef DEBUG
	printf("\nR%d <=> R%d", x, y);
	disp_matrix(A, mRows, nCols);
#endif
}
void k_X_nthRow(DATATYPE **A, int mRows, int nCols, int row, DATATYPE k)
{
	int i;
	assert(mRows > row);
	for (i = 0; i < nCols; i++)
		A[row][i] *= k;
#ifdef DEBUG
	printf("\n%.1f*R%d\n", k, row);
	disp_matrix(A, mRows, nCols);
#endif
}
void add_xthRow_ythRow(DATATYPE **A, int mRows, int nCols, int x, int y)
{
	int i;
	assert(x < mRows && y < mRows);
	for (i = 0; i < nCols; i++)
		A[x][i] += A[y][i];
#ifdef DEBUG
	printf("\nR%d - R%d\n", x, y);
	disp_matrix(A, mRows, nCols);
#endif
}
void sub_xthRow_ythRow(DATATYPE **A, int mRows, int nCols, int x, int y)
{
	int i;
	assert(x < mRows && y < mRows);
	for (i = 0; i < nCols; i++)
		A[x][i] -= A[y][i];
#ifdef DEBUG
	printf("\nR%d - R%d\n", x, y);
	disp_matrix(A, mRows, nCols);
#endif
}
void add_xthRow_k_X_ythRow
(DATATYPE **A, int mRows, int nCols, int x, int y, DATATYPE k)
{
	int i;
	assert(x < mRows && y < mRows);
	for (i = 0; i < nCols; i++)
		A[x][i] += k * A[y][i];
#ifdef DEBUG
	printf("\nR%d + %.1f*R%d\n", x, k, y);
	disp_matrix(A, mRows, nCols);
#endif
}
void sub_xthRow_k_X_ythRow
(DATATYPE **A, int mRows, int nCols, int x, int y, DATATYPE k)
{
	int i;
	assert(x < mRows && y < mRows);
	for (i = 0; i < nCols; i++)
		A[x][i] -= k * A[y][i];
#ifdef DEBUG
	printf("\nR%d - %.1f*R%d\n", x, k, y);
	disp_matrix(A, mRows, nCols);
#endif
}
