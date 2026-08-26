/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malima-m <malima-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 19:02:39 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/24 18:55:13 by malima-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack_a, t_context *context)
{
	t_node	*first;
	t_node	*second;

	if (!stack_a || !(*stack_a)->top || !(*stack_a)->top->next)
		return ;
	first = (*stack_a)->top;
	second = first->next;
	if (first->value > second->value)
		sa(stack_a, context);
}

//sa =Troca a posição dos 2 primeiros elementos que estão no topo da stack_a.
//ra = Move o elemento do topo para o fundo da stack_a. Todos os outros elementos "sobem" uma posição.
//rra = Move o elemento do fundo para o topo da stack_a. Todos os outros elementos "descem" uma posição.
//1 -> (213) = sa
//2 -> (321) = sa e rra
//3 -> (312) = ra
//4 -> (132) = sa e ra
//5 -> (231) = rra


void	sort_three(t_stack **a, t_context *context)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->top->value;
	second = (*a)->top->next->value;
	third = (*a)->top->next->next->value;
	if (first < second && second < third)
		return ;
	else if (first < third && third < second)
	{
		sa(a, context);
		ra(a, context);
	}
	else if (second < first && first < third)
		sa(a, context);
	else if (second < third && third < first)
		ra(a, context);
	else if (third < first && first < second)
		rra(a, context);
	else if (third < second && second < first)
	{
		sa(a, context);
		rra(a, context);
	}
}

static int	find_min_position(t_stack *a)
{
	int	i; //contador
	int	pos; //guardar a posição
	int	min;
	t_node	*actual;

	if (!a || !a->top)
		return (0);
	i = 0;
	pos = 0;
	actual = a->top;
	min = actual->value;
	while (actual)
	{
		if (actual->value < min)
		{
			min = actual->value;
			pos = i;
		}
		i++;
		actual = actual->next;
	}
	return (pos);
}

static void	move_min_to_top(t_stack **a, t_context *context)
{
	int	pos;

	pos = find_min_position(*a);
	while (pos != 0)
	{
		if (pos <= (*a)->size / 2)
			ra(a, context);
		else
			rra(a, context);
		pos = find_min_position(*a);
	}
}

void	sort_five(t_stack **a, t_stack **b, t_context *context)
{
	if (!a || !*a)
		return ;
	move_min_to_top(a, context);
	pb(a, b, context);
	move_min_to_top(a, context);
	pb(a, b, context);
	sort_three(a, context);
	pa(a, b, context);
	pa(a, b, context);
}
