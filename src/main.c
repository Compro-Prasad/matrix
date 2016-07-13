#include <matrix.h>
#include <misc.h>
#include <malloc.h>
int main()
{
  DATATYPE **A, **B;
  int m, n, i, j;
  printf("Enter number of rows of matrix: ");
  scanf("%d", &m);
  printf("Enter number of cols of matrix: ");
  scanf("%d", &n);
  printf("Enter the elements in the matrix:\n");
  A = (DATATYPE **)malloc(m * sizeof(DATATYPE *));
  for (i = 0; i < m; i++)
    {
      A[i] = (DATATYPE *)malloc(n * sizeof(DATATYPE));
      for (j = 0; j < n; j++)
	scanf("%f", A[i] + j);
    }
  /*k_X_nthRow(A, m, n, 1, 5);
    disp_matrix(A, m, n);
    char c[]="A0<=>A1";
    row_echilon(A, m, n);*/
  B = inverse(A, m);
  disp_matrix(B, m, n);
  /*printf("%f", determinant(A, m));*/
  return 0;
}
