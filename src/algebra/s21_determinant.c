#include "../s21_matrix.h"

double s21_det_util(matrix_t *);

int s21_determinant(matrix_t *A, double *result) {
  if (!s21_is_exists(A)) {
    return INVALID_MATRIX;
  }

  if (A->columns != A->rows) {
    return CALCULATION_ERROR;
  }

  if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else {
    *result = s21_det_util(A);
  }

  return OK;
}

double s21_det_util(matrix_t *A) {
  double det = 0;
  int sign = 1;

  if (A->rows == 2) {
    det = A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    for (int i = 0; i < A->columns; i++) {
      matrix_t sub_mat;
      s21_exclude_row_col(A, &sub_mat, 0, i);
      det += sign * A->matrix[0][i] * s21_det_util(&sub_mat);
      sign = -sign;
      s21_remove_matrix(&sub_mat);
    }
  }

  return det;
}
