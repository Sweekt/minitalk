SRC_SERV	=	server.c		\
				ft_printf.c		\
				ft_printf_utils.c

SRC_CLN		=	client.c		\
				ft_printf.c		\
				ft_printf_utils.c

OBJ_SERV	=	${SRC_SERV:.c=.o}

OBJ_CLN		=	${SRC_CLN:.c=.o}

HEADER		=	minitalk.h

SERVER		=	server

CLIENT		=	client

CC			=	cc

FLAGS	=	-Wall -Wextra -Werror

all: ${CLIENT} ${SERVER}

%.o:%.c  ${HEADER}
	${CC} ${FLAGS} -c $< -o $@

${CLIENT}: ${OBJ_CLN} Makefile ${HEADER}
	${CC} ${FLAGS} ${OBJ_CLN} -o ${CLIENT}

${SERVER}: ${OBJ_SERV} Makefile ${HEADER}
	${CC} ${FLAGS} ${OBJ_SERV} -o ${SERVER}

clean:
	rm -f ${OBJ_CLN} ${OBJ_SERV}

fclean: clean
	rm -f ${CLIENT} ${SERVER}

re: fclean all

.PHONY: all clean fclean re