#ifndef SQUARE_SOLVER_H
#define SQUARE_SOLVER_H

#include "SquareCommon.h"
const double eps = 1e-7;

roots SquareSolve (double a, double b, double c, double *x1, double *x2);
roots LinearSolve (double b, double c, double *x1, double *x2);
int IsEqual (double num_1, double num_2);

#endif
