SRCS    =	main.c \
			utils.c \
			parsing.c \
			gnl/gnl.c \
			gnl/gnl_utils.c \
			set_image.c \
			itoa.c \
			key_press.c
			
OBJ    = ${SRCS:.c=.o}
INCS    = includes
NAME    = so_long
CC        = gcc
RM        = rm -rf
CFLAGS    = -Wall -Wextra -Werror# -fsanitize=address -g

.c.o:
	$(CC) ${CFLAGS} -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) ${CFLAGS} -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re