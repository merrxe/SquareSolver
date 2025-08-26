#include <TXLib.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#include "SquareSolver.h"

//????????????????????????????????????????????????
//! Solves a square equation ax2 + bx + c = 0
//!
//! @param [in]   a   a-coefficient
//! @param [in]   b   b-coefficient
//! @param [in]   c   c-coefficient
//! @param [out]  x1  Pointer to the 1st root
//! @param [out]  x2  Pointer to the 2nd root
//!
//! @return Numbers of roots
//!
//! @note If equation has only one root x1 = x2
//????????????????????????????????????????????????
roots SquareSolve (double a, double b, double c, double *x1, double *x2)
    {
    assert (x1 && x2);

    if (IsEqual(a, 0))
        {
        return LinearSolve (b, c, x1, x2);
        }

    else /* if (a != 0) */
        {
        if (IsEqual (c, 0)) /*   ��������� ���� ax^2 + bx = 0    */
            {
            if (IsEqual (b, 0))
                {
                x1 = x2 = 0;
                return ONE_ROOT;
                }
            else /* if (b != 0) */
                {
                *x1 = 0;
                *x2 = -b/a;
                return TWO_ROOTS;
                }
            }

        else /*    ��������� ���� ax^2 + bx + c= 0     */
            {
            double D, sqrt_D;
            D = b*b - 4*a*c;
            sqrt_D = 0;

            if (D > 0)
                {
                sqrt_D = sqrt(D);
                *x1 = (-b - sqrt_D) / (2 * a);
                *x2 = (-b + sqrt_D) / (2 * a);
                return TWO_ROOTS;
                }

            else if (IsEqual (D, 0))
                {
                sqrt_D = sqrt(D);
                *x1 = *x2 = (-b + sqrt_D) / (2 * a);
                return ONE_ROOT;
                }

            else /* if (D < 0) */
                {
                return NO_REAL_SOLUTION;
                }
            }
        }
    }

//????????????????????????????????????????????????
//! Solves a linear equation bx + c = 0
//!
//! @param [in]   b   b-coefficient
//! @param [in]   c   c-coefficient
//! @param [out]  x1  Pointer to the 1st root
//! @param [out]  x2  Pointer to the 2nd root
//!
//! @return Numbers of roots
//!
//! @note If equation has only one root x1 = x2
//????????????????????????????????????????????????
roots LinearSolve (double b, double c, double *x1, double *x2)
    {
    assert (x1 && x2);

    if (IsEqual (b, 0)) {    /*  ��������� ���� c = 0   */
            if (IsEqual (c, 0))
                {
                return INFINITE_ROOTS;
                }
            else
                {
                return NO_ROOTS;
                }
        }

    else     /*  ��������� ���� bx + c = 0     */
        {
        *x1 = *x2 = -c/b;
        return ONE_ROOT;
        }
    }

//????????????????????????????????????????????????
//! Check if the 1st number is equal to the 2nd number
//!
//! @param [in]   num_1   1st number
//! @param [in]   num_2   2nd number
//!
//! @return True or false (1 or 0)
//????????????????????????????????????????????????
int IsEqual (double num_1, double num_2)
    {
    if (fabs(num_1 - num_2) < eps)
        {
        return 1;
        }
    else
        {
        return 0;
        }
    }
