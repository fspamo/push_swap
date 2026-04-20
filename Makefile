NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = adp_printer.c ft_strdup.c five_or_less.c bench_parser.c benchingen.c ft_strcmp.c sqrt.c indexer_chunk.c chungus.c bit.c bubble_sort.c controls.c disorder.c ft_memcpy.c ft_so_long_atoi.c ft_split.c ft_strlen.c indexer.c input_count.c lst_helper_functions.c main.c navigator.c parsingen.c push.c rotate.c r_rotate.c swap.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
