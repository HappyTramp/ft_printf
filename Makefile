CC = gcc
CCFLAGS = -Wall -Wextra #-Werror

RM = rm -f

NAME = ft_printf
SRC = ft_printf.c utils.c printer.c parse.c list.c
OBJ = $(SRC:.c=.o)
INCLUDE = header.h

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(CCFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(OBJ)

re: fclean all
