/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/11 22:08:21 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// compares the first n bytes (each interpreted as unsigned char) of the memory 
// areas s1 and s2
// returns an integer less than, equal to, or greater than zero 
// if the first n bytes of s1 is found to be 
// less than, to match, or be greater than the first n bytes of s2
// for a nonzero return value, the sign is determined by the sign of the 
// difference between the first pair of bytes (interpreted as unsigned char)
// that differ in s1 and s2
// If n is zero, the return value is zero
// Do not use memcmp() to compare security critical data, such as cryptographic 
// secrets, because the required CPU time depends on the number of equal bytes
// Instead, a function that performs comparisons in constant time is required
// возвращаемые значения у меня и у libc не совпадают

#include <stddef.h>
#include <stdio.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					i;
	unsigned char*	p1;
	unsigned char*	p2;

	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	i = 0;
	while (1)
	{
		if (i >= n)
			return (0);
		if (*p1 != *p2)
			return (int)(*p1 - *p2); //
		p1++;
		p2++;
		i++;
	}
}
