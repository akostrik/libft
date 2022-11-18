/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/18 15:18:34 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Concatenate dst + src
// Appends at most n-strlen(dst)-1 bytes
// NUL-terminates the result as long as there is at least 1 byte free in dst
// A byte for the NUL should be included in n
// Takes the full size of the buffer (not just the length)
// src and dst must be NUL-terminated (true “C” strings)
// Returns the total length of the string it tried to create = 
// the initial dst-length + src-length (to make truncation detection simple)
// Replacements for strncat (more consistent, and less error prone)

#include "libft.h"

static size_t	min(size_t a, size_t b)
{
	if ((int)a < (int)b)
		return (a);
	return (b);
}

static size_t	calc_nb_chars_to_append(char *dst, const char *src, size_t n)
{
	size_t	src_length;
	size_t	dst_initial_len;

	dst_initial_len = ft_strlen(dst);
	src_length = ft_strlen(src);

	if ((int)dst_initial_len + (int)src_length + 1 <= (int)n)
		return (dst_initial_len + src_length);
	if ((int)dst_initial_len + 1 >= (int)n)
		return (0);
	return ((int)n - (int)dst_initial_len - 1);
}

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	dst_initial_len;
	size_t	nb_chars_to_append;

	dst_initial_len = ft_strlen(dst);
	nb_chars_to_append = calc_nb_chars_to_append(dst, src, n);
	i = 0;
	while (i < nb_chars_to_append)
	{
		dst[dst_initial_len + i] = src[i];
		i++;
	}
	dst[dst_initial_len + i] = '\0';
	return (dst_initial_len + min(ft_strlen(src), n));
}
