#ifndef ROW_OPERATIONS_H
#define ROW_OPERATIONS_H

#include <matrix_macros.h>

void swap_xthRow_and_ythRow
(DATATYPE **A, int mRows, int nCols, int x, int y);

void k_X_nthRow(DATATYPE **A, int mRows, int nCols, int row, DATATYPE k);

void add_xthRow_ythRow(DATATYPE **A, int mRows, int nCols, int x, int y);

void sub_xthRow_ythRow(DATATYPE **A, int mRows, int nCols, int x, int y);

void add_xthRow_k_X_ythRow
(DATATYPE **A, int mRows, int nCols, int x, int y, DATATYPE k);

void sub_xthRow_k_X_ythRow
(DATATYPE **A, int mRows, int nCols, int x, int y, DATATYPE k);

#endif
