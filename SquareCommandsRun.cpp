#include <TXLib.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "SquareCommandsRun.h"

//-------------------------------------------------------------------------------------------
//! Check if user called any ./start.exe commands
//!
//! @param [in]   argc   The number of arguments
//! @param [in]   argv   The list of arguments
//! @param [in]   color  Text color
//!
//! @return True or false (1 or 0)
//!
//! @note There are three ./start.exe commands: --help, --color and --call_poltorashka
//-------------------------------------------------------------------------------------------
int CommandsCalled (int argc, char *argv[], colors *color)
    {
    if (argc < 2)
        {
        return 0;
        }

    /*�������: ������� ���������� � ��������� �� �����.*/
    else if (!strcmp (argv[1], "--help"))
        {
        return SquadHelp ();
        }

    /*�������: ����� ����������*/
    else if (!strcmp (argv[1], "--call_poltorashka"))
        {
        return  CallPoltorashka ();
        }

    /*�������: ������ ���� ������*/
    else if (!strcmp (argv[1], "--color"))
        {
        return ColorChange (argc, argv, color);
        }
    return 0;
    }

//-------------------------------------------------------------------------------------------
//! Run --help command
//!
//! @return True or false (1 or 0)
//-------------------------------------------------------------------------------------------
int SquadHelp ()
    {
    printf ("\n������ ��������� ������ ���������� ��������� � �������������� ������.");
    printf ("\n������� ./start.exe, ����� ��������� ��������� start.exe.");
    printf ("\n������� ./start.exe --help, ����� ������� ���������� � ��������� �� �����.");
    printf ("\n������� ./start.exe --color [black] [red] [green] [yellow] [blue] [purple] [light_blue], ����� �������� ���� ������.");
    printf ("\n������� ./start.exe --call_poltorashka, ����� ������� ����������.\n");
    return 1;
    }

//-------------------------------------------------------------------------------------------
//! Run --call_poltorashka command
//!
//! @return True or false (1 or 0)
//-------------------------------------------------------------------------------------------
int CallPoltorashka ()
    {
    printf(" ,_     _\n");
    printf(" |\\_,-~/\n");
    printf(" / _  _ |     ,--.\n");
    printf("(  @  @ )   / ,-'\n");
    printf("\\  _T_/-._( (\n");
    printf("/         `. \\\n");
    printf("|         _  \\ |\n");
    printf("\\ \\ ,  /      |\n");
    printf(" || |-_\\__   /\n");
    printf("((_/`(____,-'\n");
    printf("MEOW! RTRTRTRTRTRTRTRTRTRT");
    return 1;
    }

//-------------------------------------------------------------------------------------------
//! Run --color command
//!
//! @param [in]   argc   The number of arguments
//! @param [in]   argv   The list of arguments
//! @param [in]   color  Text color
//!
//! @return True or false (1 or 0)
//-------------------------------------------------------------------------------------------
int ColorChange (int argc, char *argv[], colors *color)
    {
    if (argc == 2)
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
