/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/21 16:17:27 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Converts the initial portion of the string pointed to by str to int
Does not detect errors
The string may begin with an arbitrary amount of white space (isspace(3)) 
followed by a single optional '+' or '-' 
The remainder of the string is converted to a long value in the obvious manner, 
stopping at the first character which is not a valid digit 
Retourns the converted value or 0 on error
If there were no digits at all, returns 0
*/

// tester  1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 10.OK 11.OK 12.KO 13.OK 14.OK 15.OK 16.OK 17.OK 
// 12) ft_atoi("-+42") == 0)

#include "libft.h"

static int	is_whitespace(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\r')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int	sign;
	int	to_return;

	i = 0;
	while (is_whitespace(str[i]) == 1)
		i++;
	sign = 1;
	if (str[i] == '-')
	{
		if (!ft_isdigit(str[i + 1]))
			return (0);
		sign = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	to_return = 0;
	while (ft_isdigit(str[i]) == 1)
	{
		to_return = to_return * 10 + str[i] - '0';
		i++;
	}
	return (sign * to_return);
}
