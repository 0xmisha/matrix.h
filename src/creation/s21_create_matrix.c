#include "../s21_matrix.h"

void handle_allocation_error(matrix_t *, status *);

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0) {
    return INVALID_MATRIX;
  }

  status status = OK;
  result->matrix = (double **)calloc(rows, sizeof(double *));
  handle_allocation_error(result, &status);

  for (int i = 0; i < rows; i++) {
    result->matrix[i] = (double *)calloc(columns, sizeof(double));
  }

  if (status == OK) {
    result->rows = rows;
    result->columns = columns;
  }

  return status;
}

void handle_allocation_error(matrix_t *result, status *status) {
  if (result->matrix == NULL) {
    *status = INVALID_MATRIX;
  }
}
