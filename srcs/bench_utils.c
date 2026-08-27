/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araissa- <araissa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 16:50:54 by araissa-          #+#    #+#             */
/*   Updated: 2026/08/27 16:51:57 by araissa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*format_decimal(int dec_p)
{
	char	*decimal_part;
	char	*decimal_zero;

	if (dec_p < 0)
		dec_p = -dec_p;
	decimal_part = ft_itoa(dec_p);
	if (!decimal_part)
		return (NULL);
	if (ft_strlen(decimal_part) == 1)
	{
		decimal_zero = ft_strjoin("0", decimal_part);
		free(decimal_part);
		return (decimal_zero);
	}
	return (decimal_part);
}

static char	*join_parts(char *int_part, char *decimal_part)
{
	char	*tmp;
	char	*result;

	tmp = ft_strjoin(int_part, ".");
	free(int_part);
	if (!tmp)
		return (free(decimal_part), NULL);
	result = ft_strjoin(tmp, decimal_part);
	free(tmp);
	free(decimal_part);
	return (result);
}

char	*convert_disorder(double disorder)
{
	int		int_p;
	int		dec_p;
	char	*int_part;
	char	*decimal_part;

	int_p = (int)(disorder * 100);
	dec_p = (int)((disorder * 100 - int_p) * 100);
	int_part = ft_itoa(int_p);
	decimal_part = format_decimal(dec_p);
	if (!int_part || !decimal_part)
		return (free(int_part), free(decimal_part), NULL);
	return (join_parts(int_part, decimal_part));
}
