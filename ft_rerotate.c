#include "push_swap.h"

void    ft_rerotate(t_stack **stack)
{
	t_node *penultimo;
	t_node	*last;

	if (!stack || !(*stack)->top || !(*stack)->top->next)
		return;
	penultimo = (*stack)->bottom->prev;
	last = (*stack)->bottom;
	last->next = (*stack)->top;
	(*stack)->top->prev = last;
	penultimo->next = NULL;
	last->prev = NULL;
	(*stack)->top = last;
	(*stack)->bottom = penultimo;
}

void	rra(t_stack **stack_a)

{
	ft_rerotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)

{
	ft_rerotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)

{
	ft_rerotate(stack_a);
	ft_rerotate(stack_b);
	write(1, "rrr\n", 4);
}