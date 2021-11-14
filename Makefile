name = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT =	./libft/libft.a
LIBFT_DIR =	./libft

OBJ = srcs/push_swap.o srcs/pushSwapTools.o srcs/parse_args.o srcs/operations.o srcs/checkErrors.o

all: $(name)

$(name): $(LIBFT) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(name)

$(LIBFT): force
		make -C $(LIBFT_DIR)

force:

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)
fclean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)
re:
	make fclean
	make