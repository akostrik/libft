/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:09:54 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/11 22:10:34 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// locates the first occurrence of the null-terminated string little 
// in the string big, where not more than n characters are searched
// Characters that appear after a ‘\0’ character are not searched
// the function is a FreeBSD specific API => it should only be used when 
// portability is not a concern
// returns big if little is an empty string
// returns NULL if little occurs nowhere in big
// otherwise returns a pointer to the first char of the first occurrence of little

#include <stddef.h>
#include <stdio.h>

char* ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
     	i++;
	}
	return (s);
}