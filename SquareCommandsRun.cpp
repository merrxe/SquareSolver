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
    else if (!strcmp (argv[1], "--help"))
        {
        printf ("\n\n������ ��������� ������ ���������� ��������� � �������������� ������.");
        printf("\n������� ./start.exe, ����� ��������� ��������� start.exe.");
        printf("\n������� ./start.exe --help, ����� ������� ������ ��������� ������.\n");
        printf("\n������� ./start.exe --color [rm] [black] [red] [green] [yellow] [blue] [purple] [light_blue], ����� �������� ������������ �����.\n");
        return 1;
        }

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
