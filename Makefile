CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
SRC= $(wildcard ../*.cpp)
OBJ= $(SRC:.cc=.o)
TST= $(wildcard *.cpp)
OBJ_TEST = $(filter-out ../main.o, $(OBJ)) $(TST:.cpp=.o)

Game : $(OBJ_TEST) 
	$(CC) $(CCFLAGS)  -o $@ $^

%.o: %.cc
	$(CC) $(CCFLAGS) -I../ -o $@ -c $<

clean :
	rm -f $(OBJ_TEST) Game
