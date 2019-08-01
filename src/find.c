/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 21:31:07 by solefir           #+#    #+#             */
/*   Updated: 2019/08/01 18:37:06 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int			find_room_index(char *links, t_room **all_rooms, char *room_a)
{
	int		y;
	int		i;
	char	*link;
	t_room 	*room;

	y = -1;
	i = -1;
	link = ft_strstr(links, room_a);
	if (link == links)
	{
		while (link[++i])
			if (link[i] == '-')
				break;
		link[i] = '\0';
	}
	while (++y < g_count_room)
	{
		room = all_rooms[y];
		if (ft_strcmp(link, room->name) == 0)
			return (y);
	}
	return (0);
}

t_list				*find_link_in_lsts(t_list *list, char *str)
{
	while (ft_strnstr((char*)list->content, str, list->content_size) != NULL)
			list = list->next;
	return (list);
}

int					*find_links_room(char *name, t_list *input, t_room **graph, int count_links)
{
	int		*links;
	t_list	*temp;
	int		i;

	i = -1;
	temp = input;
	links = (int*)ft_memalloc(sizeof(int) * (count_links));
	while (++i < count_links)
	{
		temp = find_link_in_lsts(temp, name);
		links[i] = find_room_index(temp->content, graph, name);
	}
	return (links);
}