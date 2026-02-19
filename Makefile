NAME    = bsq
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I include

SRC_DIR = ./
FILES   = bsq.c main.c util.c matrix.c parser.c validator.c
SRCS    = $(addprefix $(SRC_DIR), $(FILES))
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
