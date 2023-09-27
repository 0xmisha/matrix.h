#include "../s21_matrix.h"

int s21_is_exists(matrix_t *A) {
  if (A == NULL || A->matrix == NULL || A->columns <= 0 || A->rows <= 0) {
    return 0;
  }

  bool status = 1;

  for (int i = 0; i < A->rows; i++) {
    if (A->matrix[i] == NULL) {
      status = 0;
      break;
    }
  }

  return status;
}

int s21_is_same_size(matrix_t *A, matrix_t *B) {
  bool status = 1;

  if (A->rows != B->rows || A->columns != B->columns) {
    status = 0;
  }

  return status;
}

int s21_exclude_row_col(matrix_t *A, matrix_t *result, int excluding_row,
                        int excluding_col) {
  if (!s21_is_exists(A)) {
    return INVALID_MATRIX;
  }

  if (excluding_row >= A->rows || excluding_col >= A->columns) {
    return CALCULATION_ERROR;
  }

  int new_rows = A->rows - 1;
  int new_cols = A->columns - 1;
  if (s21_create_matrix(new_rows, new_cols, result) != OK) {
    return CALCULATION_ERROR;
  }

  int i_idx = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == excluding_row) continue;

    int j_idx = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j == excluding_col) continue;

      result->matrix[i_idx][j_idx] = A->matrix[i][j];
      j_idx++;
    }
    i_idx++;
  }

  return OK;
}

void print_matrix(matrix_t A) {
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      printf("%lf ", A.matrix[i][j]);
    }
    printf("\n");
  }
}
