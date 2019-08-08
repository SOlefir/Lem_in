/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 21:31:07 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 19:55:38 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	find_room_index(char *links, t_room **all_rooms, char *room_a)
{
	int		y;
	int		i;
	char	*link;
	t_room	*room;

	y = -1;
	link = (!ft_strncmp(links, room_a, ft_strlen(room_a))) ?
	ft_strchr(links, '-') + 1 : links;
	i = (!ft_strchr(link, '-')) ? ft_strlen(link) : ft_strchr(link, '-') - link;
	while (++y < g_count_room)
	{
		room = all_rooms[y];
		if (!ft_strncmp(link, room->name, i))
			return (y);
	}
	return (0);
}

t_list		*find_link_in_input(t_list *input, char *str)
{
	while (input != NULL)
	{
		if (!ft_strncmp((char*)input->content, str, ft_strlen(str)) ||
			!ft_strcmp(ft_strchr((char*)input->content, '-') + 1, str))
			return (input);
		input = input->next;
	}
	return (input);
}

int			*find_links_room(char *name, t_list *input, t_room **graph,
															int count_links)
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
