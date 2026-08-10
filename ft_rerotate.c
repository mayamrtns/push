void    ft_rerotate(t_stack **stack)
{
	t_stack *penultimo;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return;
	penultimo = *stack;
	while (penultimo->next->next)
		penultimo = penultimo->next;
	last = penultimo->next;
	last->next = *stack;
	penultimo->next = NULL;
	*stack = last;
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