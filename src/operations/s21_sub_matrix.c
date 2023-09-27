#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!s21_is_exists(A) || !s21_is_exists(B)) {
    return INVALID_MATRIX;
  }

  if (!s21_is_same_size(A, B)) {
    return CALCULATION_ERROR;
  }

  status status = OK;

  if (s21_create_matrix(A->rows, A->columns, result) == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  } else {
    status = INVALID_MATRIX;
  }

  return status;
}
