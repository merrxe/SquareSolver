#include <TXLib.h>
#include <math.h>
#include <stdlib.h>

#include "SquareMain.h"

//-------------------------------------------------------
int main (int argc, char *argv[])
    {
    /**txCreateWindow (GetSystemMetrics (SM_CXSCREEN) / 2, GetSystemMetrics (SM_CYSCREEN) / 2);

    txSetColor (TX_LIGHTGREEN);
    txSetFillColor (TX_LIGHTGREEN);
    for (double x = -100; x <= +100; x += 0.001)
        {
        double y = sin (x);

        txCircle (x*10 + txGetExtentX()/2, -y*100 + txGetExtentY()/2, 1);
        }**/

    colors color = NOT_COLORED;
    if (!CommandsCalled (argc, argv, &color))
        {

        #ifdef _DEBUG
        /*UNIT-ÒÅÑÒÛ*/
        int failed = nFailed();
        if (failed != 0)
            {
            printf("FAILED: %d", failed);
            }
        #endif

        /*ÈÍÈÖÈÀËÈÇÀÖÈß ÏÅÐÅÌÅÍÍÛÕ*/
        double a, b, c, x1, x2;
        a = b = c = 0;
        x1 = x2 = NAN;

        /*ÂÂÎÄ ÊÎÝÔÔÈÖÈÅÍÒÎÂ*/
        Input(&a, &b, &c, color);

        /*ÂÛÂÎÄ ÊÎÐÍÅÉ*/
        roots nRoots = SquareSolve (a, b, c, &x1, &x2);
        Output(nRoots, x1, x2);

        return 0;
        }
    }
//-------------------------------------------------------
