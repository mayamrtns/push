/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malima-m <malima-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 18:40:07 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/18 18:29:02 by malima-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **src, t_stack **dst)
{
	t_node	*tmp;

	if (!src || !(*src)->top)
		return;
	tmp = (*src)->top;
	(*src)->top = tmp->next;
	if ((*src)->top)
		(*src)->top->prev = NULL;
	else
		(*src)->bottom = NULL;
	tmp->next = (*dst)->top;
	if ((*dst)->top)
		(*dst)->top->prev = tmp;
	else
		(*dst)->bottom = tmp;
	(*dst)->top = tmp;
	(*src)->size--;
	(*dst)->size++;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
