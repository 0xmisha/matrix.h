#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!s21_is_exists(A)) {
    return INVALID_MATRIX;
  }

  if (A->columns != A->rows) {
    return CALCULATION_ERROR;
  }

  double det = 0;
  int status = OK;
  s21_determinant(A, &det);
  if (det == 0) {
    status = CALCULATION_ERROR;
  } else {
    matrix_t complements;
    s21_calc_complements(A, &complements);

    matrix_t transponted_complements;
    s21_transpose(&complements, &transponted_complements);

    s21_mult_number(&transponted_complements, 1.0 / det, result);

    s21_remove_matrix(&complements);
    s21_remove_matrix(&transponted_complements);
  }

  return status;
}
