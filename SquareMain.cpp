#include <TXLib.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "SquareMain.h"

int main (int argc, char *argv[])
    {
    colors color = NOT_COLORED;
    if (!CommandsCalled (argc, argv, &color))
        {
        /*UNIT-РЕЯРШ*/
        int failed = nFailed();
        if (failed != 0)
            {
            printf("FAILED: %d", failed);
            }

        /*оепелеммше*/
        double a, b, c, x1, x2;
        a = b = c = 0;
        x1 = x2 = 0;

        /*ббнд дюммшу*/
        Input(&a, &b, &c, color);

        /*бшбнд дюммшу*/
        roots nRoots = SquareSolve (a, b, c, &x1, &x2);
        Output(nRoots, x1, x2);

        return 0;
        }
    }
