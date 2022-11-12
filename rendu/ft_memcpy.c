/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/10 16:45:24 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// copies n bytes from memory area src to memory area dest 
// The memory areas must not overlap
// returns a pointer to dest

#include <stddef.h>

void* ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	i=0;
	while (i < n)
	{
	  *((char *)dest + i) = *((char *)src + i);
		i++;
	}  
	return (dest);
}
