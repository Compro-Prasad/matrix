#ifndef BASIC_CHECKINGS_H
#define BASIC_CHECKINGS_H

#include <matrix_macros.h>

#define find_one_in_row(A, r, c, row) find_element_in_row(A, r, c, row, 1)
#define find_one_in_col(A, r, c, col) find_element_in_col(A, r, c, col, 1)
#define find_zero_in_row(A, r, c, row) find_element_in_row(A, r, c, row, 0)
#define find_zero_in_col(A, r, c, col) find_element_in_col(A, r, c, col, 0)

unsigned char are_all_zero_in_nthRow
(DATATYPE **A, int mRows, int nCols, int row);

unsigned char are_all_zero_in_nthCol
(DATATYPE **A, int mRows, int nCols, int col);

unsigned char is_atmost_one_element_in_nthRow_nonzero
(DATATYPE **A, int mRows, int nCols, int row);

unsigned char is_atmost_one_element_in_nthCol_nonzero
(DATATYPE **A, int mRows, int nCols, int col);

int find_element_in_row
(DATATYPE **A, int mRows, int nCols, int row, DATATYPE element);

int find_element_in_col
(DATATYPE **A, int mRows, int nCols, int col, DATATYPE element);

DATATYPE nthRow_has_factor(DATATYPE **A, int mRows, int nCols, int n);

DATATYPE nthCol_has_factor(DATATYPE **A, int mRows, int nCols, int n);


#endif
