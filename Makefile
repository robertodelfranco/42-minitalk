SRC_CLIENT	= client.c
SRC_SERVER	= server.c

OBJ_CLIENT	= $(SRC_CLIENT:.c=.o)
OBJ_SERVER	= $(SRC_SERVER:.c=.o)

LIBFT	= ./current_lib
LIB		=	$(LIBFT)/libft.a

NAME	= minitalk

HEADER	= -I ${LIBFT}/Includes

CC		= gcc
RM		= rm -f

CFLAGS 	= -Wall -Wextra -Werror

all:	${NAME}

%.o:%.c
	${CC} ${CFLAGS} ${HEADER} -o $@ -c $<

${NAME}: libft server client

libft:
	@echo "compiling libft"
	@make -C ${LIBFT}

client:	client.o
	${CC} ${OBJ_CLIENT} ${LIB} ${HEADER} -o client

server:	server.o
	${CC} ${OBJ_SERVER} ${LIB} ${HEADER} -o server

clean:
	@rm -rf ${OBJ_CLIENT} ${OBJ_SERVER}
	@echo "clean objs files"
	@$(MAKE) -C $(LIBFT) clean

fclean:	clean
	@rm -rf server client
	@echo "clean library"
	@$(MAKE) -C $(LIBFT) fclean

re:	fclean all

.PHONY: all clean fclean re libft