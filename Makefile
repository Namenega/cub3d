SRCNAME =	includes/get_next_line/get_next_line.c		\
			includes/get_next_line/get_next_line_utils.c\
			srcs/main/main.c							\
			srcs/main/free.c							\
			srcs/main/bmp.c								\
			srcs/main/event.c							\
			srcs/parsing/parsing.c						\
			srcs/parsing/parsing2.c						\
			srcs/parsing/resolution.c					\
			srcs/parsing/sprites_path/obstacle.c		\
			srcs/parsing/sprites_path/directions.c		\
			srcs/parsing/sky.c							\
			srcs/parsing/ground.c						\
			srcs/parsing/map_parsing/map.c				\
			srcs/parsing/map_parsing/verif_map.c		\
			srcs/utils/lib_functions_1.c				\
			srcs/utils/lib_functions_2.c				\
			srcs/utils/utils_2.c						\
			srcs/visual/affichage.c						\
			srcs/visual/init_struct.c					\
			srcs/visual/texture.c						\
			srcs/visual/sprite.c						\
			srcs/visual/movement.c						\
			srcs/visual/movement_2.c					\

SRCS	= ${SRCNAME}

OBJS	= ${SRCS:.c=.o}

NAME	= cub3D

CC		= gcc -g -fsanitize=address
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -I. -I./includes/libft

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		make -C includes/mlx
		make -C includes/libft
		cp includes/mlx/libmlx.dylib .
		${CC} -o ${NAME} ${OBJS} -L./includes/libft -lft -L. -lmlx -framework OpenGL -framework AppKit

all: 		${NAME}

clean:
			make -C includes/mlx clean
			${RM} ${OBJS} ${NAME}

fclean:		clean
			rm -f libmlx.dylib
			rm -f screen.bmp
			${RM} ${NAME}

re:		fclean all

c:		all clean

.PHONY:		clean fclean re all bonus