/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/10 13:25:36 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// tests for an ASCII character (0 to 127) ?
// checks whether c is a 7-bit unsigned char value that fits into the ASCII set
// возвращает ненулевое знач, если c от 0 до 0x7F, )0x7F =7*16+15=255 
// POSIX 1003.1 OB XSI. isascii obsolescent
// macros

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 255)
		return (1);
	return (0);
}