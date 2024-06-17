SRCS    =	main.c \
			utils.c \
			parsing.c \
			gnl/gnl.c \
			gnl/gnl_utils.c \
			set_image.c \
			exit.c \
			set_image_in_game.c \
			key_press.c
			
OBJ    = ${SRCS:.c=.o}
INCS    = includes
NAME    = so_long
CC        = gcc
RM        = rm -rf
LIBFTDIR	= libft
PRINTFDIR	= printf
MINILIBDIR	= minilib
MINILIB		= ${MINILIBDIR}/libmlx.a
PRINTF		= ${PRINTFDIR}/printf.a
LIBFT		= ${LIBFTDIR}/libft.a
CFLAGS    = -Wall -Wextra -Werror -fsanitize=address -g

.c.o:
	$(CC) ${CFLAGS} -Imlx -c $< -o $@

$(NAME): $(OBJ)
	make -C $(LIBFTDIR)
	make -C ${PRINTFDIR}
	make -C ${MINILIBDIR}
	$(CC) $(OBJ) ${CFLAGS} ${LIBFT} ${PRINTF} ${MINILIB} -framework OpenGL -framework AppKit -o $(NAME)

all: ${NAME}

clean:
	make clean -C $(LIBFTDIR) 
	make clean -C ${PRINTFDIR}
	make clean -C ${MINILIBDIR}
	${RM} ${OBJ}

fclean: clean
	make fclean -C $(LIBFTDIR) 
	make fclean -C${PRINTFDIR}
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re