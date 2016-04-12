#ifndef COL_OPERATIONS_H
#define COL_OPERATIONS_H

#include <matrix_macros.h>

void swap_xthCol_and_ythCol
(DATATYPE **A, int mRows, int nCols, int x, int y);

void k_X_nthCol(DATATYPE **A, int mRows, int nCols, int col, DATATYPE k);

void add_xthCol_ythCol(DATATYPE **A, int mRows, int nCols, int x, int y);

void sub_xthCol_ythCol(DATATYPE **A, int mRows, int nCols, int x, int y);

void add_xthCol_k_X_ythCol
(DATATYPE **A, int mRows, int nCols, int x, int y, DATATYPE k);

void sub_xthCol_k_X_ythCol
(DATATYPE **A, int mRows, int nCols, int x, int y, DATATYPE k);

#endif
