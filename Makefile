CC = gcc

CFLAGS = -Wall -Werror -Wextra -lmlx -framework Appkit -framework OpenGL -O3 -ffast-math -msse4.2 -mtune=intel

NAME = fractol

HEADER = fractol.h

SRC =  tools.c maousetools.c mandelbrot.c julia.c fractolexe.c burningship.c\

all: $(NAME)

$(NAME): $(SCLIENT) $(SRC) $(HEADER)
	@$(CC) $(CFLAGS) $(SCLIENT) $(SRC) -o $@

bonus: all

clean:
	rm -f $(NAME)

fclean: clean

re: clean all