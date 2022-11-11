/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:59:03 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/11 21:34:00 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlen(char *str);
void*	ft_memset(void *s, int c, size_t n);

size_t	ft_strlcpy(char *dst, const char *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
int			ft_toupper(int c);	
int			ft_tolower(int c);
char*		ft_strchr(const char *s, int c);
char*		ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void*		ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char*		ft_strnstr(const char *big, const char *little, size_t len);
int			ft_atoi(const char *nptr);
void*		ft_calloc(size_t nmemb, size_t size);
char*		ft_strdup(const char *s);