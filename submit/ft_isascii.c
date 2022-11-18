/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/18 12:53:12 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ASCII character (0 to 127) ?
// man : whether c is a 7-bit unsigned char value that fits into the ASCII set
// c must have the value of an unsigned char or EOF
// POSIX 1003.1 OB XSI  obsolescent
// macros
// 32 = 00010000
// | поразрядное ИЛИ
//if ( ((unsigned)c|32) <= 127)

#include "libft.h"

int	ft_isascii(int c)
{
	if ((unsigned int)c <= 127)
		return (1);
	return (0);
}
