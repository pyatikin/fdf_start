
NAME		=	fdf

CC			=	gcc

CFLAGS		=	

SRC			=	fdf.c

OBJ			=	$(SRC:.c=.o)

all: $(NAME)

##$(NAME): $(OBJ)
##		ar rcs $(NAME) $(OBJ)

$(NAME): $(OBJ) Makefile
	$(CC) $(OBJ)  -Llibft -lft -L. -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	
%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all