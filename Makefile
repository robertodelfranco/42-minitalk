SRCC_FILES = client.c
SRCS_FILES = server.c
BONUS_SRCC_FILES = client_bonus.c
BONUS_SRCS_FILES = server_bonus.c
SRC_DIR = src/
BONUS_DIR = bonus/
LIB = current_lib
LIBFT = $(LIB)/libft.a
SRCC = $(addprefix $(SRC_DIR), $(SRCC_FILES))
SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILES))
BONUS_SRCC = $(addprefix $(BONUS_DIR), $(BONUS_SRCC_FILES))
BONUS_SRCS = $(addprefix $(BONUS_DIR), $(BONUS_SRCS_FILES))
OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o}
BONUS_OBJC = ${BONUS_SRCC:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I $(LIB)/Includes
RM = rm -rf

NAMEC = client
NAMES = server
NAMEC_BONUS = client_bonus
NAMES_BONUS = server_bonus

all: $(NAMEC) $(NAMES)

$(NAMEC): $(OBJC) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJC) $(LIBFT) $(INCLUDE) -o $(NAMEC)

$(NAMES): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INCLUDE) -o $(NAMES)

bonus: $(NAMEC_BONUS) $(NAMES_BONUS)

$(NAMEC_BONUS): $(BONUS_OBJC) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJC) $(LIBFT) $(INCLUDE) -o $(NAMEC_BONUS)

$(NAMES_BONUS): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(INCLUDE) -o $(NAMES_BONUS)

$(LIBFT):
	$(MAKE) -C $(LIB)

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(BONUS_DIR)%.o: $(BONUS_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@$(MAKE) -C $(LIB) clean
	$(RM) $(OBJC) $(OBJS) $(BONUS_OBJC) $(BONUS_OBJS)

fclean: clean
	@$(MAKE) -C $(LIB) fclean
	$(RM) $(NAMEC) $(NAMES) $(NAMEC_BONUS) $(NAMES_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus