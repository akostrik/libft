/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/14 15:56:27 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Calculates the length of the string pointed to by s, 
// excluding the terminating null byte ('\0')
// Returns the number of bytes in the string pointed to by s.

#include <stddef.h> 

size_t	ft_strlen(char *str)
{
	char	*c;
	size_t	n;

	if (str == NULL)
		return (0);
	c = str;
	n = 0;
	while (*c != '\0')
	{
		n++;
		c++;
	}
	return (n);
}
