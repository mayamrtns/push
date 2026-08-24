/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araissa- <araissa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:18:11 by araissa-          #+#    #+#             */
/*   Updated: 2026/06/02 21:01:08 by araissa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i_s1;
	size_t	i_s2;

	if (!s1 || !s2)
		return (NULL);
	result = malloc(sizeof(char) * ((ft_strlen(s1)) + (ft_strlen(s2)) + 1));
	if (result == NULL)
		return (NULL);
	i_s1 = 0;
	i_s2 = 0;
	while (s1[i_s1] != '\0')
	{
		result[i_s1] = s1[i_s1];
		i_s1++;
	}
	while (s2[i_s2] != '\0')
	{
		result[i_s1] = s2[i_s2];
		i_s1++;
		i_s2++;
	}
	result[i_s1] = '\0';
	return (result);
}
