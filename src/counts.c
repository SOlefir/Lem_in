/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 19:45:52 by solefir           #+#    #+#             */
/*   Updated: 2019/08/02 20:27:49 by solefir          ###   ########.fr       */
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

	count_links = 0;
	while (input != NULL)
	{
		if (is_link((char*)input->content))
			if (ft_strstr((char*)input->content, str))
				count_links++;
		input = input->next;
	}
	return (count_links);
}
