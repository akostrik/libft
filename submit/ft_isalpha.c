/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/18 12:53:05 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// isalpha - макрокоманда, почему?
// определена только если isascii(c) равно true или c = EOF
// доступна в UNIX, поддерживается стандартом ANSI C

// 	return (((unsigned)c | 32) - 'a' < 26);

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
