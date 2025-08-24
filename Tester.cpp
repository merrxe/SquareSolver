#include <TXLib.h>
#include <math.h>
#include "Tester.h"
#include "SquarSolver.h"

int OneTest (double a, double b, double c, roots nRoots_ref, double x1_ref, double x2_ref);


int nFailed ()
    {
    int failed = 0;
    /*ТЕСТЫ ДЛЯ ДВУХ КОРНЕЙ*/
    failed += OneTest(1, -5, 6, TWO_ROOTS, 2, 3); // ax^2 + bx + c = 0, D > 0
    failed += OneTest(1, 0, -4, TWO_ROOTS, -2, 2); // ax*2 + c = 0
    failed += OneTest(1, -5, 0, TWO_ROOTS, 0, 5); // ax^2 + bx = 0

    /*ТЕСТЫ ДЛЯ ОДНОГО КОРНЯ*/
    failed += OneTest(1, -10, 25, ONE_ROOT, 5, 5); // ax^2 + bx + c = 0, D = 0
    failed += OneTest(0, 5, -10, ONE_ROOT, 2, 2); // bx + c = 0

    /*ТЕСТ ДЛЯ ОТСУТСТВИЯ ДЕЙСТВИТЕЛЬНЫХ РЕШЕНИЙ*/
    failed += OneTest(100, 2, 100, NO_REAL_SOLUTION, 0, 0);

    /*ТЕСТ ДЛЯ ОТСУТСТВИЯ КОРНЕЙ*/
    failed += OneTest(0, 0, 5, NO_ROOTS, 0, 0);

    /*ТЕСТ ДЛЯ БЕСКОНЕЧНОГО КОЛИЧЕСТВА РЕШЕНИЙ*/
    failed += OneTest(0, 0, 0, INFINITE_ROOTS, 0, 0);

    return failed;
    }

int OneTest (double a, double b, double c, roots nRoots_ref, double x1_ref, double x2_ref)
    {
    double x1 = 0, x2 = 0;
    int nRoots = SquareSolve (a, b, c, &x1, &x2);
    if (!(IsEqual (x1, x1_ref)  && IsEqual (x2, x2_ref) && nRoots == nRoots_ref))
        {
        printf ("При решении квадратного урвнения с коэффициентами a = %.2f, b = %.2f, c = %.2f получены корни %.2f и %.2f, ожидаемые корни %.2f и %.2f. \n", a, b, c, x1, x2, x1_ref, x2_ref);
        return 1;
        }
    return 0;
    }
