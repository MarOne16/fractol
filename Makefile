CC = gcc

CFLAGS = -Wall -Werror -Wextra -lmlx -framework Appkit -framework OpenGL -Ofast 

NAME = mandelbrot

HEADER = fractol.h

SCLIENT = k.c

SRC =  tools.c 

all: $(NAME) $(SERVER)

$(NAME): $(SCLIENT) $(SRC) $(HEADER)
	@$(CC) $(CFLAGS) $(SCLIENT) $(SRC) -o $@

clean:
	rm -f $(NAME) $(SERVER) $(BNAME) $(BSERVER)

fclean: clean

re: clean all