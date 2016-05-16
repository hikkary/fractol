
NAME = fractol

SRC = 	main.c \
		error.c \
		check.c \
		julia.c  \
		image.c \
		keyboard.c \

DOTO	=		$(SRC:.c=.o)

FW = -lmlx -framework OpenGL -framework AppKit

FLAGS	= -Wall -Wextra -Werror

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(DOTO)
	make -C libft
	gcc $(FLAGS) $(FW) -lft -L ./libft -o $(NAME) $(DOTO)

%.o: %.c
	gcc -c $(FLAGS) $< -o $@

clean:
	make -C libft/ fclean
	rm -rf $(DOTO)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)