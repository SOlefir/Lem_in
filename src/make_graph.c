/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:52:07 by solefir           #+#    #+#             */
/*   Updated: 2019/08/01 18:25:10 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static	void		add_links(t_room ***rooms, t_list *input)
{
	t_room *temp;
	int		y;

	y = -1;
	while (++y <= g_count_room)
	{
		temp = (*rooms)[y];
		while (!is_link(input->content))
			input = input->next;
		if (is_link(input->content))
		{
			temp->count_links = count_links_room(input, temp->name);
			temp->links = find_links_room(temp->name, input, *rooms,
															temp->count_links);
		}
		(*rooms)[y] = temp;
	}
}

static t_room		*make_room(char *room_name, int y)
{
	t_room *room;

	room = (t_room*)ft_memalloc(sizeof(t_room));
	room->count_steps = g_count_links;
	room->name = ft_strdup(room_name);
	room->index = y;//
	return (room);
}

t_room			**make_graph(t_list *input)
{
	t_room	**arr;
	t_list	*temp;
	int		j;
	int		y;

	y = 0;
	arr = (t_room**)ft_memalloc(sizeof(t_room*) * g_count_room + 1);
	while (input != NULL)
	{
		if (is_comand((char *)input->content))
		{
			j = ((char *)input->content)[2] == 's' ? 0 : (g_count_room - 1);
			input = input->next;
			arr[j] = make_room(input->content, j);
		}
		else if (is_comment((char *)input->content))
			continue;
		else if (is_room((char *)input->content))
			arr[++y] = make_room(input->content, y);
		else if (is_link((char *)input->content))
			break;
		input = input->next;
	}
	add_links(&arr, input);
	return (arr);
}
