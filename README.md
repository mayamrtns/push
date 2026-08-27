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


//sa =Troca a posição dos 2 primeiros elementos que estão no topo da stack_a.
//ra = Move o elemento do topo para o fundo da stack_a. Todos os outros elementos "sobem" uma posição.
//rra = Move o elemento do fundo para o topo da stack_a. Todos os outros elementos "descem" uma posição.
//1 -> (213) = sa
//2 -> (321) = sa e rra
//3 -> (312) = ra
//4 -> (132) = sa e ra
//5 -> (231) = rra
