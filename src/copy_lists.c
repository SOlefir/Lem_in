/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:29:34 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 00:26:05 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static	t_way		*copy_way(t_way *way)
{
	t_way	*new;
	t_way	*front;
	t_way	*temp;

	new = NULL;
	new = new_list(-1, NULL);

	new->len = way->parent->len;
	temp = way;
	front = new;
	while (way && way->parent)
	{
		new->parent = new_list(way->parent->id, NULL);
		new->parent->next = new;
		new = new->parent;
		way = way->parent;
	}
	way = temp;
	del_list(&temp);
	return (front);
}

t_way		*copy_list(t_way *meta)
{
	t_way	*new;
	t_way	*front;
	t_way	*temp;

	new = new_list(-1, NULL);
	front = new;
	temp = meta->next;
	new->len = meta->len;
	while (meta->next && new)
	{
		new->next = copy_way(meta->next);
		new = new->next;
		meta = meta->next;
	}
	del_list(&temp);
	return (front);
}
