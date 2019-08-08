/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 12:45:00 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 00:50:27 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char		*cut_coordinates(char *room_name)
{
	int		i;
	char	*name;

	i = 0;
	while (!ft_iswhitespace(room_name[i]))
		i++;
	name = (char*)ft_memalloc(i + 1);
	i = -1;
	while (!ft_iswhitespace(room_name[++i]) && room_name[i] != '\0')
		name[i] = room_name[i];
	name[i] = '\0';
	return (name);
}
