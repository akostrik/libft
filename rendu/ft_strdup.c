/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/11 17:17:06 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
       The  strdup()  function  returns  a pointer to a new string which is a duplicate of the string s.  Memory for the new string is ob‐
       tained with malloc(3), and can be freed with free(3).

       The strndup() function is similar, but copies at most n bytes.  If s is longer than n, only n bytes are copied, and  a  terminating
       null byte ('\0') is added.

       strdupa()  and  strndupa()  are  similar, but use alloca(3) to allocate the buffer.  They are available only when using the GNU GCC
       suite, and suffer from the same limitations described in alloca(3).

RETURN VALUE
       On success, the strdup() function returns a pointer to the duplicated string.  It returns NULL if insufficient  memory  was  avail‐
       able, with errno set to indicate the cause of the error.

ERRORS
       ENOMEM Insufficient memory available to allocate duplicate string.
*/

#include <stddef.h>
#include <stdio.h>

char *ft_strdup(const char *s)
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
