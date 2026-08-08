//Garante que a entrada não possui duplicatas, trata múltiplos argumentos e orquestra a conversão de texto para nó.
#include "push_swap.h"

int	has_duplicate(t_node *top, int number)
{
	t_node	*current;

	current = top;
	while (current != NULL)
	{
		if (current->value == number)
			return (1);
		else
			current = current->next;
	}
	return (0);
}
void	parse_args(int argc, char **argv, t_stack *stack)
{
	long value;
	t_node *new_node;
	int	i;

	i = 1;
	while (i < argc)
	{
			if (!is_number(argv[i]))
				print_error(stack);
			value = ft_atol(argv[i]);
			if (value> INT_MAX || value < INT_MIN)
				print_error(stack);
			if (has_duplicate(stack->top, (int)value))
				print_error(stack);
			new_node = create_node((int)value);
			if (!new_node)
				print_error(stack);
			add_node_back(stack, new_node);
			i++;
	}
}
