/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_ants_move_and_print.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 00:28:17 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 20:22:16 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		make_moves(t_way **ws)
{
	int		moved;
	int		i;
	t_way	*way;

	moved = 0;
	i = -1;
	while ((way = ws[++i]))
	{
		while (way->parent)
			way = way->parent;
		while (way->next->next)
		{
			if (way->parent && way->ant_inside && ++moved)
				way->parent->ant_inside = way->ant_inside;
			way->ant_inside = 0;
			way = way->next;
		}
	}
	return (moved);
}

void	add_ant_and_print(int ant_id, t_way *ways, t_room **graph)
{
	ways->parent->parent->ant_inside = ant_id;
	ft_printf("L%d-%s ", ant_id, graph[ways->parent->parent->id]->name);
}

int		print_one(t_way *w, int j, t_room **graph)
{
	while (w->parent)
		w = w->parent;
	while (w->next && (!w->ant_inside || j--))
		w = w->next;
	if (j == -1 && w->ant_inside)
	{
		if (w->parent)
			ft_printf("L%d-%s ", w->ant_inside, graph[w->parent->id]->name);
		return (1);
	}
	return (0);
}

void	print_moves(t_way **ws, t_room **graph)
{
	int		i;
	int		j;
	int		printed;

	i = 0;
	while (++i)
	{
		j = -1;
		printed = 0;
		while (ws[++j])
		{
			printed += print_one(ws[j], i - 1, graph);
		}
		if (!printed)
			break ;
	}
}
