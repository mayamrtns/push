//Concentra utilitários genéricos: is_number e exibição de erros no stderr.
#include "push_swap.h"



int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	print_error(t_stack *stack)
{
	if(stack)
		free_stack(stack);
	ft_putendl_fd("Error", 2);
	exit(1);
}
