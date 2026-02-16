CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = src/
SRCS = bsq.c util.c matrix.c
OBJECTS = $(SRCS:.c=.o)
NAME = bsq

all:
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
