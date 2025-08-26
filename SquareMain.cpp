#include <TXLib.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#include "SquareMain.h"

int main (int argc, char *argv[])
    {
    if (!CommandsCalled (argc, argv))
        {
        /*UNIT-�����*/
        int failed = nFailed();
        if (failed != 0)
            {
            printf("FAILED: %d", failed);
            }

        /*����������*/
        double a, b, c, x1, x2;
        a = b = c = 0;
        x1 = x2 = NAN;

        /*���� ������*/
        Input(&a, &b, &c);

        /*����� ������*/
        roots nRoots = SquareSolve (a, b, c, &x1, &x2);
        Output(nRoots, x1, x2);

        return 0;
        }
    }
