#include "push_swap.h"

void	sort_two(t_stack **stack_a)
{
	t_node *first;
	t_node *second;
	if (!stack_a || !(*stack_a)->top || !(*stack_a)->top->next)
		return ;
	first = (*stack_a)->top;
	second = first->next;
	if (first->value > second->value)
		sa(stack_a);
}

//sa =Troca a posição dos 2 primeiros elementos que estão no topo da stack_a.
//ra = Move o elemento do topo para o fundo da stack_a. Todos os outros elementos "sobem" uma posição.
//rra = Move o elemento do fundo para o topo da stack_a. Todos os outros elementos "descem" uma posição.
//1 -> (213) = sa
//2 -> (321) = sa e rra
//3 -> (312) = ra
//4 -> (132) = sa e ra 
//5 -> (231) = rra
void	sort_three(t_stack **stack_a)
{
	t_node *first;
	t_node *second;
	t_node *third;

	if (!stack_a || !(*stack_a)->top || !(*stack_a)->top->next || !(*stack_a)->top->next->next)
		return ;
	first = (*stack_a)->top;
	second = first->next;
	third = second->next;
	if (first->value > second->value && second->value < third->value && first->value < third->value)
		sa(stack_a);
	else if (first->value > second->value && second->value > third->value && first->value > third->value)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first->value > second->value && second->value < third->value && first->value > third->value)
		ra(stack_a);
	else if (first->value < second->value && second->value >third->value && first->value < third->value)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first->value < second->value && second->value > third->value && first->value > third->value)
		rra(stack_a);
}