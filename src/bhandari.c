/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bhandari.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:53:30 by solefir           #+#    #+#             */
/*   Updated: 2019/08/05 19:57:08 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				find_int(int *array, int len, int to_find)
{
	int i;

	i = 1;
	while (i < len && array[i] != to_find)
		i++;
	if (i == len)
		return 0;
	return i;
}

void			copy_way(t_ways *a, t_ways *b, t_ways *new_a, int a_place)
{
	int 	i;
	int		j;

	i = -1;
	while (++i < a_place)
		new_a->way[i] = a->way[i];
	j = a_place + b->len_way - new_a->len_way - 1;
	while (++j < b->len_way)
		new_a->way[i++] = b->way[j];
}

t_ways			do_one_way(t_ways *a, t_ways *b)
{
	int			a_place;
	int			b_place;
	t_ways		new_a;

	a_place = 0;
	while (++a_place < a->len_way - 1)
		if ((b_place = find_int(b->way, b->len_way - 1, a->way[a_place])) > 0)
			break;
	new_a.len_way = a_place + (b->len_way - b_place);
	new_a.way = (int *)malloc(sizeof(int) * new_a.len_way);
	copy_way(a, b, &new_a, a_place);
	return (new_a);
}

static void		bhandari_disijoint(t_ways *a, t_ways *b)
{
	t_ways		new_a;
	t_ways		new_b;

	new_a = do_the_way(a, b);
	new_b = do_the_way(b, a);
	free(a->way);
	a->way = new_a.way;
	a->len_way = new_a.len_way;
	free(b->way);
	b->way = new_b.way;
	b->len_way = new_b.len_way;
}
