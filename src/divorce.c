/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divorce.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 20:16:25 by solefir           #+#    #+#             */
/*   Updated: 2019/07/31 20:44:27 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			*divorce(int *way, int *start, int *end)
{
	int i;
	int	j;
	int	len;
	int	*new_way;

	j = -1;
	i = (count_len_way(way) - count_len_way(start)) + 1;
	len = count_len_way(end) + i;
	new_way = (int*)ft_memalloc(sizeof(int) * (len + 1));
	new_way[len] = NULL;
	while (new_way[++j] != start)
		new_way[j] = way[j];
	i = -1;
	while (new_way[++j] != NULL)
		new_way[j] = end[++i];
	return (new_way);
}
