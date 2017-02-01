
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
