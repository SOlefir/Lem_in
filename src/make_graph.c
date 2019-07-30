/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:52:07 by solefir           #+#    #+#             */
/*   Updated: 2019/07/30 22:30:21 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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

static int			*find_links_room(char *name, t_list *input, t_room **rooms)
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
		temp = find_in_lsts(input, name);
		links[i] = find_indx(temp->content, rooms);
	}
}

static	void		add_links(t_room ***rooms, t_list *input)
{
	t_room *temp;
	int		y;

	y = -1;
	while (++y < g_count_room)
	{
		temp = (*rooms)[y];
		if (is_link(input->content))
			temp->links = find_links_room(temp->name, input, *rooms);
		input = input->next;
		(*rooms)[y] = temp;
	}
}

static t_room		*make_room(char *room_name, int y)
{
	t_room *room;

	room = (t_room*)ft_memalloc(sizeof(t_room));
	room->count_steps = g_count_links;
	room->name = ft_strdup(room_name);
	room->index = y;
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
	arr[g_count_room] = NULL;
	while (input != NULL)
	{
		if (is_comand((char *)input->content))
		{
			j = ((char *)input->content)[2] == 's' ? 0 : (g_count_room - 1);
			input = input->next;
			arr[j] = make_room(input->content, j);
			arr[j] = make_room(input->content, j);
			input = input->next;
		}
		else if (is_room((char *)input->content))
			arr[++y] = make_room(input->content, y);
		else if (is_link((char *)input->content))
			break;
		input = input->next;
	}
	add_links(&arr, input);
	return (arr);
}
