/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/11 17:13:06 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
       The atoi() function converts the initial portion of the string pointed to by nptr to int.  The behavior is the same as

           strtol(nptr, NULL, 10);

       except that atoi() does not detect errors.

       The atol() and atoll() functions behave the same as atoi(), except that they convert the initial portion of the string to their re‐
       turn type of long or long long.

RETURN VALUE
       The converted value or 0 on error
NOTES
       POSIX.1 leaves the return value of atoi() on error unspecified.  On glibc, musl libc, and uClibc, 0 is returned on error.

BUGS
       errno is not set on error so there is no way to distinguish between 0 as an error and as the converted value.  No checks for  over‐
       flow or underflow are done.  Only base-10 input can be converted.  It is recommended to instead use the strtol() and strtoul() fam‐
       ily of functions in new programs.

*/

#include <stddef.h>
#include <stdio.h>

int ft_atoi(const char *nptr)
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
