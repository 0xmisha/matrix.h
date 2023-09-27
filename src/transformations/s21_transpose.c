#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (!s21_is_exists(A)) {
    return INVALID_MATRIX;
  }

  status status = OK;

  if (s21_create_matrix(A->columns, A->rows, result) == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  } else {
    status = INVALID_MATRIX;
  }

  return status;
}
