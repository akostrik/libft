/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:09:54 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/18 18:08:13 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Locates the first occurrence of the null-terminated little in big
// Not more than n characters are searched
// Characters that appear after a ‘\0’ character are not searched
// Is a FreeBSD specific API => should only be used when portability is not 
// a concern
// Returns a pointer to the first char of the first occurrence of little
// Returns NULL if little occurs nowhere in big
// Returns big if little is empty

// teter
// ft_strnstr      : 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK ==1574372== Invalid read of size 1
// ==1574372==    at 0x404DFB: little_is_here (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
// ==1574372==    by 0x404D5F: ft_strnstr (in /mnt/nfs/homes/akostrik/nana/01_libft/submit/tester/a.out)
// ==1574372==    by 0x404AD9: main (ft_strnstr_test.cpp:28)
// ==1574372==  Address 0x409000 is not stack'd, malloc'd or (recently) free'd
// ==1574372== 
// 7.SIGSEGV
// 7) ft_strnstr(empty, "coucou", -1) == 0

#include "libft.h"

static int	little_is_here(const char *big, const char *little, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (little[i] == '\0')
			return (1);
		if (little[i] != big[i])
			return (0);
		i++;
	}
	if (little[i] == '\0')
		return (1);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (i < n)
	{
		if (little_is_here(&big[i], little, n - i) == 1)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
