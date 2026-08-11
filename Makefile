# 1. Detecta o Sistema Operacional
ifeq ($(OS),Windows_NT)
    # Configurações para Windows
    NAME        = push_swap.exe
    RM          = del /f /q
    FIXPATH     = $(subst /,\,$(1))
    NO_ERROR    = 2>nul || exit 0
else
    # Configurações para Linux / macOS
    NAME        = push_swap
    RM          = rm -f
    FIXPATH     = $(1)
    NO_ERROR    = 
endif

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -Iincludes -Ilibft

# Lista de arquivos fonte
SRC         = srcs/main.c \
              srcs/parsing.c \
              srcs/stack_utils.c \
              srcs/utils.c \
              srcs/analysis.c \
               srcs/sort_base.c \
              libft/ft_atol.c \
              libft/ft_isdigit.c \
              libft/ft_putstr_fd.c \
              libft/ft_putendl_fd.c \
              libft/ft_split.c \
              libft/ft_strdup.c \
              libft/ft_strlen.c \
              libft/ft_substr.c \
              ft_rerotate.c ft_rotate.c ft_swap.c push.c 

OBJ         = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
ifeq ($(OS),Windows_NT)
	$(RM) $(call FIXPATH,$(OBJ)) $(NO_ERROR)
else
	$(RM) $(OBJ)
endif

fclean: clean
	$(RM) $(NAME) $(NO_ERROR)

re: fclean all

# Lista de fontes de teste (igual ao SRC, mas sem srcs/main.c, com test_main.c)
TEST_SRC    = srcs/parsing.c \
              srcs/stack_utils.c \
              srcs/utils.c \
              srcs/analysis.c \
              srcs/sort_base.c \
              libft/ft_atol.c \
              libft/ft_isdigit.c \
              libft/ft_putstr_fd.c \
              libft/ft_putendl_fd.c \
              libft/ft_split.c \
              libft/ft_strdup.c \
              libft/ft_strlen.c \
              libft/ft_substr.c \
              ft_rerotate.c ft_rotate.c ft_swap.c push.c \
              test_main.c

test: $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) -o test
    
.PHONY: all clean fclean re test