/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:47:09 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/21 18:58:16 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s: La chaîne de caractères à découper
// c: Le caractère délimiteur
// Return Le tableau de nouvelles chaînes de caractères résultant du découpage
// Return NULL si l’allocation échoue
// fonctions autorisées : malloc, free
// Alloue (avec malloc(3)) et retourne un tableau de chaînes de caractères
// obtenu en séparant ’s’ à l’aide du caractère ’c’, utilisé comme délimiteur
// Le tableau doit être terminé par NULL

/*
static void print_list(t_text_portion **list)
{
	t_text_portion	*cour;

	printf("\nlist list = %p *list = %p of the length %zu\n",list,*list,
	list_size(*list));
	cour = *list;
	while(cour != NULL)
	{
		printf("%p %zu %zu\n",cour,cour ->start_text_portion,
		cour -> len_text_portion);
		cour = cour -> next;
	}
}
*/

#include "libft.h"

static size_t	list_size(t_text_portion *list)
{
	t_text_portion	*cour;
	size_t			i;

	cour = list;
	i = 0;
	while (cour != NULL)
	{
		cour = cour -> next;
		i++;
	}
	return (i);
}

static int	add_to_end(t_text_portion **lst, size_t start_text, size_t len_text)
	{
	t_text_portion	*new_elt;
	t_text_portion	*cour;

	new_elt = (t_text_portion *)malloc(sizeof(t_text_portion));
	if (new_elt == NULL)
		return (0);
	new_elt -> start_text_portion = start_text_portion;
	new_elt -> len_text_portion = len_text_portion;
	new_elt -> next = NULL;
	if (*lst == NULL)
		*lst = new_elt;
	else
	{
		cour = *lst;
		while (cour -> next != NULL)
			cour = cour -> next;
		cour -> next = new_elt;
	}
	return (1);
}

static t_text_portion	**creat_list(char const *s, char c)
{
	t_text_portion	**list;
	size_t			start_t;
	size_t			len_t;
	size_t			i;

	list = (t_text_portion **)malloc(sizeof(t_text_portion *));
	if (list == NULL)
		return (NULL);
	*list = NULL;
	i = 0;
	while (1)
	{
		start_t = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (i - start_t > 0 && add_to_end(list, start_t, i - start_t) == 0)
			return (NULL);
		if (s[i] == '\0')
			break ;
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
	}
	return (list);
}

static void	destroy_list(t_text_portion ***list)
{
	t_text_portion	*to_destroy;

	if (*list == NULL)
		return ;
	while (**list != NULL)
	{
		to_destroy = **list;
		**list = (**list)-> next;
		free(to_destroy);
	}
	free(*list);
}

static char	create-tab()
{

}

char	**ft_split(char const *s, char c)
{
	t_text_portion	***list;
	t_text_portion	*cour;
	size_t			len_list;
	size_t			i;
	size_t			j;
	char			**tab;

	list = (t_text_portion ***)malloc(sizeof(t_text_portion **));
	*list = creat_list(s, c);
	if (*list == NULL)
		return (NULL);
	len_list = list_size(**list);

	tab = (char **)malloc((len_list + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	i = 0;
	cour = **list;
	while (i < len_list)
	{
		tab[i] = (char *)malloc(cour -> len_text_portion + 1);
		if (tab[i] == NULL)
			return (NULL);
		j = 0;
		while (j < cour -> len_text_portion)
		{
			tab[i][j] = s[cour -> start_text_portion + j];
			j++;
		}
		tab[i][j] = '\0';
		i++;
		cour = cour -> next;
	}
	destroy_list(list);
	return (tab);
}