# push
Makefile para rodar no windows
para compilar:mingw32-make
para limpar tudo: mingw32-make fclean
mingw32-make clean
mingw32-make re

# Teste normal
.\push_swap.exe 42 13 8 -5 100

# Teste com erro (duplicados)
.\push_swap.exe 1 2 2 3

# Teste com erro (letra)
.\push_swap.exe 10 20 abc