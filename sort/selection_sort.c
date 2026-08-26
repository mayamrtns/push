/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malima-m <malima-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 16:52:13 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/20 19:58:20 by malima-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_selection_sort(t_stack **stack_a, t_stack **stack_b, t_context *context)
{
	int	size;

	if (!stack_a || !*stack_a || !(*stack_a)->top)
		return ;
	size = (*stack_a)->size;
	push_chunk(stack_a, stack_b, 0, size - 1, context);
	push_back(stack_a, stack_b, context);
}
