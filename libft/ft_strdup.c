#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len_s1;
	char	*copy;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	len_s1 = i;
	copy = malloc(sizeof(char) * (len_s1 + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
