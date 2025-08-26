#include <TXLib.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#include "SquareInput.h"

void Input (double *a, double *b, double *c, colors color)
    {
    assert (a && b && c);

    printf ("\033[%dm������� ������������ a, b, c ����������� ���������: ", color);

    while (scanf ("%lf %lf %lf", a, b, c) != 3)
        {
        ClearInputBuffer ();
        }
    }

void ClearInputBuffer ()
    {
    while (getchar() != '\n'){}
    printf("\n ���������, ��� �������� ������ ���������.\n");
    }
