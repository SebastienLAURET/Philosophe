
NAME1	= philoThread

FILE1	= src/Display.cpp 	\
	src/Handler.cpp				 	\
	src/main.cpp 						\
	src/Philosophe.cpp


OBJ1	= $(FILE1:.cpp=.o)

NAME2	= launcher

FILE2	= srcFork/Abstraction/Semaphore.cpp 	\
				srcFork/Abstraction/Fork.cpp	 			\
				srcFork/Abstraction/Execve.cpp	 		\
				srcFork/mainTable.cpp


OBJ2	= $(FILE2:.cpp=.o)

NAME3	= philo

FILE3	= srcFork/Abstraction/Semaphore.cpp 	\
				srcFork/Philosophe.cpp							\
				srcFork/main.c


OBJ3	= $(FILE3:.cpp=.o)


GCC	= g++

CPPFLAGS	+= -W -Wall -Wextra -std=c++11 -lncurses -pthread -I ./srcFork/Abstraction/ -g3

RM	= rm -f

all: thread fork

thread: $(NAME1)

fork: $(NAME2) $(NAME3)

$(NAME1): $(OBJ1)
	$(GCC) -o $(NAME1) $(OBJ1) $(CPPFLAGS)

$(NAME2): $(OBJ2)
	$(GCC) -o $(NAME2) $(OBJ2) $(CPPFLAGS)

$(NAME3): $(OBJ3)
	$(GCC) -o $(NAME3) $(OBJ3) $(CPPFLAGS)


fclean:
	$(RM) $(OBJ1) $(OBJ2)

clean: fclean
	$(RM) $(NAME1) $(NAME2)

re: clean all

.PHONY: fclean clean all re base plus
