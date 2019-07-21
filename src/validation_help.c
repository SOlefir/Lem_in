/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:14:24 by solefir           #+#    #+#             */
/*   Updated: 2019/07/21 20:20:19 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

_Bool	is_room(char *str)
{
	int	i;
	int	coordinates;

	i = -1;
	coordinates = 0;
	while (str[++i] != '\0')
	{
		while (!ft_iswhitespace((int)str[i]))
			i++;
		coordinates++;
		if (coordinates > 2)
			return (0);
	}
	return (1);
}

_Bool	is_link(char *str)
{
	int	i;
	int	room;
	int	link;

	i = -1;
	room = 0;
	link = 0;
	while (str[++i] != '\0')
	{
		while (str[i] != '-')
		{
			if (ft_iswhitespace(str[i]))
				return (0);
			i++;
			room++;
		}
		link++;
	}
}

_Bool	is_comand(char *str)
{
	int		i;
	char	*start;
	char	*end;

	i = -1;
	if (ft_strcmp("##start", str))
	{
		g_start++;
		return (1);
	}
	else if (ft_strcmp("##end", str))
	{
		g_start++;
		return (1);
	}
	return (0);
}

_Bool	is_comment(char **str)
{
	int	i;
	int	hash;

	i = -1;
	hash = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == '#')
			hash++;
		if (hash > 1)
			return (0);
	}
	ft_strdel(str);
	return (1);
}
