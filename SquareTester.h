#ifndef SQUARE_TESTER_H
#define SQUARE_TESTER_H

#include "SquareColors.h"
#include "SquareCommon.h"

struct CoeffSquare
    {
    double a, b, c;
    };

struct RootsSquare
    {
    double x1_ref, x2_ref;
    };


struct SquareTestData
    {
    struct CoeffSquare coeff;
    roots nRoots_ref;
    struct RootsSquare roots_ref;
    };

int OneTest (SquareTestData);

int nFailed ();

#endif
