/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:52:07 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 20:11:29 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static	void		add_links(t_room ***rooms, t_list *input)
{
	t_room	*temp;
	int		y;

	y = -1;
	while (++y < g_count_room && temp != NULL)
	{
		temp = (*rooms)[y];
		temp->count_links = count_links_room(input, temp->name);
		temp->links = find_links_room(temp->name, input, *rooms,
															temp->count_links);
	}
}

static t_room		*make_room(char *room_name, int y)
{
	t_room *room;

	room = (t_room*)ft_memalloc(sizeof(t_room));
	room->name = cut_coordinates(room_name);
	room->index = y;
	room->occup = NULL;
	return (room);
}

t_room				**make_graph(t_list *input)
{
	t_room	**arr;
	t_list	*temp;
	int		j[2];

	j[1] = 0;
	temp = input;
	arr = (t_room**)ft_memalloc(sizeof(t_room*) * g_count_room);
	while (temp != NULL)
	{
		if (is_comand((char *)temp->content))
		{
			j[0] = ((char *)temp->content)[2] == 's' ? 0 : (g_count_room - 1);
			arr[j[0]] = make_room(temp->next->content, j[0]);
			temp = temp->next;
		}
		else if (is_comment((char *)temp->content) && (temp = temp->next))
			continue;
		else if (is_room((char *)temp->content) && ++j[1] < (g_count_room - 1))
			arr[j[1]] = make_room(temp->content, j[1]);
		else if (is_link((char *)temp->content))
			break ;
		temp = temp->next;
	}
	add_links(&arr, input);
	return (arr);
}
