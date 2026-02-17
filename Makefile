CC = cc
CFLAGS = -g
SRC = src/
SRCS = bsq.c main.c util.c matrix.c parser.c validator.c
OBJECTS = $(SRCS:.c=.o)
NAME = bsq

all:
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
