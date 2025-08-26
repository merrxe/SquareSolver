#include <TXLib.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#include "SquareOutput.h"

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
