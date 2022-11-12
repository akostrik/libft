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

// erases the data in the n bytes of the memory starting at the location 
// pointed to  by s,  by  writing zeros (bytes containing '\0') to that area

#include <stddef.h>

void ft_bzero(void *s, size_t n)
{
	size_t	i;
	i=0;
	while (i < n)
	{
	  *((char *)s+i) = '\0';
		i++;
	}  
}
