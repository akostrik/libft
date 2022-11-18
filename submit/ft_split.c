/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:47:09 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/18 18:23:13 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s: La chaîne de caractères à découper
// c: Le caractère délimiteur
// Return Le tableau de nouvelles chaînes de caractères résultant du découpage
// Return NULL si l’allocation échoue
// fonctions autorisées : malloc, free
// Alloue (avec malloc(3)) et retourne un tableau de chaînes de caractères 
// obtenu en séparant ’s’ à l’aide du caractère ’c’, utilisé comme délimiteur
// Le tableau doit être terminé par NULL

// free no used ???

/*
ft_split        : 1.MKO 2.OK 3.MOK 4.OK 5.MOK 6.OK ==1574672== Invalid write of size 8
==1574672==    at 0x40525B: ft_split (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
==1574672==    by 0x404A58: main (ft_split_test.cpp:38)
==1574672==  Address 0x4de5198 is 0 bytes after a block of size 8 alloc'd
==1574672==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1574672==    by 0x40538A: tab_allocation (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
==1574672==    by 0x40516E: ft_split (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
==1574672==    by 0x404A58: main (ft_split_test.cpp:38)
==1574672== 
7.OK ==1574672== Invalid read of size 8
==1574672==    at 0x404A8E: main (ft_split_test.cpp:40)
==1574672==  Address 0x4de5198 is 0 bytes after a block of size 8 alloc'd
==1574672==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1574672==    by 0x40538A: tab_allocation (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
==1574672==    by 0x40516E: ft_split (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
==1574672==    by 0x404A58: main (ft_split_test.cpp:38)
==1574672== 
8.OK ==1574672== Invalid read of size 8
==1574672==    at 0x40483B: freeTab(char**) (ft_split_test.cpp:15)
==1574672==    by 0x404AAC: main (ft_split_test.cpp:41)
==1574672==  Address 0x4de5198 is 0 bytes after a block of size 8 alloc'd
==1574672==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1574672==    by 0x40538A: tab_allocation (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
==1574672==    by 0x40516E: ft_split (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
==1574672==    by 0x404A58: main (ft_split_test.cpp:38)
==1574672== 
9.OK 10.OK ==1574672== Invalid write of size 8
==1574672==    at 0x40525B: ft_split (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
==1574672==    by 0x404B88: main (ft_split_test.cpp:52)
==1574672==  Address 0x4de5328 is 0 bytes after a block of size 8 alloc'd
==1574672==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1574672==    by 0x40538A: tab_allocation (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
==1574672==    by 0x40516E: ft_split (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
==1574672==    by 0x404B88: main (ft_split_test.cpp:52)
==1574672== 
11.MKO 12.OK ==1574672== Invalid read of size 8
==1574672==    at 0x404BCF: main (ft_split_test.cpp:55)
==1574672==  Address 0x4de5328 is 0 bytes after a block of size 8 alloc'd
==1574672==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1574672==    by 0x40538A: tab_allocation (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
==1574672==    by 0x40516E: ft_split (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
==1574672==    by 0x404B88: main (ft_split_test.cpp:52)
==1574672== 
13.OK ==1574672== Invalid read of size 8
==1574672==    at 0x40483B: freeTab(char**) (ft_split_test.cpp:15)
==1574672==    by 0x404BED: main (ft_split_test.cpp:56)
==1574672==  Address 0x4de5328 is 0 bytes after a block of size 8 alloc'd
==1574672==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1574672==    by 0x40538A: tab_allocation (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
==1574672==    by 0x40516E: ft_split (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
==1574672==    by 0x404B88: main (ft_split_test.cpp:52)
==1574672== 
14.MOK 15.OK ==1574672== Invalid write of size 8
==1574672==    at 0x40525B: ft_split (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
==1574672==    by 0x404C6F: main (ft_split_test.cpp:65)
==1574672==  Address 0x4de5508 is 0 bytes after a block of size 8 alloc'd
==1574672==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1574672==    by 0x40538A: tab_allocation (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
==1574672==    by 0x40516E: ft_split (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
==1574672==    by 0x404C6F: main (ft_split_test.cpp:65)
==1574672== 
16.MKO 17.OK ==1574672== Invalid read of size 8
==1574672==    at 0x404CB6: main (ft_split_test.cpp:68)
==1574672==  Address 0x4de5508 is 0 bytes after a block of size 8 alloc'd
==1574672==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1574672==    by 0x40538A: tab_allocation (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
==1574672==    by 0x40516E: ft_split (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
==1574672==    by 0x404C6F: main (ft_split_test.cpp:65)
==1574672== 
18.OK ==1574672== Invalid read of size 8
==1574672==    at 0x40483B: freeTab(char**) (ft_split_test.cpp:15)
==1574672==    by 0x404CE0: main (ft_split_test.cpp:69)
==1574672==  Address 0x4de5508 is 0 bytes after a block of size 8 alloc'd
==1574672==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1574672==    by 0x40538A: tab_allocation (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
==1574672==    by 0x40516E: ft_split (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
==1574672==    by 0x404C6F: main (ft_split_test.cpp:65)
==1574672== 
19.MOK 20.OK 21.OK 22.MOK 23.OK 24.OK 25.MKO 26.OK 27.MOK 28.OK 29.MOK 30.OK 31.MOK 32.OK 33.MOK 34.OK 35.MOK 36.OK 37.MOK 38.OK 39.MOK 40.OK 41.MOK 42.OK 
*/

#include "libft.h"

static char	**tab_allocation(const char *s, char c)
{
	int		nb_substrings;
	char	**tab;
	size_t	i; // changes

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

static size_t	calc_length(int i, const char *s, char c, int separator_or_not) // changes size_t
{
	size_t	length;

	length = 0;
	while (s[i] != '\0' && (s[i] == c) == separator_or_not)
	{
		i++;
		length++;
	}
	return (length);
}

static char	*next_substring(const char *s, size_t first_pos_substr, size_t substr_len)
{
	size_t	i; // changes int
	char	*substr;

	substr = (char *)malloc((substr_len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < substr_len)
	{
		substr[i] = s[first_pos_substr + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	num_word; // changes int size_t
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
		length = calc_length(i, s, c, 0); // убрать один аргумент
		tab[num_word] = next_substring(s, i, length);
		if (tab[num_word] == NULL)
			return (NULL);
		i += length;
		num_word++;
	}
	tab[num_word] = NULL;
	return (tab);
}
