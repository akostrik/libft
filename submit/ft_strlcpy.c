/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/18 14:33:55 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Copies up to n - 1 characters from the NUL-terminated src to dst
// Takes the full size of the buffer (not just the length)
// Guarantees to NUL-terminate the result (as long as n>0)
// A byte for the NUL should be included in n
// src must be NUL-terminated (true “C” strings)
// Returns the total length of the string it tried to create = the length of src
// (to make truncation detection simple)
// Iif traverses n characters without finding a NUL, the length of the string 
// is considered to be n and dst will not be NUL-terminated (no space for NUL)
// This keeps it from running off the end of a string. In practice this 
// should not happen (as it means n is incorrect / dst is not a proper C string)
// The check exists to prevent potential security problems in incorrect code
// replacement for strncpy (more consistent, less error prone)

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	src_length;

	i = 0;
	while (src[i] != '\0')
		i++;
	src_length = i;
	i = 0;
	while ((int)i < (int)(n - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (n > 0)
		dst[i] = '\0';
	return (src_length);
}
