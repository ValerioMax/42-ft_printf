NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC_FILES = ft_printf.c ft_printf_utils1.c ft_printf_utils2.c

OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re