/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:31:15 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/18 13:19:58 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Scans the initial n bytes of the memory area pointed to by s for the first 
// instance of c
// c and the bytes of the memory area are interpreted as unsigned char
// Returns a pointer to the matching byte 
// or NULL if the character does not occur

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*p == (unsigned char)c)
			return (p); // (void)p ?
		p++;
		i++;
	}
	return (NULL);
}
