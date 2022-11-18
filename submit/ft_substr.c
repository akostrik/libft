/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:08:08 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/18 18:18:44 by akostrik         ###   ########.fr       */
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

//  : 1.OK 2.MOK 3.OK 4.MOK ==1574542== Invalid read of size 1
// ==1574542==    at 0x484FBD4: strcmp (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
// ==1574542==    by 0x404A12: main (ft_substr_test.cpp:28)
// ==1574542==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
// ==1574542== 
// 5.SIGSEGV

// char * s = ft_substr("tripouille", 0, 42000);
// 1) check(!strcmp(s, "tripouille"));
// 2) mcheck(s, strlen("tripouille") + 1); free(s); showLeaks();
// s = ft_substr("tripouille", 1, 1);
// 3) check(!strcmp(s, "r"));
// 4) mcheck(s, 2); free(s); showLeaks();
// s = ft_substr("tripouille", 100, 1);
// 5) check(!strcmp(s, ""));

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
