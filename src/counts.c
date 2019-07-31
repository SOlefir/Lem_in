/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 19:45:52 by solefir           #+#    #+#             */
/*   Updated: 2019/07/31 20:49:02 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		count_lst(t_ways *lst)
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

int		count_all_steps(t_ways *ways)
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

int		count_len_way(int *way)
{
	int	len;

	len = 0;
	while (way[len] != NULL)
		len++;
	return (len);
}

int		max_allowable(int *start, int *end)
{
	int	i;
	int j;

	i = count_len_way(start);
	j = count_len_way(end);
	return (i <= j ? i : j);
}
