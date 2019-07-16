/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 17:21:52 by solefir           #+#    #+#             */
/*   Updated: 2019/07/15 17:32:25 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static _Bool	valid_links(t_data	*farm)
{
	
}

static _Bool	valid_rooms(t_data	*farm)
{
	
}

static _Bool	valid_write(t_data	*farm)
{
	
}

static _Bool	valid_lemins(t_data	*farm)
{

}

int		validation(t_data *farm)
{
	if (!valid_lemins(farm))
		return (1);
	if (!valid_write(farm))
		return (2);
	if (!valid_rooms(farm))
		return (3);
	if (!valid_links(farm))
		return (4);
	return (0);
}
