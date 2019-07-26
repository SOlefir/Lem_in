/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:54:06 by solefir           #+#    #+#             */
/*   Updated: 2019/07/26 20:09:12 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		count_links_room(t_list *input, char *str)
{

}

t_struct_d		*get_data(t_list *input)
{
	t_struct_d	*data;
	int			count_room_links;
	int			y;
	int			x;

	y = -1;
	data = NULL;
	data->rooms = (char**)ft_memalloc(sizeof(char*) * g_count_room);
	data->links = (int**)ft_memalloc(sizeof(int*) * g_count_room);
	while (input->next != NULL)
	{
		while (is_room && ++y < g_count_room)
		{
			data->rooms[y] = (char*)ft_memalloc(input->content_size);
			x = -1;
			while (++x < input->content_size)
				data->rooms[y][x] = (char*)input->content[x];
			input = input->next;
		}
		while (is_link && input->next != NULL)
		{
			y = find_room_index(input->content, data->rooms);
			count_room_links = count_links_room(input, input->content);
			data->links[y] = (int*)ft_memalloc(sizeof(int) * count_room_links);
			x = -1;
			while (++x < count_room_links)
				data->links[y][x] = find_room_index(input->content, data->rooms);
			input = input->next;
		}
	}
}
