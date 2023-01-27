CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
LIBFLAGS= -lSDL2_image -lSDL2_ttf -lSDL2 -I/usr/include/SDL2
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)
TST= $(wildcard *.cpp)
OBJ_TEST = $(filter-out ../main.o, $(OBJ)) $(TST:.cpp=.o)
EXEC= out

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $^ -o $@ $(LIBFLAGS)

%.o: %.cpp
	$(CC) $(CCFLAGS) -o $@ -c  $< $(LIBFLAGS)

Game : $(OBJ_TEST) 
	$(CC) $(CCFLAGS)  -o $@ $^

%.o: %.cc
	$(CC) $(CCFLAGS) -I../ -o $@ -c $<

clean :
	rm -f $(OBJ_TEST) Game
