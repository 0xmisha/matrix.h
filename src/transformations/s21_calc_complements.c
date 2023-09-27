#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (!s21_is_exists(A)) {
    return INVALID_MATRIX;
  }

  if (A->rows != A->columns) {
    return CALCULATION_ERROR;
  }

  double det_A = 0;
  s21_determinant(A, &det_A);
  if (det_A == 0) {
    return CALCULATION_ERROR;
  }

  status status = OK;

  if (s21_create_matrix(A->rows, A->columns, result) == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t minor;
        s21_exclude_row_col(A, &minor, i, j);
        double det;
        s21_determinant(&minor, &det);
        result->matrix[i][j] = pow(-1, i + j) * det;
        s21_remove_matrix(&minor);
      }
    }
  } else {
    status = INVALID_MATRIX;
  }

  return status;
}
