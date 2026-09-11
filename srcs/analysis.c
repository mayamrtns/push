/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araissa- <araissa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 18:47:53 by malima-m          #+#    #+#             */
/*   Updated: 2026/09/11 16:31:58 by araissa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *stack_a)
{
	double	mistakes;
	double	total_pairs;
	t_node	*index_i;
	t_node	*index_j;

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
	return (mistakes / total_pairs);
}

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
		while (index_j != NULL)
		{
			if (index_j->value < index_i->value)
			count++;
			index_j = index_j->next;
		}
		index_i->index = count;
		index_i = index_i->next;
	}
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}
