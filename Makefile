NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

AR = ar

ARFLAGS = rsc

SRC = ft_printf.c ft_forunsigned.c ft_hexup.c \
		ft_printhexa.c ft_putadr.c ft_putnbr.c \
		ft_putchar.c ft_putstr.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c ft_printf.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : clean fclean re all