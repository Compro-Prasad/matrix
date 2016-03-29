#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <conio.h>

#define SWAP(x, y, z) z = x, x = y, y = z
#define find_one_in_row(A, r, c, row) find_element_in_row(A, r, c, row, 1)
#define find_one_in_col(A, r, c, col) find_element_in_col(A, r, c, col, 1)
#define find_zero_in_row(A, r, c, row) find_element_in_row(A, r, c, row, 0)
#define find_zero_in_col(A, r, c, col) find_element_in_col(A, r, c, col, 0)

#define DATATYPE float

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
void swap_xthRow_and_ythRow
(DATATYPE **A, int mRows, int nCols, int x, int y)
{
	assert(x < mRows && y < mRows);
	int i = 0, temp;
	for (; i < nCols; i++)
		SWAP(A[x][i], A[y][i], temp);
}
void swap_xthCol_and_ythCol
(DATATYPE **A, int mRows, int nCols, int x, int y)
{
	assert(x < nCols && y < nCols);
	int i = 0, temp;
	for (; i < mRows; i++)
		SWAP(A[i][x], A[i][y], temp);
}
void trim_cmd(char *cmd)
{
	int i = 0, j, k;
	for (; cmd[i]; i++)
	{
		if (cmd[i] == ' ' ||
			cmd[i] == ']' ||
			cmd[i] == '[')
		{
			k = j = i;
			while (cmd[j] == ' ' ||
				cmd[j] == '[' ||
				cmd[j] == ']') j++;
			while (cmd[j])
				cmd[k++] = cmd[j++];
			cmd[k] = cmd[j];
		}
	}
	printf("%s", cmd);
}
void disp_matrix(DATATYPE **A, int mRows, int nCols)
{
	int i = 0, j;
	for (; i < mRows; i++)
	{
		for (j = 0; j < nCols; j++)
			printf("%f ", A[i][j]);
		printf("\n");
	}
}
void k_X_nthRow(DATATYPE **A, int mRows, int nCols, int row, DATATYPE k)
{
	int i;
	assert(mRows > row);
	for (i = 0; i < nCols; i++)
		A[row][i] *= k;
}
void add_xthRow_ythRow(DATATYPE **A, int mRows, int nCols, int x, int y)
{
	int i;
	assert(x < mRows && y < mRows);
	for (i = 0; i < nCols; i++)
		A[x][i] += A[y][i];
}
void sub_xthRow_ythRow(DATATYPE **A, int mRows, int nCols, int x, int y)
{
	int i;
	assert(x < mRows && y < mRows);
	for (i = 0; i < nCols; i++)
		A[x][i] -= A[y][i];
}
void add_xthRow_k_X_ythRow
(DATATYPE **A, int mRows, int nCols, int x, int y, DATATYPE k)
{
	k_X_nthRow(A, mRows, nCols, y, k);
	add_xthRow_ythRow(A, mRows, nCols, x, y);
}
void sub_xthRow_k_X_ythRow
(DATATYPE **A, int mRows, int nCols, int x, int y, DATATYPE k)
{
	k_X_nthRow(A, mRows, nCols, y, k);
	sub_xthRow_ythRow(A, mRows, nCols, x, y);
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
void row_operation(DATATYPE **A, int mRows, int nCols, char *cmd)
{
	int x, y;
	DATATYPE k;
	if (sscanf(cmd, "A%d-%fA%d", &x, &k, &y) == 3)
		sub_xthRow_k_X_ythRow(A, mRows, nCols, x, y, k);
	else if (sscanf(cmd, "A%d+%fA%d", &x, &k, &y) == 3)
		add_xthRow_k_X_ythRow(A, mRows, nCols, x, y, k);
	else if (sscanf(cmd, "A%d-A%d", &x, &y) == 2)
		sub_xthRow_ythRow(A, mRows, nCols, x, y);
	else if (sscanf(cmd, "A%d+A%d", &x, &y) == 2)
		add_xthRow_ythRow(A, mRows, nCols, x, y);
	else if (sscanf(cmd, "%fA%d", &k, &y) == 2)
		k_X_nthRow(A, mRows, nCols, y, k);
	else if (sscanf(cmd, "A%d<=>A%d", &x, &y) == 2)
		swap_xthRow_and_ythRow(A, mRows, nCols, x, y);
	else
		printf("Wrong command");
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
	disp_matrix(A, m, n);*/
	char c[]="A0<=>A1";
	row_operation(A, m, n, c);
	disp_matrix(A, m, n);
	return 0;
}
