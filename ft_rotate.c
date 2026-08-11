#include "push_swap.h"

static void	ft_rotate(t_stack **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !(*stack)->top || !(*stack)->top->next)
		return;
	first = (*stack)->top;
	last = (*stack)->bottom;
	(*stack)->top = first->next;
	(*stack)->top->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	(*stack)->bottom = first;
}

void	ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
	ft_putendl_fd("ra",1);
}

void	rb(t_stack **stack_b)
{
	ft_rotate(stack_b);
	ft_putendl_fd("rb",1);
}
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putendl_fd("rr",1);
}