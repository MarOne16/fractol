CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra -lmlx -framework Appkit -framework OpenGL -O3

NAME = fractol
NAME2 = fractol_bonus

HEADER = fractol.h

SRC =  tools.c maousetools.c mandelbrot.c julia.c fractolexe.c burningship.c\

SRCB =  tools.c maousetools.c mandelbrot.c julia.c fractolbonus.c burningship.c\

all: $(NAME)

$(NAME): $(SRC) $(HEADER)
	@$(CC) $(CFLAGS) $(SRC) -o $@

bonus: $(NAME2)

$(NAME2): $(SRC) $(HEADER)
	@$(CC) $(CFLAGS) $(SRCB) -o $@

clean:
	@$(RM) $(NAME) $(NAME2)

fclean: clean

re: fclean all