#ifndef STR_H
#define STR_H
#include <stdio.h>

void trim_cmd(char *cmd);
void row_operation(DATATYPE **A, int mRows, int nCols, char *cmd);
void col_operation(DATATYPE **A, int mRows, int nCols, char *cmd);

#endif // STR_H
