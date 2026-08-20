/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malima-m <malima-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:53:47 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/20 18:12:58 by malima-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_big(t_stack *stack_b)
{
	t_node	*big;
	t_node	*tmp;

	if (!stack_b || !stack_b->top)
		return (NULL); //TEM que ter o NULL pelo retorno ser t_node
	big = stack_b->top;
	tmp = stack_b->top;

	while (tmp) //enquanto tmp existe
	{
		if (tmp->index > big->index) //se o index da variavel tmp for maior que a da big, big recebe o valor de tmp e tmp segue para o próximo nó
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
	while (top && top != target) //verificando se é nulo antes de ser igual a target
	{
		k++;
		top = top->next;
	}
	return (k);
}
