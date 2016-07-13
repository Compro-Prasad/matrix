#ifndef MATRIX_H
#define MATRIX_H

#include <matrix_macros.h>

void row_echilon(DATATYPE **A, int mRows, int nCols);

void col_echilon(DATATYPE **A, int mRows, int nCols);

DATATYPE determinant(DATATYPE **A, int order);

DATATYPE **inverse(DATATYPE **A, int order);

#endif
