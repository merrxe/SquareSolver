#include <TXLib.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "SquareCommandsRun.h"

int CommandsCalled (int argc, char *argv[], colors *color)
    {
    if (argc < 2)
        {
        return 0;
        }

    /*ÊÎÌÀÍÄÀ: ÂÛÂÎÄÈÒ ÈÍÔÎÐÌÀÖÈÞ Î ÏÐÎÃÐÀÌÌÅ ÍÀ ÝÊÐÀÍ.*/
    else if (!strcmp (argv[1], "--help"))
        {
        printf ("\n\nÄàííàÿ ïðîãðàììà ðåøàåò êâàäðàòíîå óðàâíåíèå â äåéñòâèòåëüíûõ ÷èñëàõ.");
        printf("\nÂâåäèòå ./start.exe, ÷òîáû çàïóñòèòü ïðîãðàììó start.exe.");
        printf("\nÂâåäèòå ./start.exe --help, ÷òîáû âûâåñòè èíôîðìàöèþ î ïðîãðàììå íà ýêðàí.\n");
        printf("\nÂâåäèòå  ./start.exe --color [rm] [black] [red] [green] [yellow] [blue] [purple] [light_blue], ÷òîáû èçìåíèòü öâåò òåêñòà.\n");
        return 1;
        }

    /*ÏÐÎÃÐÀÌÌÀ: ÌÅÍßÅÒ ÖÂÅÒ ÒÅÊÑÒÀ*/
    else if (!strcmp (argv[1], "--color"))
        {
        if (argc == 2)
            {
            *color = NOT_COLORED;
            }
        else if (!strcmp (argv[2], "rm"))
            {
            *color = NOT_COLORED;
            }
        else if (!strcmp (argv[2], "black"))
            {
            *color = BLACK;
            }
        else if (!strcmp (argv[2], "red"))
            {
            *color = RED;
            }
        else if (!strcmp (argv[2], "green"))
            {
            *color = GREEN;
            }
        else if (!strcmp (argv[2], "yellow"))
            {
            *color = YELLOW;
            }
        else if (!strcmp (argv[2], "blue"))
            {
            *color = BLUE;
            }
        else if (!strcmp (argv[2], "purple"))
            {
            *color = PURPLE;
            }
        else if (!strcmp (argv[2], "light_blue"))
            {
            *color = LIGHT_BLUE;
            }

        return 0;
        }
    return 0;
    }

//colors ColorChoice ()
