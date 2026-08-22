/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malima-m <malima-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 19:02:39 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/20 18:21:23 by malima-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack_a)
{
	t_node	*first;
	t_node	*second;

	if (!stack_a || !(*stack_a)->top || !(*stack_a)->top->next)
		return ;
	first = (*stack_a)->top;
	second = first->next;
	if (first->value > second->value)
		sa(stack_a);
}

//sa =Troca a posição dos 2 primeiros elementos que estão no topo da stack_a.
//ra = Move o elemento do topo para o fundo da stack_a. Todos os outros elementos "sobem" uma posição.
//rra = Move o elemento do fundo para o topo da stack_a. Todos os outros elementos "descem" uma posição.
//1 -> (213) = sa
//2 -> (321) = sa e rra
//3 -> (312) = ra
//4 -> (132) = sa e ra
//5 -> (231) = rra


void	sort_three(t_stack **a)
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
		sa(a);
		rra(a);
	}
	else if (second < first && first < third)
		sa(a);
	else if (second < third && third < first)
		rra(a);
	else if (third < first && first < second)
		ra(a);
	else if (third < second && second < first)
	{
		sa(a);
		rra(a);
	}
}

// static int	find_min_position(t_stack *a)
// {

// }