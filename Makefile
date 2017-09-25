COMPILLER = g++
FLAGS = -std=c++11 -Wall -Werror -Wno-sign-compare -Wno-unused-result
FILES = figure_main.cpp figure_pentagon.cpp figure_hexagon.cpp figure_octagon.cpp
NAME = main

all:
	$(COMPILLER) $(FLAGS) -o $(NAME) $(FILES)

clean:
	rm -f *.o $(NAME)
