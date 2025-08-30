#ifndef SQUARE_COMMANDS_RUN_H
#define SQUARE_COMMANDS_RUN_H

#include "SquareColors.h"
int CommandsCalled (int argc, char *argv[], colors *color);
int SquadHelp (char path[], colors color);
int CallPoltorashka (colors color);
int ColorChange (char *argv[], colors *color, int i);

#endif
