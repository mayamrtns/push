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
SRC = srcs/main.c \
	srcs/parsing.c \
	srcs/stack_utils.c \
	srcs/utils.c \
	srcs/analysis.c \
	srcs/bench_utils.c \
	srcs/bench_print.c \
	srcs/bench_strategy.c \
	srcs/main_utils.c \
	libft/ft_atol.c \
	libft/ft_isdigit.c \
	libft/ft_putstr_fd.c \
	libft/ft_putendl_fd.c \
	libft/ft_split.c \
	libft/ft_strdup.c \
	libft/ft_strlen.c \
	libft/ft_substr.c \
	libft/ft_strncmp.c\
	libft/ft_itoa.c \
	libft/ft_strjoin.c \
	operations/ft_rerotate.c\
	operations/ft_rotate.c\
	operations/ft_swap.c\
	operations/ft_push.c\
	sort/chunk_sort.c\
	sort/chunk_utils.c\
	sort/selection_sort.c\
	sort/sort_dispatch.c\
	sort/sort_base.c\
	sort/radix_sort.c\
	sort/adaptive_sort.c


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
TEST_SRC    = srcs/main.c \
	srcs/parsing.c \
	srcs/stack_utils.c \
	srcs/utils.c \
	srcs/analysis.c \
	srcs/bench_utils.c \
	srcs/bench_print.c \
	srcs/bench_strategy.c \
	srcs/main_utils.c \
	libft/ft_atol.c \
	libft/ft_isdigit.c \
	libft/ft_putstr_fd.c \
	libft/ft_putendl_fd.c \
	libft/ft_split.c \
	libft/ft_strdup.c \
	libft/ft_strlen.c \
	libft/ft_substr.c \
	libft/ft_strncmp.c\
	libft/ft_itoa.c \
	libft/ft_strjoin.c \
	operations/ft_rerotate.c\
	operations/ft_rotate.c\
	operations/ft_swap.c\
	operations/ft_push.c\
	sort/chunk_sort.c\
	sort/chunk_utils.c\
	sort/selection_sort.c\
	sort/sort_base.c\
	sort/radix_sort.c\
	sort/adaptive_sort.c

test: $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) -o test

.PHONY: all clean fclean re test