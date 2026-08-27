/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araissa- <araissa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 18:23:44 by araissa-          #+#    #+#             */
/*   Updated: 2026/08/27 18:23:46 by araissa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	origin_len;
	char	*str_copy;
	size_t	i;

	if (!s)
		return (NULL);
	origin_len = ft_strlen(s);
	if (start >= origin_len)
	{
		return (ft_strdup(""));
	}
	else if (len > origin_len - start)
		len = origin_len - start;
	str_copy = malloc(sizeof(char) * (len + 1));
	if (!str_copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str_copy[i] = s[start + i];
		i++;
	}
	str_copy[i] = '\0';
	return (str_copy);
}
