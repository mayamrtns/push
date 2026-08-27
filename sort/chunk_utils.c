/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araissa- <araissa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:53:47 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/27 17:45:37 by araissa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_big(t_stack *stack_b)
{
	t_node	*big;
	t_node	*tmp;

	if (!stack_b || !stack_b->top)
		return (NULL);
	big = stack_b->top;
	tmp = stack_b->top;
	while (tmp)
	{
		if (tmp->index > big->index)
			big = tmp;
		tmp = tmp->next;
	}
	return (big);
}

int	get_position(t_node *top, t_node *target)
{
	int	k;

	if (!top || !target)
		return (-1);
	k = 0;
	while (top && top != target)
	{
		k++;
		top = top->next;
	}
	return (k);
}
