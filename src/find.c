/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 21:31:07 by solefir           #+#    #+#             */
/*   Updated: 2019/07/31 13:57:36 by solefir          ###   ########.fr       */
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

static t_list		*find_link_in_lsts(t_list *list, char *str)
{
	while (ft_strnstr((char*)list->content, str, list->content_size) != NULL)
			list = list->next;
	return (list);
}

static int			count_links_room(t_list *input, char *str)
{
	int		count_links;
	int		i;
	int		j;

	i = -1;
	count_links = 0;
	while (input->next != NULL)
	{
		if (is_link((char*)input->content))
		{
			while (((char*)input->content)[++i] != '\0' && 
					((char*)input->content)[i] == str[i])		
					j++;
			count_links += (j == ((int)input->content_size - 1)) ? 1 : 0;
		}
		input = input->next;
	}
}

int					*find_links_room(char *name, t_list *input, t_room **graph)
{
	int		count_links;
	int		*links;
	t_list	*temp;
	int		i;

	i = -1;
	temp = input;
	count_links = count_links_room(input, name);
	links = (int*)ft_memalloc(sizeof(int) * count_links);
	links[count_links] = NULL;
	while (++i < count_links)
	{
		temp = find_link_in_lsts(temp, name);
		links[i] = find_indx_link(temp->content, graph, name);
	}
	return (links);
}