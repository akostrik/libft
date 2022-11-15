
// s: La chaîne de caractères à découper
// c: Le caractère délimiteur
// Return Le tableau de nouvelles chaînes de caractères résultant du découpage
// Return NULL si l’allocation échoue
// fonctions autorisées : malloc, free
// Alloue (avec malloc(3)) et retourne un tableau de chaînes de caractères obtenu en séparant ’s’ à l’aide du caractère ’c’, utilisé comme délimiteur
// Le tableau doit être terminé par NULL

// free no used ???

#include <stdlib.h>

static char	**tab_allocation(const char *s, char c)
{
	int		nb_substrings;
	char	**tab;
	int		i;

	i = 0;
	nb_substrings = 0;
	while (1)
	{
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != '\0' && s[i] == c)
			i++;
		nb_substrings++;
	}
	tab = (char **)malloc((nb_substrings + 1) * sizeof(char *)); 
	if (tab == NULL)
		return (NULL);
	return (tab);
}

static int	calc_length(int i, const char *s, char c, int separator_or_not)
{
	int	length;

	length = 0;
	while (s[i] != '\0' && (s[i] == c) == separator_or_not)
	{
		i++;
		length++;
	}
	return (length);
}

static char	*next_substring(const char *s, int first_pos_substring, int substr_length)
{
	int		i;
	char	*substring;

	substring = (char *)malloc((substr_length + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	i = 0;
	while (i < substr_length)
	{
		substring[i] = s[first_pos_substring + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

char **ft_split(char const *s, char c)
{
	char	  **tab;
	int		  num_word;
	size_t	length;
	size_t	i;

	tab = tab_allocation(s, c);
	if (tab == NULL)
		return (NULL);
	num_word = 0;
	i = 0;
	while (1)
	{
		length = calc_length(i, s, c, 1);
		i += length;
		if (s[i] == '\0')
			break ;
		length = calc_length(i, s, c, 0);
		tab[num_word] = next_substring(s, i, length);
		if (tab[num_word] == NULL)
			return (NULL);
		i += length;
		num_word++;
	}
	tab[num_word] = NULL;
	return (tab);
}

