# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread -g

# Source files
SRC = main.c \
	  init/init.c \
	  routine/routine.c \
	  routine/actions.c \
	  routine/monitor.c \
	  utils/ft_atoi.c \
	  utils/parse_args.c \
	  utils/time.c \
	  utils/print.c \
	  utils/cleanup.c \
	  utils/error.c

# Object files
OBJ = $(SRC:.c=.o)

# Executable name
NAME = philo

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re