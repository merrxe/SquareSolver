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
        case NO_REAL_SOLUTION:  printf("\n��������� �� ����� �������������� �������.");
                                break;



        case NO_ROOTS:          printf("\n��������� �� ����� �������.");
                                break;



        case ONE_ROOT:          printf("\n��������� ����� ���� ������: � = %.2f.", x1);
                                break;



        case TWO_ROOTS:         printf("\n��������� ����� ��� �����: �1 = %.2f � x2 = %.2f.", x1, x2);
                                break;



        case INFINITE_ROOTS:    printf("\n��������� ����� ����������� ���������� ������.");
                                break;



        default:                printf("\nFAILED");
                                break;
        }
    printf("\n!!!COMMIT GITHUB!!!");
    }
