/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malima-m <malima-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 16:52:13 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/18 18:36:50 by malima-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_array(t_stack *stack, int *array)
{
	t_node	*current;
	int		i;

	current = stack->top;
	i = 0;
	while (current)
	{
		array[i++] = current->value;
		current = current->next;
	}
}

static int	find_index(int *sorted, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	sort_int_array(int *array, int size)
{
	int	i;
	int	j;
	int	min_idx;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
			j++;
		}
		tmp = array[i];
		array[i] = array[min_idx];
		array[min_idx] = tmp;
		i++;
	}
}

void	ft_selection_sort(t_stack *stack_a)
{
	t_node	*current;
	int		*array;

	array = malloc(sizeof(int) * stack_a->size);
	if (!array)
		return ;
	fill_array(stack_a, array);
	sort_int_array(array, stack_a->size);
	current = stack_a->top;
	while (current)
	{
		current->value = find_index(array, stack_a->size, current->value);
		current = current->next;
	}
	free(array);
}