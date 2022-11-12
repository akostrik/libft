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
// The memory areas may overlap: copying takes place as though the bytes in
// src are first copied into a temporary array that does not overlap src or  
// dest, and the bytes are then copied from the temporary array to dest
// returns a pointer to dest

#include <stddef.h>

void* ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char tmp[n];
	i=0;
	while (i < n)
	{
	  tmp[i] = *((char *)src + i);
		i++;
	}  
	i=0;
	while (i < n)
	{
	  *((char *)dest + i) = tmp[i];
		i++;
	}  
	return (dest);
}
