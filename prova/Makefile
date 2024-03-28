NAME = libftprintf

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC_FILES = ft_printf.c ft_printf_utils.c

OBJ_FILES = $(SRC_FILES:.c=.o)

INCLUDES	=	-I includes -I $(LIBFT_DIR)/includes/

LIBFT		=	$(LIBFT_DIR)libft.a
LIBFT_DIR	=	libft/
LIB_FLAGS	=	-L $(LIBFT_DIR) -lft

$(LIBFT):
			make -C $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIB_FLAGS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re