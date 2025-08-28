#include <TXLib.h>
#include <math.h>

#include "SquareTester.h"
#include "SquareSolver.h"

//-----------------------------------------------------
//! Run the tests
//!
//! @param [out] failed The number of failed tests
//!
//! @return The number of failed tests
//-----------------------------------------------------
int nFailed ()
    {
    int failed = 0;

    SquareTestData sqTests [] =
        {
        /*ÒÅÑÒÛ ÄËß ÄÂÓÕ ÊÎĞÍÅÉ*/
        {.coeff = {.a = 1, .b = -5, .c = 6},  .nRoots_ref = TWO_ROOTS, .roots_ref = {.x1_ref = 2,  .x2_ref = 3}},
        {.coeff = {.a = 1, .b = 0,  .c = -4}, .nRoots_ref = TWO_ROOTS, .roots_ref = {.x1_ref = -2, .x2_ref = 2}},
        {.coeff = {.a = 1, .b = -5, .c = 0},  .nRoots_ref = TWO_ROOTS, .roots_ref = {.x1_ref = 0,  .x2_ref = 5}},

        /*ÒÅÑÒÛ ÄËß ÎÄÍÎÃÎ ÊÎĞÍß*/
        {.coeff = {.a = 1, .b = -10, .c = 25}, .nRoots_ref = ONE_ROOT, .roots_ref = {.x1_ref = 5,  .x2_ref = 5}},
        {.coeff = {.a = 0, .b = 5, .c = -10},  .nRoots_ref = ONE_ROOT, .roots_ref = {.x1_ref = 2,  .x2_ref = 2}},

        /*ÒÅÑÒÛ ÄËß ÎÒÑÓÒÑÒÂÈß ÄÅÉÑÒÂÈÒÅËÜÍÛÕ ÊÎĞÍÅÉ*/
        {.coeff = {.a = 100, .b = 2, .c = 100}, .nRoots_ref = NO_REAL_SOLUTION, .roots_ref = {.x1_ref = 0,  .x2_ref = 0}},

        /*ÒÅÑÒÛ ÄËß ÎÒÑÓÒÑÒÂÈß ÊÎĞÍÅÉ*/
        {.coeff = {.a = 0, .b = 0, .c = 5}, .nRoots_ref = NO_ROOTS, .roots_ref = {.x1_ref = 0,  .x2_ref = 0}},

        /*ÒÅÑÒÛ ÄËß ÁÅÑÊÎÍÅ×ÍÎÃÎ ÊÎËÈ×ÅÑÒÂÀ ĞÅØÅÍÈÉ*/
        {.coeff = {.a = 0, .b = 0, .c = 0}, .nRoots_ref = INFINITE_ROOTS, .roots_ref = {.x1_ref = 0, .x2_ref = 0}},
        };

        size_t size = sizeof (sqTests) / sizeof (SquareTestData);

        for (size_t i = 0; i < size; i++)
            {
            failed += OneTest (sqTests[i]);
            }

        return failed;
    }

//----------------------------------------------------------------
//! Run only one test and check if there are mistakes in program
//!
//! @param [in]   dataOneTest   Data from the test
//!
//! @return True or False (1 or 0)
//----------------------------------------------------------------
int OneTest (SquareTestData dataOneTest)
    {
    double x1 = 0, x2 = 0;

    double a = dataOneTest.coeff.a, b = dataOneTest.coeff.b, c = dataOneTest.coeff.c;
    roots nRoots_ref = dataOneTest.nRoots_ref;
    double x1_ref = dataOneTest.roots_ref.x1_ref, x2_ref = dataOneTest.roots_ref.x2_ref;

    int nRoots = SquareSolve (a, b, c, &x1, &x2);
    if (!(IsEqual (x1, x1_ref)  && IsEqual (x2, x2_ref) && nRoots == nRoots_ref))
        {
        printf ("Ïğîãğàììà ïğè âõîäíûõ äàííûõ a = %.2f, b = %.2f, c = %.2f ïîëó÷àåò êîğíè %.2f è %.2f, äîëæíà ïîëó÷àòü %.2f è %.2f. \n", a, b, c, x1, x2, x1_ref, x2_ref);
        return 1;
        }
    return 0;
    }
