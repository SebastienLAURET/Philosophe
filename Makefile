##
## Makefile for MAKEFILE in /home/lauret_s/rendu/PSU_2014_philo
##
## Made by Sebastien Lauret
## Login   <lauret_s@epitech.net>
##
## Started on  Mon Feb 23 20:45:08 2015 Sebastien Lauret
## Last update Fri Feb 27 11:29:54 2015 Francois Rosain
##

NAME1	= philo

NAME2	= philo_graph

FILE1	= src/main.c \
	  src/philo.c \
	  src/handler.c

FILE2	= src_graphique/main.c \
	  src_graphique/simulator.c \
	  src_graphique/handler_1.c \
	  src_graphique/handler_2.c

OBJ1	= $(FILE1:.c=.o)

OBJ2	= $(FILE2:.c=.o)

GCC	= gcc

CFLAGS	+= -lncurses -pthread -W -Wall -Wextra

CFLAGS	+= `pkg-config --cflags --libs gtk+-2.0`

RM	= rm -f

all: $(NAME1) $(NAME2)

base: $(NAME1)

plus: $(NAME2)

$(NAME1): $(OBJ1)
	$(GCC) -o $(NAME1) $(OBJ1) $(CFLAGS)

$(NAME2):
	$(GCC) $(CFLAGS) $(FILE2) -o $(NAME2)

clean:
	$(RM) $(OBJ1) $(OBJ2)

fclean: clean
	$(RM) $(NAME1) $(NAME2)

re: fclean all

.PHONY: fclean clean all re base plus
