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

// returns a pointer to the memory area s

// Третий аргумент = колво байт, а не элементов, не учитывая тип данных

#include <stddef.h>
#include <stdio.h>

void* ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	printf("s = %s = %ld\n",(char*)s,(long int)s);
	i = 0;
	while (i < n)
	{
		s[0] = c;
		i++;
	}
	printf("s = %s = %ld\n",(char*)s,(long int)s);
	return (s);
}
