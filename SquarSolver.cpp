#include <TXLib.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#include "Tester.h"
#include "SquarSolver.h"

const double eps = 1e-7;

void Input (double *a, double *b, double *c);
void Output (roots nRoots, double x1, double x2);

roots LinearSolve (double b, double c, double *x1, double *x2);

void ClearInputBuffer ();

int main (void)
    {
    /*UNIT-ТЕСТЫ*/
    int failed = nFailed();
    if (failed != 0)
        {
        printf("FAILED: %d", failed);
        }

    /*ПЕРЕМЕННЫЕ*/
    double a, b, c, x1, x2;
    a = b = c = 0;
    x1 = x2 = 0;

    /*ВВОД ДАННЫХ*/
    Input(&a, &b, &c);

    /*ВЫВОД КОРНЕЙ*/
    roots nRoots = SquareSolve (a, b, c, &x1, &x2);
    Output(nRoots, x1, x2);

    return 0;
    }


void Input (double *a, double *b, double *c)
    {
    assert (a && b && c);

    printf ("Введите коэффициенты квадратного уравнения через пробел: ");

    while (scanf ("%lf %lf %lf", a, b, c) != 3)
        {
        ClearInputBuffer ();
        }
    }


void Output (roots nRoots, double x1, double x2)
    {
    switch (nRoots)
        {
        case NO_REAL_SOLUTION:  printf("\nУравнение не имеет действительных корней.");
                                break;



        case NO_ROOTS:          printf("\nУравнение не имеет решений.");
                                break;



        case ONE_ROOT:          printf("\nУравнение имеет один действительный корень: х = %.2f.", x1);
                                break;



        case TWO_ROOTS:         printf("\nУравнение имеет два действительных корня: х1 = %.2f и x2 = %.2f.", x1, x2);
                                break;



        case INFINITE_ROOTS:    printf("\nУравнение имеет бесконечно много решений.");
                                break;



        default:                printf("\nFAILED");
                                break;
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
        if (IsEqual (c, 0)) /*     уравнение вида ax^2 + bx = 0    */
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


        else /*    уравнение вида ax^2 + bx + c= 0     */
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

    if (IsEqual (b, 0)) {    /*     уравнение вида c = 0   */
            if (IsEqual (c, 0))
                {
                return INFINITE_ROOTS;
                }
            else
                {
                return NO_ROOTS;
                }
        }

    else     /*    уравнение вида bx + c = 0     */
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



void ClearInputBuffer ()
    {
    while (getchar() != '\n'){}
    printf("\n Убедитесь, что введёные данные корректны.\n");
    }
