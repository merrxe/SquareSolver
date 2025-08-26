#include <TXLib.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "SquareCommandsRun.h"

int CommandsCalled (int argc, char *argv[])
    {
    if (argc < 2)
        {
        return 0;
        }
    else if (!strcmp (argv[1], "--help"))
        {
        printf ("\n\nДанная программа предназначена для решения квадратных уравнений в действительных числах.");
        printf("\nВведите ./start.exe, чтобы запустить программу.");
        printf("\nВведите ./start.exe --help, чтобы вывести краткое описание команды и список доступных команд.\n");
        return 1;
        }
    return 0;
    }
