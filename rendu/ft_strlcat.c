/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/11 21:24:08 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// concatenate strings
// take the full size of the buffer (not just the length) 
// NUL-terminates the result as long as there is at least 1 byte free in dst
// a byte for the NUL should be included in n
// only operates on true “C” strings: both src and dst must be NUL-terminated
// appends the NUL-terminated string src to the end of dst. It will 
// append at most n - strlen(dst) - 1 bytes, NUL-terminating the result.
// returns the total length of the string they tried to create = the initial 
// length of dst + the length of src (to make truncation detection simple)
// replacements for strncat (more consistent, and less error prone)

#include <stddef.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	nb_chars_to_treat;
	size_t	init_d_len;

	d = dst;
	s = (char *)src;
	nb_chars_to_treat = n;
	while (nb_chars_to_treat-- != 0 && *d != '\0')
		d++;
	init_d_len = d - dst;
	nb_chars_to_treat = n - init_d_len;
	if (nb_chars_to_treat == 0)
		return (init_d_len + ft_strlen(s));
	while (*s != '\0')
	{
		if (nb_chars_to_treat != 1)
		{
			*d++ = *s;
			nb_chars_to_treat--;
		}
		s++;
	}
	*d = '\0';
	return (init_d_len + (s - src));
}