#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

void _INPUT (double *a, double *b, double *c);
void _OUTPUT (int nRoots, double x1, double x2);

int SquareSolve (double a, double b, double c, double *x1, double *x2);
int LinearSolve (double b, double c, double *x1, double *x2);

int Comparing (double num_1, double num_2);


int main (void)
    {
    /*����������*/
    double a, b, c, x1, x2;
    a = b = c = NAN;
    x1 = x2 = NAN;

    /*���� ������*/
    _INPUT(&a, &b, &c);

    /*����� ������*/
    int nRoots = SquareSolve (a, b, c, &x1, &x2);
    _OUTPUT(nRoots, x1, x2);

    return 0;
    }



void _INPUT (double *a, double *b, double *c)
    {
    printf ("������� ������������ ����������� ��������� ����� ������: ");

    while (scanf ("%f %f %f", &a, &b, &c) != 3)
        {
        while (getchar() != '\n'){}
        printf("\n ���������, ��� ������� ������ ���������.\n");
        }
    }


void _OUTPUT (int nRoots, double x1, double x2)
    {
    switch (nRoots)
        {
        case 0:     printf("\n��������� �� ����� �������������� ������.");
                    break;


        case 1:     printf("\n��������� ����� ���� �������������� ������: � = %.2f.", x1);
                    break;


        case 2:     printf("\n��������� ����� ��� �������������� �����: �1 = %.2f � x2 = %.2f.", x1, x2);
                    break;


        case 8:     printf("\n��������� ����� ���������� ����� �������.");
                    break;


        default:    printf("\nFAILED");
                    break;
        }
    }




int SquareSolve (double a, double b, double c, double *x1, double *x2)
    {

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
            return 2;
            }


        else /*    ��������� ���� ax^2 + bx + c= 0     */
            {
            double D, sqrt_D;
            D = b*b - 4*a*c;
            printf("%f", D);
            if (D > 0)
                {
                sqrt_D = sqrt(D);
                *x1 = (-b - sqrt_D) / (2 * a);
                *x2 = (-b + sqrt_D) / (2 * a);
                return 2;
                }

            else if (Comparing (D, 0))
                {
                sqrt_D = sqrt(D);
                *x1 = *x2 = (-b + sqrt_D) / (2 * a);
                return 1;
                }

            else /* if (D < 0) */
                {
                return 0;
                }
            }
        }
    }


int LinearSolve (double b, double c, double *x1, double *x2)
    {
    if (Comparing (b, 0)) {    /*     ��������� ���� c = 0   */
            if (Comparing (c, 0))
                {
                return 8;
                }
            else
                {
                return 0;
                }
        }

    else     /*    ��������� ���� bx + c = 0     */
        {
        *x1 = *x2 = -c/b;
        return 1;
        }
    }




int Comparing (double num_1, double num_2)
    {
    double eps = 1e-7;
    if (fabs(num_1 - num_2) < eps)
        {
        return 1;
        }
    else
        {
        return 0;
        }
    }
