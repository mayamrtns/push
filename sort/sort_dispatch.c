/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dispatch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malima-m <malima-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 18:49:20 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/27 19:18:07 by malima-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_small_sort(t_context *context, t_mode mode)
{
	if (context->stack_a->size <= 1)
		return (1);
	if (context->stack_a->size == 2)
		sort_two(context);
	else if (context->stack_a->size == 3)
		sort_three(context);
	else if (context->stack_a->size <= 5)
		sort_five(context);
	else
		return (0);
	context->strategy_used = mode;
	return (1);
}