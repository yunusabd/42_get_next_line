NAME = get_next_line
CC = gcc
FLAGS = -Wall -Werror -Wextra
FILES = *.c
LIBFT = libft/*.c
FT_C = $(patsubst %,%.c,$(FILES))
OBJ = $(patsubst %,%.o,$(FILES))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(FILES) $(LIBFT)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
