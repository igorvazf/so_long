NAME = libft.a
CC = clang
CFLAGS = -Wall -Wextra -Werror
SRC =	ft_strdup.c \
		ft_strjoin.c \
		ft_substr.c \
		ft_strlen.c \
		ft_split.c \
		ft_itoa.c \
		get_next_line.c

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
