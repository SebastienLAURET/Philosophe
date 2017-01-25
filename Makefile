##
## Makefile for MAKEFILE in /home/lauret_s/rendu/PSU_2014_philo
##
## Made by Sebastien Lauret
## Login   <lauret_s@epitech.net>
##
## Started on  Mon Feb 23 20:45:08 2015 Sebastien Lauret
## Last update Fri Feb 27 11:29:54 2015 Francois Rosain
##

NAME	= philo

FILE	= src/Display.cpp \
	src/Handler.cpp \
	src/main.cpp \
	src/Philosophe.cpp


OBJ	= $(FILE:.cpp=.o)

GCC	= g++

CPPFLAGS	+= -std=c++11 -lncurses -pthread  #-W -Wall -Wextra

RM	= rm -f

all: $(NAME)


$(NAME): $(OBJ)
	$(GCC) -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean clean all re base plus
