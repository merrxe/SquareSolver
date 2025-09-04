CC = g++

CFLAGS = -Wshadow -Winit-self 									\
	-Wredundant-decls -Wcast-align -Wundef -Wfloat-equal 		\
	-Winline -Wunreachable-code -Wmissing-declarations 			\
	-Wmissing-include-dirs -Wswitch-enum -Wswitch-default 		\
	-Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions 		\
	-Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body 	\
	-Wformat-security -Wformat=2 -Wignored-qualifiers 			\
	-Wlogical-op -Wno-missing-field-initializers 				\
	-Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith 	\
	-Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing 			\
	-Wstrict-null-sentinel -Wtype-limits -Wwrite-strings 		\
	-Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE -IInclude

CPP = SquareMain.cpp SquareSolver.cpp SquareTester.cpp SquareCommandsRun.cpp SquareOutput.cpp SquareInput.cpp
SOURCES = $(addprefix Sources/, $(CPP))
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = start

all: prepare $(SOURCES) $(EXECUTABLE)
	@echo "Compilation complete"


$(EXECUTABLE): $(OBJECTS)
	@mv $(OBJECTS) Build/
	@$(CC) $(CFLAGS) $(addprefix Build/, $(CPP:.cpp=.o)) -o $@
	@mv *.exe Build/

prepare:
	@mkdir -p Build

.cpp.o:
	@$(CC) $(CFLAGS) -c $< -o Build/$@
