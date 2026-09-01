
NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror


SRC = ft_atol.c \
	ft_isdigit.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_split.c \
	ft_strdup.c \
	ft_strlen.c \
	ft_substr.c \
	ft_strncmp.c\
	ft_itoa.c \
	ft_strjoin.c


OBJ = $(SRC:.c=.o)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


all: $(NAME)


$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)


clean:
	rm -f $(OBJ)


fclean: clean
	rm -f $(NAME)


re: fclean all


.PHONY: all clean fclean re