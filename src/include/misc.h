#ifndef MISC_H
#define MISC_H

#include <matrix_macros.h>

void disp_matrix(DATATYPE **A, int mRows, int nCols);

void Row_operation_convert_element_to_one
(DATATYPE **A, int mRows, int nCols, int i, int j);

void Col_operation_convert_element_to_one
(DATATYPE **A, int mRows, int nCols, int i, int j);

DATATYPE determinant(DATATYPE **A, int order);

#endif
