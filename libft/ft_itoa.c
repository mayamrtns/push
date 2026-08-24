/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araissa- <araissa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:20:27 by araissa-          #+#    #+#             */
/*   Updated: 2026/06/10 18:58:33 by araissa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	n_len(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*put_result(char *result, size_t i, long copy_n, int signal)
{
	result[i] = '\0';
	if (copy_n == 0)
		result[0] = '0';
	while (i > 0 && copy_n > 0)
	{
		result[i - 1] = (copy_n % 10) + '0';
		copy_n = copy_n / 10;
		i--;
	}
	if (signal == -1)
		result[0] = '-';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	i;
	long	copy_n;
	int		signal;

	i = 0;
	copy_n = n;
	signal = 1;
	if (n < 0)
	{
		copy_n = -copy_n;
		signal = -1;
	}
	i = n_len(n);
	result = malloc ((sizeof (char)) * (i + 1));
	if (result == NULL)
		return (NULL);
	return (put_result(result, i, copy_n, signal));
}
