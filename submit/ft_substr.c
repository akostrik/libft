/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:08:08 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/21 18:35:24 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s: La chaîne de laquelle extraire la nouvelle chaîne
// start: L’index de début de la nouvelle chaîne dans la chaîne s
// len: La taille maximale de la nouvelle chaîne
// Retourne la nouvelle chaîne de caractères, NULL si l’allocation échoue
// Fonctions autorisées : malloc
// Alloue (avec malloc(3)) et retourne une chaîne de caractères issue de’s’
// La nouvelle chaîne commence à l’index ’start’ et a pour taille maximale ’len’

//  : 1.OK 2.MOK 3.OK 4.MOK ==1574542== Invalid read of size 1
// ==1574542==    at 0x484FBD4: strcmp (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
// ==1574542==    by 0x404A12: main (ft_substr_test.cpp:28)
// ==1574542==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
// ==1574542== 
// 5.SIGSEGV

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	if (start >= ft_strlen(s))
		return (NULL);
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	substr = (char *)malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
