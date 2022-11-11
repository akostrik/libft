/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/11 19:35:27 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// copies up to n - 1 characters from the NUL-terminated src to dst
// takes the full size of the buffer (not just the length)
// NUL-terminats the result
// guarantees to NUL-terminate the result (as long as n>0)
// a byte for the NUL should be included in n
// only operates on true “C” strings: src must be NUL-terminated
// returns the total length of the string it tried to create = the length of src
// it was done to make truncation detection simple
// if traverses n characters without finding a NUL, the length of the string 
// is considered to be n and dst will not be NUL-terminated (no space for NUL)
// This keeps it from running off the end of a string. In practice this 
// should not happen (as it means n is incorrect / dst is not a proper C string)
// The check exists to prevent potential security problems in incorrect code
// replacement for strncpy (more consistent, less error prone)
// On Ubuntu, is available in the libbsd-dev package

#include <stddef.h>
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		if (src[i] == '\0')
			return (i + 1);
		i++;
	}
	dst[i - 1] = '\0';
	return (i + 1);
}
