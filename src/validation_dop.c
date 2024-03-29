/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_dop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:01:18 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 20:23:16 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static _Bool	room_in_links(t_list *head)
{
	while (head != NULL && head->next != NULL && head->next->next != NULL)
	{
		if (is_link((char*)head->content) &&
		is_room((char*)head->next->content) &&
		is_link((char*)head->next->next->content))
			return (1);
		head = head->next;
	}
	if (head != NULL && head->next != NULL &&
		is_link((char*)head->content) && is_room((char*)head->next->content))
		return (1);
	return (0);
}

static _Bool	link_in_rooms(t_list *head)
{
	while (head != NULL && head->next != NULL && head->next->next != NULL)
	{
		if (is_room((char*)head->content) &&
			is_link((char*)head->next->content) &&
			is_room((char*)head->next->next->content))
			return (1);
		head = head->next;
	}
	if (head != NULL && is_link((char*)head->next->content) &&
		is_room((char*)head->content))
		return (1);
	return (0);
}

_Bool			last_validation(t_list *head)
{
	t_list	*temp;

	temp = head;
	if (g_count_room <= 0 || g_count_links <= 0)
		if ((g_error_nbr = 6))
			return (0);
	if (link_in_rooms(head) || room_in_links(head))
		if ((g_error_nbr = 7))
			return (0);
	return (1);
}
