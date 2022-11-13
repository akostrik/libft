/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/11 20:31:37 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// returns a pointer to the last occurrence of the character c in the string s.
// or NULL if the character is not found

#include <stddef.h>
#include <stdio.h>

char* ft_strrchr(const char *s, int c)
{
	char*	p;
	char*	to_return;

	p = (char*)s;
	to_return = NULL;
	while (1 == 1)
	{
		if (*p == c)
			to_return = p;
		if (*p == '\0')
			return (to_return);
		p++;
	}
}