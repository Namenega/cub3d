SRCNAME	=	srcs/parsing/main.c							\
			srcs/parsing/parsing.c						\
			srcs/parsing/getting_data.c					\
			srcs/parsing/free.c							\
			srcs/utils/lib_functions_1.c				\
			srcs/utils/lib_functions_2.c				\
			srcs/get_next_line/get_next_line.c			\
			srcs/get_next_line/get_next_line_utils.c	\

SRCS	= ${SRCNAME}

OBJS	= ${SRCS:.c=.o}

NAME	= Cub3D

CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -I.

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		make -C includes/mlx
		cp includes/mlx/libmlx.dylib .
		${CC} -o ${NAME} ${OBJS} -L. -lmlx -framework OpenGL -framework AppKit

all: 		${NAME}

clean:
			make -C includes/mlx clean
			${RM} ${OBJS} ${NAME}

fclean:		clean
			rm -f libmlx.dylib
			${RM} ${NAME}

re:		fclean all

c:		all clean

.PHONY:		clean fclean re all bonus