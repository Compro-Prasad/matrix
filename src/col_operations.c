#include <assert.h>

#include <matrix_macros.h>

void swap_xthCol_and_ythCol
(DATATYPE **A, int mRows, int nCols, int x, int y)
{
	assert(x < nCols && y < nCols);
	int i = 0, temp;
	for (; i < mRows; i++)
		SWAP(A[i][x], A[i][y], temp);
}
void k_X_nthCol(DATATYPE **A, int mRows, int nCols, int col, DATATYPE k)
{
	int i;
	assert(nCols > col);
	for (i = 0; i < mRows; i++)
		A[i][col] *= k;
}
void add_xthCol_ythCol(DATATYPE **A, int mRows, int nCols, int x, int y)
{
	int i;
	assert(x < nCols && y < nCols);
	for (i = 0; i < mRows; i++)
		A[i][x] += A[i][y];
}
void sub_xthCol_ythCol(DATATYPE **A, int mRows, int nCols, int x, int y)
{
	int i;
	assert(x < nCols && y < nCols);
	for (i = 0; i < mRows; i++)
		A[i][x] -= A[i][y];
}
void add_xthCol_k_X_ythCol
(DATATYPE **A, int mRows, int nCols, int x, int y, DATATYPE k)
{
	k_X_nthCol(A, mRows, nCols, y, k);
	add_xthCol_ythCol(A, mRows, nCols, x, y);
}
void sub_xthCol_k_X_ythCol
(DATATYPE **A, int mRows, int nCols, int x, int y, DATATYPE k)
{
	k_X_nthCol(A, mRows, nCols, y, k);
	sub_xthCol_ythCol(A, mRows, nCols, x, y);
}
