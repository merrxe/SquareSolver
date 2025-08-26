#include <TXLib.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#include "SquareOutput.h"

//????????????????????????????????????????????????
//! Output the answer of equation
//!
//! @param [in]  nRoots  The number of roots
//! @param [in]  x1      Pointer to the 1st root
//! @param [in]  x2      Pointer to the 2nd root
//????????????????????????????????????????????????
void Output (roots nRoots, double x1, double x2)
    {
    switch (nRoots)
        {
        case NO_REAL_SOLUTION:  printf("\nУравнение не имеет действительных решений.");
                                break;



        case NO_ROOTS:          printf("\nУравнение не имеет решений.");
                                break;



        case ONE_ROOT:          printf("\nУравнение имеет один корень: х = %.2f.", x1);
                                break;



        case TWO_ROOTS:         printf("\nУравнение имеет два корня: х1 = %.2f и x2 = %.2f.", x1, x2);
                                break;



        case INFINITE_ROOTS:    printf("\nУравнение имеет бесконечное количество корней.");
                                break;



        default:                printf("\nFAILED");
                                break;
        }
    printf("\n!!!COMMIT GITHUB!!!");
    }
