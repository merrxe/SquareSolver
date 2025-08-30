#include <TXLib.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

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
    assert (color && argv);
    bool CommandIncorrect = false;
    int NumToReturn = 0;

    for (int i = 1; i < argc; i++)
        {
        /*�������: ������� ���������� � ��������� �� �����.*/
        if (!strcmp (argv[i], "--help"))
            {
            NumToReturn = SquadHelp (argv[0], *color);
            }

        /*�������: ������ ���� ������*/
        else if (!strcmp (argv[i], "--color"))
            {
            NumToReturn = ColorChange (argv, color, i + 1);
            }

        /*�������: ����� ����������*/
        else if (!strcmp (argv[i], "--call_poltorashka"))
            {
            NumToReturn = CallPoltorashka (*color);
            }

        /*������������ �¨� ������� �����������*/
        else if (strcmp (argv[i-1], "--color"))
            {
            CommandIncorrect = true;
            }
        }

    if (CommandIncorrect)
        {
        printf("������� �� �������.\n");
        NumToReturn = 1;
        }
    return NumToReturn;
    }

//-------------------------------------------------------------------------------------------
//! Run --help command
//!
//! @return True or false (1 or 0)
//-------------------------------------------------------------------------------------------
int SquadHelp (char path[], colors color)
    {
    char *str = strtok (path, "\\");
    char *name_exe;
    while (str != NULL)
    {
        name_exe = str;
        str = strtok (NULL, "\\");
    }
    printf ("\n\033[%dm������ ��������� ������ ���������� ��������� � �������������� ������.", color);
    printf ("\n������� ./%s, ����� ��������� ��������� ./%s.", name_exe, name_exe);
    printf ("\n������� ./%s --help, ����� ������� ���������� � ��������� �� �����.", name_exe);
    printf ("\n������� ./%s --color [black] [red] [green] [yellow] [blue] [purple] [light_blue], ����� �������� ���� ������.", name_exe);
    printf ("\n������� ./%s --call_poltorashka, ����� ������� ����������.\n", name_exe);
    return 1;
    }

//-------------------------------------------------------------------------------------------
//! Run --call_poltorashka command
//!
//! @return True or false (1 or 0)
//-------------------------------------------------------------------------------------------
int CallPoltorashka (colors color)
    {
    printf("\033[%dm  ,_     _\n", color);
    printf("  |\\_,-~/\n");
    printf(" / _  _ |     ,--.\n");
    printf("(  @  @ )   / ,-'\n");
    printf("\\  _T_/-._( (\n");
    printf("/         `. \\\n");
    printf("|         _  \\ |\n");
    printf("\\ \\ ,  /      |\n");
    printf(" || |-_\\__   /\n");
    printf("((_/`(____,-'\n");
    printf("MEOW! RTRTRTRTRTRTRTRTRTRT\n");
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
int ColorChange (char *argv[], colors *color, int i)
    {
    assert (color && argv);

    if (!strcmp (argv[i], "black"))
        {
        *color = BLACK;
        }
    else if (!strcmp (argv[i], "red"))
        {
        *color = RED;
        }
    else if (!strcmp (argv[i], "green"))
        {
        *color = GREEN;
        }
    else if (!strcmp (argv[i], "yellow"))
        {
        *color = YELLOW;
        }
    else if (!strcmp (argv[i], "blue"))
        {
        *color = BLUE;
        }
    else if (!strcmp (argv[i], "purple"))
        {
        *color = PURPLE;
        }
    else if (!strcmp (argv[i], "light_blue"))
        {
        *color = LIGHT_BLUE;
        }
    return 0;
    }
