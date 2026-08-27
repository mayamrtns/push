/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araissa- <araissa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 18:23:19 by araissa-          #+#    #+#             */
/*   Updated: 2026/08/27 18:23:21 by araissa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	size_t	i;
	size_t	j_word;
	int		words;

	i = 0;
	words = 0;
	while (s[i] != '\0' )
	{
		while (s[i] != '\0' && s[i] == c)
		i++;
		if (s[i] != '\0')
			words++;
		j_word = i;
		while (s[j_word] != '\0' && s[j_word] != c)
			j_word++;
		i = j_word;
	}
	return (words);
}

static void	*free_memory(char **matrix, size_t words)
{
	while (words > 0)
	{
		words--;
		free(matrix[words]);
	}
	free(matrix);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**word;
	size_t	limits[2];
	size_t	word_index;

	word = malloc (sizeof (char *) * (count_words(s, c) + 1));
	if (word == NULL)
		return (NULL);
	limits[1] = 0;
	word_index = 0;
	while (s[limits[1]] != '\0' )
	{
		while (s[limits[1]] != '\0' && s[limits[1]] == c)
			limits[1]++;
		if (s[limits[1]] != '\0')
		{
			limits[0] = limits[1];
			while (s[limits[1]] != '\0' && s[limits[1]] != c)
				limits[1]++;
			word[word_index++] = ft_substr(s, limits[0], limits[1] - limits[0]);
			if (word[word_index - 1] == NULL)
				return (free_memory(word, word_index - 1));
		}
	}
	word[word_index] = NULL;
	return (word);
}
