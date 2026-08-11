#include "push_swap.h"

//mede o quão "bagunçada" a pilha A está, 
// devolvendo um número entre 0.0 (perfeitamente ordenada)
//  e 1.0 (na pior ordem possível).

double	compute_disorder ( t_stack *stack_a)
{
	double mistakes;
	double total_pairs;
	t_node *index_i;
	t_node *index_j;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	index_i = stack_a->top;
	while (index_i != NULL )
	{
		index_j = index_i->next;
		while (index_j != NULL)
		{
			total_pairs += 1;
			if (index_i->value > index_j->value)
				mistakes += 1;
			index_j = index_j->next;
		}
		index_i = index_i->next;
	}
	return (mistakes/total_pairs);
}

// ela é a "tradutora" entre os valores reais que o
//  usuário digitou e os índices 0..N-1 que os
//  algoritmos de ordenação mais avançados precisam pra
//  funcionar direito.
//Pilha (valores): [  42,   -7, 1000,    3]
//Pilha (index):   [   2,    0,    3,    1]
void	index_stack(t_stack *stack_a)
{
	t_node	*index_i;
	t_node	*index_j;
	int		count;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return ;
	index_i = stack_a->top;
	while (index_i != NULL)
	{
		count = 0;
		index_j = stack_a->top;
		while(index_j != NULL)
		{
			if (index_j->value < index_i->value)
			count++;
			index_j = index_j->next;
		}
		index_i->index = count;
		index_i = index_i->next;
	}
}


