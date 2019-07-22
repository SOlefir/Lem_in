/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:53:16 by solefir           #+#    #+#             */
/*   Updated: 2019/07/22 18:56:14 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_list		*make_list(char *str, int str_size)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (str == NULL || str_size == 0)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		if (!(list->content = malloc(str_size)))
			list->content_size = 0;
		else
		{
			ft_memcpy(list->content, (const void *)str, str_size);
			list->content_size = str_size;
		}
	}
	list->next = NULL;
	return (list);
}
