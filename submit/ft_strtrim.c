/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:12:27 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/21 18:50:37 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s1: La chaîne de caractères à trimmer
// set: Le set de référence de caractères à trimmer
// Retourns La chaîne de caractères trimmée, NULL si l’allocation échoue
// fonc. authorisées : malloc
// Alloue (avec malloc(3)) et retourne une copie de la chaîne ’s1’, sans les 
// caractères spécifiés
// dans ’set’ au début et à la fin de la chaîne de caractères

// 1.OK 2.MOK 3.OK 4.MOK 5.OK 6.MOK 7.OK 8.MKO ==1574627== Invalid free() / delete / delete[] / realloc()
// ==1574627==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
// ==1574627==    by 0x404A9B: main (ft_strtrim_test.cpp:33)
// ==1574627==  Address 0x4050d7 is in a r-- mapped file /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out segment
// ==1574627== 
// 9.OK 10.MKO 11.OK 12.MOK 13.OK 14.MKO 15.OK 16.MOK 

#include "libft.h"

static int	to_trim(char c, char const *set)
{
	size_t	i;

	if (c == '\0')
		return (1);
	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*new_str;
	size_t	new_str_start;
	size_t	new_str_end;

	new_str_start = 0;
	while (to_trim(s1[new_str_start], set) == 1 && s1[new_str_start] != '\0')
		new_str_start++;
	new_str_end = 0;
	new_str_end = ft_strlen(s1);
	while (to_trim(s1[new_str_end], set) == 1 && new_str_end > 0)
		new_str_end--;
	if (new_str_start > new_str_end)
		return ("");
	new_str = (char *)malloc(new_str_end - new_str_start + 2);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < new_str_end - new_str_start + 1)
	{
		new_str[i] = s1[new_str_start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
