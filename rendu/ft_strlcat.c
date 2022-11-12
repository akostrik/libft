/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/12 22:01:25 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// concatenate dst + src
// appends at most n-strlen(dst)-1 bytes
// take the full size of the buffer (not just the length)
// both src and dst must be NUL-terminated (true “C” strings)
// NUL-terminates the result as long as there is at least 1 byte free in dst
// a byte for the NUL should be included in n
// returns the total length of the string they tried to create = 
// the initial dst-length + src-length (to make truncation detection simple)
// replacements for strncat (more consistent, and less error prone)

#include <stddef.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	int	id;
	int	is;
	int	dst_initial_strlen;

	id = 0;
	is = 0;
	while (dst[id] != '\0')
		id++;
	dst_initial_strlen = id;
	//printf("\ndst_initial_length = %ld, dst = %s\n",dst_initial_length, dst);
	while (is < (int)n - dst_initial_strlen - 1)
	{
		dst[id] = src[is];
		if (src[is] == '\0')
			break;
		is++;
		id++;
	}
	dst[id + is] = '\0'; // ?
	return (id);
}