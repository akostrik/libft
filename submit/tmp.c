#include "libft.h"

char	*tmp(const char *s, int c)
{
	size_t	i;

	if (c == '\0')
		return ((char *)&(s[ft_strlen(s)]));
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(&s[i]));
		i++;
	}
	return (NULL);
}
