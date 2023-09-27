#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (!s21_is_exists(A) || !s21_is_exists(B)) {
    return FAILURE;
  }

  if (!s21_is_same_size(A, B)) {
    return FAILURE;
  }

  bool status = SUCCESS;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPSILON) {
        status = FAILURE;
      }
    }
    if (status == FAILURE) break;
  }

  return status;
}
