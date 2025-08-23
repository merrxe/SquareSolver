#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

const double eps = 1e-7;


void Input (double *a, double *b, double *c);
void Output (int nRoots, double x1, double x2);

int SquareSolve (double a, double b, double c, double *x1, double *x2);
int LinearSolve (double b, double c, double *x1, double *x2);

int Comparing (double num_1, double num_2);

void ClearInputBuffer ();


int main (void)
    {
    /*����������*/
    double a, b, c, x1, x2;
    a = b = c = NAN;
    x1 = x2 = NAN;

    /*���� ������*/
    Input(&a, &b, &c);

    /*����� ������*/
    int nRoots = SquareSolve (a, b, c, &x1, &x2);
    Output(nRoots, x1, x2);

    return 0;
    }



enum roots
    {
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INFINITE_ROOTS,
    NO_REAL_SOLUTION
    };


void Input (double *a, double *b, double *c)
    {
    assert (a != 0 && b != 0 && c != 0);

    printf ("������� ������������ ����������� ��������� ����� ������: ");

    while (scanf ("%lf %lf %lf", a, b, c) != 3)
        {
        ClearInputBuffer ();
        }
    }


void Output (int nRoots, double x1, double x2)
    {
    switch (nRoots)
        {
        case NO_REAL_SOLUTION:  printf("\n��������� �� ����� �������������� ������.");
                                break;



        case NO_ROOTS:          printf("\n��������� �� ����� �������.");
                                break;



        case ONE_ROOT:          printf("\n��������� ����� ���� �������������� ������: � = %.2f.", x1);
                                break;



        case TWO_ROOTS:         printf("\n��������� ����� ��� �������������� �����: �1 = %.2f � x2 = %.2f.", x1, x2);
                                break;



        case INFINITE_ROOTS:    printf("\n��������� ����� ���������� ����� �������.");
                                break;



        default:                printf("\nFAILED");
                                break;
        }
    }




int SquareSolve (double a, double b, double c, double *x1, double *x2)
    {
    assert (x1 != 0 && x2 != 0);

    if (Comparing(a, 0))
        {
        return LinearSolve (b, c, x1, x2);
        }

    else /* if (a != 0) */
        {
        if (Comparing (c, 0)) /*     ��������� ���� ax^2 + bx = 0    */
            {
            *x1 = 0;
            *x2 = -b/a;
            return TWO_ROOTS;
            }


        else /*    ��������� ���� ax^2 + bx + c= 0     */
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

            else if (Comparing (D, 0))
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


int LinearSolve (double b, double c, double *x1, double *x2)
    {
    assert (x1 != 0 && x2 != 0);

    if (Comparing (b, 0)) {    /*     ��������� ���� c = 0   */
            if (Comparing (c, 0))
                {
                return INFINITE_ROOTS;
                }
            else
                {
                return NO_ROOTS;
                }
        }

    else     /*    ��������� ���� bx + c = 0     */
        {
        *x1 = *x2 = -c/b;
        return ONE_ROOT;
        }
    }




int Comparing (double num_1, double num_2)
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
    printf("\n ���������, ��� ������� ������ ���������.\n");
    }
