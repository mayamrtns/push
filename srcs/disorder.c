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

