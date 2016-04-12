#include <assert.h>
#include <math.h>

#include <matrix_macros.h>

unsigned char are_all_zero_in_nthRow
(DATATYPE **A, int mRows, int nCols, int row)
{
	assert(row < mRows);
	int i = 0;
	for (; i < nCols; i++)
		if (A[row][i])
			return 0;
	return 1;
}

unsigned char are_all_zero_in_nthCol
(DATATYPE **A, int mRows, int nCols, int col)
{
	assert(col < nCols);
	int i = 0;
	for (; i < mRows; i++)
		if (A[i][col])
			return 0;
	return 1;
}

unsigned char is_atmost_one_element_in_nthRow_nonzero
(DATATYPE **A, int mRows, int nCols, int row)
{
	assert(row < mRows);
	int i = 0;
	unsigned char f = 0;
	for (; i < nCols; i++)
		if (A[row][i])
		{
			if (f)
				return 0;
			else
				f = 1;
		}
	return f;
}

unsigned char is_atmost_one_element_in_nthCol_nonzero
(DATATYPE **A, int mRows, int nCols, int col)
{
	assert(col < nCols);
	int i = 0;
	unsigned char f = 0;
	for (; i < mRows; i++)
		if (A[i][col])
		{
			if (f)
				return 0;
			else
				f = 1;
		}
	return f;
}

int find_element_in_row
(DATATYPE **A, int mRows, int nCols, int row, DATATYPE element)
{
	assert(row < mRows);
	int i = 0;
	for (; i < nCols; i++)
		if (A[row][i] == element)
			return i;
	return -1;
}

int find_element_in_col
(DATATYPE **A, int mRows, int nCols, int col, DATATYPE element)
{
	assert(col < nCols);
	int i = 0;
	for (; i < mRows; i++)
		if (A[i][col] == element)
			return i;
	return -1;
}

DATATYPE nthRow_has_factor(DATATYPE **A, int mRows, int nCols, int n)
{
	assert(n < mRows);
	int i = 1, k = A[n][0];
	for (; i < nCols; i++)
		if (k <= A[n][i])
		{
			if (fmod(A[n][i], k))
				return 0;
		}
		else
		{
			if (fmod(k, A[n][i]))
				return 0;
			k = A[n][i], i = -1;
		}
	return k;
}

DATATYPE nthCol_has_factor(DATATYPE **A, int mRows, int nCols, int n)
{
	assert(n < nCols);
	int i = 1, k = A[0][n];
	for (; i < mRows; i++)
		if (k <= A[i][n])
		{
			if (fmod(A[i][n], k))
				return 0;
		}
		else
		{
			if (fmod(k, A[i][n]))
				return 0;
			k = A[i][n], i = -1;
		}
	return k;
}
