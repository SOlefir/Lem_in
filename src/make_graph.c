/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:52:07 by solefir           #+#    #+#             */
/*   Updated: 2019/07/28 22:03:28 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		*find_links_room(char *name, t_list *input, t_graph **rooms)
{
	int		count_links;
	int		*links;
	int		i;

	i = -1;
	count_links = c_links(input, room_name);
	links = (int*)ft_memalloc(sizeof(int) * count_links);
	while (++i < count_links)
	{
		input = find_in_lsts(input, name);
		links[i] = find_indx(input->content, rooms);
	}
}

t_list		*find_in_lsts(t_list *list, char *str)
{
	while (ft_strcmp((char*)list->content, str) != 0)
			list = list->next;
	return (list);
}

static	void	add_links(t_graph ***rooms, t_list *input)
{
	t_graph *temp;
	int		i;

	while (++y < g_count_room)
	{
		if (is_link(input->content))
		{
			temp = (*rooms)[y];
			temp->links = find_links_room(temp->name, input, *rooms);
			input = input->next;
		}

	}

}

static int		count_links_room(t_list *input, char *str)
{
	int		count_links;
	char	*befor;

	befor = NULL;
	count_links = 0;
	while (input)
	{
		if (is_link((char*)input->content))
		{
			while (((char*)input->content)[i] != '\0')
			{
				if (str[i] == str[i])
					count_links++;
			}
			if (ft_strcmp(, str) == 0)
				count_links++;
		}
		input = input->next;
	}
}

t_graph		*make_room_struct(t_list *input, char *room_name, int y)
{
	t_graph *room;

	room = (t_graph*)ft_memalloc(sizeof(t_graph));
	room->count_steps = g_count_links;
	room->name = ft_strdup(room_name);
	room->index = y;
	return (room);
}

t_graph		**make_graph(t_list *input)
{
	t_graph	**arr;
	t_graph	*room;
	t_list	*temp;
	int		y;

	y = -1;
	arr = (t_graph**)ft_memalloc(sizeof(t_graph*) * g_count_room);
	while (input != NULL)
	{
		if (is_room)
		{
			room = make_room_struct(input, input->content, y);
			arr[y] = room;
			y++;
		}
		else if (is_link)
			break;
		input = input->next;
	}
	add_links(&arr, input);
	return (arr);
}
