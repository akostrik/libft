/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/18 13:32:18 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns a pointer to the first occurrence of the character c in the string s
// "character" = "byte"; does not work with wide or multibyte characters
// Returns a pointer to the matched character or NULL if not found
// The terminating null byte is considered part of the string, so that if c 
// is specified as '\0', returns a pointer to the terminator

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (1) //
	{
		if (*p == c)
			return (p);
		if (*p == '\0')
			return (NULL);
		p++;
	}
}
