void swap_xthRow_and_ythRow
(DATATYPE **A, int mRows, int nCols, int x, int y)
{
	assert(x < mRows && y < mRows);
	int i = 0, temp;
	for (; i < nCols; i++)
		SWAP(A[x][i], A[y][i], temp);
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
	int i;
	assert(x < mRows && y < mRows);
	for (i = 0; i < nCols; i++)
		A[x][i] += k * A[y][i];
}
void sub_xthRow_k_X_ythRow
(DATATYPE **A, int mRows, int nCols, int x, int y, DATATYPE k)
{
	int i;
	assert(x < mRows && y < mRows);
	for (i = 0; i < nCols; i++)
		A[x][i] -= k * A[y][i];
}
