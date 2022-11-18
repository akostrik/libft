/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:08:08 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/18 15:24:59 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s: La chaîne de laquelle extraire la nouvelle chaîne
// start: L’index de début de la nouvelle chaîne dans la chaîne s
// len: La taille maximale de la nouvelle chaîne
// Retourne la nouvelle chaîne de caractères, NULL si l’allocation échoue
// Fonctions autorisées : malloc
// Alloue (avec malloc(3)) et retourne une chaîne de caractères issue de’s’
// Cette nouvelle chaîne commence à l’index ’start’ 
// et a pour taille maximale ’len’

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_length;
	char	*new_str;
	size_t	new_str_length;

	s_length = 0;
	while (s[s_length] != '\0')
		s_length++;
	if (start >= s_length)
		return (NULL);
	new_str_length = 0;
	while (s[start + new_str_length] != '\0' && new_str_length < len)
		new_str_length++;
	new_str = (char *)malloc(new_str_length + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < new_str_length)
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
