/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/10 16:19:45 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ASCII character (0 to 127) ?
// man : whether c is a 7-bit unsigned char value that fits into the ASCII set
// возвращает ненулевое знач, если c от 0 до 0x7F=255 
// POSIX 1003.1 OB XSI  obsolescent
// macros
// 32 = 00010000
// | поразрядное ИЛИ
//if ( ((unsigned)c|32) <= 127)

#include <stdio.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	if (c == EOF)
		return (1);
	return (0);
}
