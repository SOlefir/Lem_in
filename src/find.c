/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 21:31:07 by solefir           #+#    #+#             */
/*   Updated: 2019/07/30 21:31:53 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			find_room_index(char *room, char** all_rooms)
{
	int	y;

	y = -1;
	while (++y < g_count_room)
		if (ft_strcmp(room, all_rooms[y]) == 0)
			return (y);
	return (0);
}

t_list		*find_in_lsts(t_list *list, char *str)
{
	while (ft_strcmp((char*)list->content, str) != 0)
			list = list->next;
	return (list);
}
