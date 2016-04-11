//#include "str.h"
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
void col_operation(DATATYPE **A, int mRows, int nCols, char *cmd)
{
	int x, y;
	DATATYPE k;
	if (sscanf(cmd, "A%d-%fA%d", &x, &k, &y) == 3)
		sub_xthCol_k_X_ythCol(A, mRows, nCols, x, y, k);
	else if (sscanf(cmd, "A%d+%fA%d", &x, &k, &y) == 3)
		add_xthCol_k_X_ythCol(A, mRows, nCols, x, y, k);
	else if (sscanf(cmd, "A%d-A%d", &x, &y) == 2)
		sub_xthCol_ythCol(A, mRows, nCols, x, y);
	else if (sscanf(cmd, "A%d+A%d", &x, &y) == 2)
		add_xthCol_ythCol(A, mRows, nCols, x, y);
	else if (sscanf(cmd, "%fA%d", &k, &y) == 2)
		k_X_nthCol(A, mRows, nCols, y, k);
	else if (sscanf(cmd, "A%d<=>A%d", &x, &y) == 2)
		swap_xthCol_and_ythCol(A, mRows, nCols, x, y);
	else
		printf("Wrong command");
}
