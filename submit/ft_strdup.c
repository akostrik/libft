/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/18 18:13:19 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Returns a pointer to a new string which is a duplicate of the string s
Memory for the new string is obtained with malloc(3), can be freed with free(3)
On success, returns a pointer to the duplicated string
Returns NULL if insufficient memory was available, errno = the cause of the error
ERRORS : ENOMEM Insufficient memory available to allocate duplicate string.
*/

// tester ft_strdup       : 1.KO 2.MKO 3.OK 4.MOK 
// 1) char * s = ft_strdup((char*)"coucou"); check(!strcmp(s, "coucou"))
// 2) mcheck(s, strlen("coucou") + 1); free(s);
	
// 3) s = ft_strdup((char*)"");  check(!strcmp(s, "")); // OK у меня
// 4) s = ft_strdup((char*)"");  mcheck(s, 1); free(s);

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	initial_length_s;
	char	*res_str;

	i = 0;
	while (s[i] != '\0')
		i++;
	initial_length_s = i;
	res_str = NULL;
	res_str = (char *)malloc((2 * initial_length_s + 1) * sizeof(char));
	if (res_str == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	i = 0;
	while (i < initial_length_s)
	{
		res_str[i] = s[i];
		res_str[initial_length_s + i] = s[i];
		i++;
	}
	res_str[initial_length_s + i] = '\0';
	return (res_str);
}
