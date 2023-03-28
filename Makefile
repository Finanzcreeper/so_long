CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3
MAKEFLAGS = --no-print-directory
MLXFLAGS = ./minilibx-linux/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
NAME = so_long
SRC = so_long_test.c readin.c mlx_main.c draw.c check_map.c draw.c is_wall.c redraw.c mechanics.c load_messages.c mechanics_norme.c
aSRC = copytest.c
OBJ = $(SRC:.c=.o)

all : preplibft $(NAME)

preplibft :
	@ make -C libft

$(NAME) : $(OBJ)
	$(CC) $^ libft/*.o $(CFLAGS) $(MLXFLAGS) -o $(NAME)

clean :
	make clean -C libft
	- rm *.o

fclean : clean
	- rm $(NAME)

re : fclean all
