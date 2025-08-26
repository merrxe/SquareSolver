#include <TXLib.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#include "SquareTester.h"
#include "SquareSolver.h"
#include "SquareCommandsRun.h"
#include "SquareInput.h"
#include "SquareOutput.h"

const double eps = 1e-7;

int main (int argc, char *argv[])
    {
    if (!CommandsCalled (argc, argv))
        {
        /*UNIT-ÒÅÑÒÛ*/
        int failed = nFailed();
        if (failed != 0)
            {
            printf("FAILED: %d", failed);
            }

        /*ÏÅÐÅÌÅÍÍÛÅ*/
        double a, b, c, x1, x2;
        a = b = c = 0;
        x1 = x2 = NAN;

        /*ÂÂÎÄ ÄÀÍÍÛÕ*/
        Input(&a, &b, &c);

        /*ÂÛÂÎÄ ÊÎÐÍÅÉ*/
        roots nRoots = SquareSolve (a, b, c, &x1, &x2);
        Output(nRoots, x1, x2);

        return 0;
        }
    }

roots SquareSolve (double a, double b, double c, double *x1, double *x2)
    {
    assert (x1 && x2);

    if (IsEqual(a, 0))
        {
        return LinearSolve (b, c, x1, x2);
        }

    else /* if (a != 0) */
        {
        if (IsEqual (c, 0)) /*     óðàâíåíèå âèäà ax^2 + bx = 0    */
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

        else /*    óðàâíåíèå âèäà ax^2 + bx + c= 0     */
            {
            double D, sqrt_D;
            D = b*b - 4*a*c;
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

roots LinearSolve (double b, double c, double *x1, double *x2)
    {
    assert (x1 && x2);

    if (IsEqual (b, 0)) {    /*     óðàâíåíèå âèäà c = 0   */
            if (IsEqual (c, 0))
                {
                return INFINITE_ROOTS;
                }
            else
                {
                return NO_ROOTS;
                }
        }

    else     /*    óðàâíåíèå âèäà bx + c = 0     */
        {
        *x1 = *x2 = -c/b;
        return ONE_ROOT;
        }
    }

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
