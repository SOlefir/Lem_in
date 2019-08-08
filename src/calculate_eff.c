/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_eff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:57:45 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 19:59:59 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int					calc_efficiency(t_way *meta)
{
	t_way	*path;
	int		efc;
	int		max;
	int		sum;
	int		mod;

	path = meta;
	max = 0;
	sum = 0;
	while ((path = path->next))
		if ((sum += path->len))
			(max < path->len) ? max = path->len : 0;
	efc = (g_count_ants - max * meta->len + sum) / meta->len + max - 1
	+ !!((g_count_ants - max * meta->len + sum) % meta->len);
	mod = (g_count_ants - max * meta->len + sum) % meta->len;
	(g_efficiency > efc) ? g_mod = mod : 0;
	return (efc == (g_efficiency = (g_efficiency > efc) ? efc : g_efficiency));
}
