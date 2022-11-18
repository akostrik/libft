/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:51:51 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/18 18:23:48 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// n: l’entier à convertir
// Retournr la chaîne de caractères représentant l’entier
// Retourne NULL si l’allocation échoue
// fonctions authorisées : malloc
// Alloue (avec malloc(3)) et retourne une chaîne de caractères représentant 
// l’entier ’n’ reçu en argument
// Les nombres négatifs doivent être gérés


/*
ft_itoa         : ==1574702== Invalid read of size 1
==1574702==    at 0x484FBE8: strcmp (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1574702==    by 0x4049B1: main (ft_itoa_test.cpp:21)
==1574702==  Address 0x4de4f9a is 0 bytes after a block of size 10 alloc'd
==1574702==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1574702==    by 0x4053EF: ft_itoa (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
==1574702==    by 0x404968: main (ft_itoa_test.cpp:20)
==1574702== 
1.OK 2.MKO 3.OK 4.MKO ==1574702== Invalid free() / delete / delete[] / realloc()
==1574702==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1574702==    by 0x404B23: main (ft_itoa_test.cpp:26)
==1574702==  Address 0x40615b is in a r-- mapped file /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out segment
==1574702== 
5.OK 6.MKO ==1574702== Invalid free() / delete / delete[] / realloc()
==1574702==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1574702==    by 0x404C05: main (ft_itoa_test.cpp:30)
==1574702==  Address 0x406159 is in a r-- mapped file /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out segment
==1574702== 
==1574702== Invalid read of size 1
==1574702==    at 0x484FBE8: strcmp (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1574702==    by 0x404C63: main (ft_itoa_test.cpp:32)
==1574702==  Address 0x4de5171 is 0 bytes after a block of size 1 alloc'd
==1574702==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1574702==    by 0x4053EF: ft_itoa (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
==1574702==    by 0x404C1A: main (ft_itoa_test.cpp:31)
==1574702== 
7.OK 8.MKO ==1574702== Invalid read of size 1
==1574702==    at 0x484FBE8: strcmp (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1574702==    by 0x404D4B: main (ft_itoa_test.cpp:35)
==1574702==  Address 0x4de5212 is 0 bytes after a block of size 2 alloc'd
==1574702==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1574702==    by 0x4053EF: ft_itoa (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
==1574702==    by 0x404D02: main (ft_itoa_test.cpp:34)
==1574702== 
9.OK 10.MKO ==1574702== Invalid read of size 1
==1574702==    at 0x484FBE8: strcmp (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1574702==    by 0x404E33: main (ft_itoa_test.cpp:39)
==1574702==  Address 0x4de52b2 is 0 bytes after a block of size 2 alloc'd
==1574702==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1574702==    by 0x4053EF: ft_itoa (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
==1574702==    by 0x404DEA: main (ft_itoa_test.cpp:38)
==1574702== 
11.OK 12.MKO 
==1574702== 1 bytes in 1 blocks are definitely lost in loss record 1 of 2
==1574702==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1574702==    by 0x4053EF: ft_itoa (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
==1574702==    by 0x404B35: main (ft_itoa_test.cpp:28)
==1574702== 
==1574702== 11 bytes in 1 blocks are definitely lost in loss record 2 of 2
==1574702==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1574702==    by 0x4053EF: ft_itoa (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
==1574702==    by 0x404A50: main (ft_itoa_test.cpp:24)
==1574702== 
*/

#include "libft.h"

static size_t	calculate_nb_bytes(int n)
{
	size_t	i;

	i = 0;
	if (n == INT_MIN)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i = 1;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	nb_bytes;
	size_t	i;

	nb_bytes = calculate_nb_bytes(n);
	str = (char *)malloc(nb_bytes);
	if (str == NULL)
		return (NULL);
	if (n == 0)
		return ("0");
	if (n == INT_MIN)
		return ("-2147483648");
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	i = nb_bytes - 1;
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (str);
}
