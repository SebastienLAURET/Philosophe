
NAME1	= philoThread

FILE1	= src/Display.cpp 	\
	src/Handler.cpp				 	\
	src/main.cpp 						\
	src/Philosophe.cpp


OBJ1	= $(FILE1:.cpp=.o)

NAME2	= philoFork

FILE2	= srcFork/Abstraction/Semaphore.cpp 	\
			srcFork/Abstraction/Fork.cpp	 				\
			srcFork/mainTable.cpp


OBJ2	= $(FILE2:.cpp=.o)


GCC	= g++

CPPFLAGS	+= -W -Wall -Wextra -std=c++11 -lncurses -pthread -I ./srcFork/Abstraction/

RM	= rm -f

all: $(NAME1) $(NAME2)


$(NAME1): $(OBJ1)
	$(GCC) -o $(NAME1) $(OBJ1) $(CPPFLAGS)

$(NAME2): $(OBJ2)
	$(GCC) -o $(NAME2) $(OBJ2) $(CPPFLAGS)

fclean:
	$(RM) $(OBJ1) $(OBJ2)

clean: fclean
	$(RM) $(NAME1) $(NAME2)

re: clean all

.PHONY: fclean clean all re base plus
