void	ft_swap(t_stack **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (stack == NULL || *stack == NULL)
		return ;
	if ((*stack)->top == NULL || (*stack)->top->next == NULL)
		return ;
	first = (*stack)->top;
	second = first->next;
	third = second->next;
	if (third != NULL)
		third->prev = first;
	first->next = third;
	first->prev = second;
	second->prev = NULL;
	second->next = first;
	(*stack)->top = second;
}