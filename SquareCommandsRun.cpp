#include <string.h>
#include <TXLib.h>
#include <math.h>
#include "SquareCommandsRun.h"

int CommandsCalled (char *argv[])
    {
    if (strcmp (*argv, "--help"))
        {
        printf ("\n\nДанная программа предназначена для решения квадратных уравнений в действительных числах.");
        printf("\nВВедите ./start.exe, чтобы запустить программу.");
        printf("\nВВедите ./start.exe --help, чтобы вывести краткое описание команды и список доступных команд.\n");
        return 1;
        }
    return 0;
    }
