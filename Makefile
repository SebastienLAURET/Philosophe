NAME	= philo

FILE	= main.c

OBJ	= $(FILE:.c=.o)

GCC	= gcc -pthread  -W -Wall -Wextra  -o

RM	= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) $(NAME) $(FILE)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
