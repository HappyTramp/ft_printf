LIBFT_ROOT = ./libft

CC = gcc
CCFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L. -lftprintf
INCFLAGS = -I$(LIBFT_ROOT)

RM = rm -f
LIB = ar rcs
MAKE = make -j4

NAME = libftprintf.a
SRC = ft_printf.c utils.c printer.c parse.c list.c extract.c
OBJ = $(SRC:.c=.o)
INCLUDE = header.h

all: libft_all $(NAME)

$(NAME): $(OBJ)
	cp $(LIBFT_ROOT)/libft.a $(NAME)
	$(LIB) $(NAME) $(OBJ)

%.o: %.c $(INCLUDE)
	$(CC) $(CCFLAGS) $(INCFLAGS) -c -o $@ $<

bonus: all

clean: libft_clean
	$(RM) $(OBJ)

fclean: libft_fclean clean
	$(RM) $(NAME)

re: fclean all

test: all
	$(CC) $(CCFLAGS) $(LDFLAGS) $(INCFLAGS) -o test main.c


libft_all:
	$(MAKE) -C $(LIBFT_ROOT) all

libft_bonus:
	$(MAKE) -C $(LIBFT_ROOT) bonus

libft_clean:
	$(MAKE) -C $(LIBFT_ROOT) clean

libft_fclean:
	$(MAKE) -C $(LIBFT_ROOT) fclean
