CC = gcc
CCFLAGS = -Wall -Wextra #-Werror

RM = rm -f

NAME = ft_printf
SRC = ft_printf.c utils.c printer.c parse.c list.c extract.c
OBJ = $(SRC:.c=.o)
INCLUDE = header.h

all: $(NAME)

debug: CCFLAGS += -g -fsanitize=address
debug: re

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) -o $@ $(OBJ)

%.o: %.c $(INCLUDE)
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(OBJ)

re: fclean all
