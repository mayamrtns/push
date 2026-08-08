//Valida se há argumentos suficientes, chama a inicialização da pilha, dispara o parsing e faz a limpeza ao final.
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack stack_a;
	if (argc < 2)
		return (0);
	init_stack(&stack_a);
	parse_args(argc, argv, &stack_a);
	free_stack(&stack_a);
	return (0);
}