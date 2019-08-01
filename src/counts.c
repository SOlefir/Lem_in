/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 19:45:52 by solefir           #+#    #+#             */
/*   Updated: 2019/08/01 18:38:04 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			count_all_ways(t_ways *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

int			count_all_steps(t_ways *ways)
{
	int	steps;

	steps = 0;
	while (ways != NULL)
	{
		steps += ways->len_way;
		ways = ways->next;
	}
	return (steps);
}

int			max_allowable(t_room **graph)
{
	int	min_start;
	int	min_end;

	min_start = graph[0]->count_links;
	min_end = graph[g_count_room - 1]->count_links;
	return (min_start <= min_end ? min_start : min_end);
}

int			count_links_room(t_list *input, char *str)
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
	return (count_links);
}
