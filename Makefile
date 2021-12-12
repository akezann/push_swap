NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT =	./libft/libft.a
LIBFT_DIR =	./libft
DEFS = ./includes/push_swap.h

OBJ = srcs/push_swap.o srcs/parse_args.o srcs/utils.o srcs/lis.o\
		srcs/algorithm.o srcs/algo_utils.o srcs/operations.o

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(DEFS)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT): force
		make -C $(LIBFT_DIR)

force:

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)
fclean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ) $(NAME)
re:
	make fclean
	make