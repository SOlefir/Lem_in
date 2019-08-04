/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 21:31:07 by solefir           #+#    #+#             */
/*   Updated: 2019/08/03 16:30:14 by solefir          ###   ########.fr       */
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
	link = ft_strstr(links, room_a);
	if (link == links)
	{
		link = ft_strchr(links, '-') + 1;
		i = ft_strlen(link);
	}
	else
	{
		link = links;
		i = 0;
		while (links[i] != '-')
			i++;
	}
	while (++y < g_count_room)
	{
		room = all_rooms[y];
		if (ft_strnstr(link, room->name, i))
			return (y);
	}
	return (0);
}

t_list				*find_link_in_input(t_list *input, char *str)
{
	while (ft_strstr((char*)input->content, str) == NULL ||
			is_comment((char*)input->content))
			input = input->next;
	return (input);
}

int					*find_links_room(char *name, t_list *input, t_room **graph, int count_links)
{
	int		*links;
	t_list	*that_link;
	int		i;

	i = -1;
	that_link = input;
	while (!is_link((char*)that_link->content))
		that_link = that_link->next;
	links = (int*)ft_memalloc(sizeof(int) * (count_links));
	while (++i < count_links)
	{
		that_link = find_link_in_input(that_link, name);
		links[i] = find_room_index((char *)that_link->content, graph, name);
		that_link = that_link->next;
	}
	return (links);
}