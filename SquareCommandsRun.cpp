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
        printf ("\n\n������ ��������� ������������� ��� ������� ���������� ��������� � �������������� ������.");
        printf("\n������� ./start.exe, ����� ��������� ���������.");
        printf("\n������� ./start.exe --help, ����� ������� ������� �������� ������� � ������ ��������� ������.\n");
        return 1;
        }
    return 0;
    }
