SRCNAME	=	srcs/parsing/main.c		\
			srcs/parsing/parsing.c	\

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