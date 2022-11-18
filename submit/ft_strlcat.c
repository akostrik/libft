/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/18 19:23:25 by akostrik         ###   ########.fr       */
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

// 1.KO 2.KO 3.KO 4.KO 5.OK 6.KO 7.KO 8.KO 9.KO 10.OK 11.OK 12.OK 13.KO 14.KO 15.OK 16.OK 17.KO 
// 1)  ft_strlcat(dest, src, 0) == strlen(src) && !strcmp(dest, "B")
// 2)  ft_strlcat(dest, src, 1) == 10 && !strcmp(dest, "B")
// 3)  ft_strlcat(dest, src, 3) == 3 + strlen(src) && !strcmp(dest, "BBBB")
// 4)  ft_strlcat(dest, src, 6) == 13 && !strcmp(dest, "BBBBA")
// 6)
// 7)  ft_strlcat(dest, src, 1) == strlen(src) && !strcmp(dest, "")
// 8)  ft_strlcat(dest, src, 5) == strlen(src) + 5 && !strcmp(dest, "1111111111")
// 9)  ft_strlcat(dest, src, 5) == strlen(src) + 5 && !strcmp(dest, "1111111111")
// 13) ft_strlcat(dest, "123", 1) == 3 && !strcmp(dest, "")
// 14) ft_strlcat(dest, "123", 2) == 3 && !strcmp(dest, "1")
// 17) ft_strlcat(dest, "123", 0) == 3 && !strcmp(dest, "")

#include "libft.h"

static size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

static size_t	calc_nb_chars_to_append(char *dst, const char *src, size_t n)
{
	size_t	src_length;
	size_t	dst_initial_len;

	dst_initial_len = ft_strlen(dst);
	src_length = ft_strlen(src);

	if (dst_initial_len + src_length + 1 <= n)
		return (dst_initial_len + src_length);
	if (dst_initial_len + 1 >= n)
		return (0);
	return (n - dst_initial_len - 1);
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
