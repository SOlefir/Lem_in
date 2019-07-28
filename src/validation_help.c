/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:14:24 by solefir           #+#    #+#             */
/*   Updated: 2019/07/27 21:17:46 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

_Bool	is_room(char *str)
{
	int	i;

	i = -1;
	if (str[0] == '#')
		return(0);
	while (str[++i] != '\0')
	{
		if (str[i] == '-')
			return (0);
		if (!g_count_ants && ft_isdigit((int)str[i]))
			return (0);
	}
		return (1);
}

_Bool	is_link(char *str)
{
	int	i;
	int	link;

	i = -1;
	link = 0;
	if (str[0] == '#')
	    return (0);
	while (str[++i] != '\0')
	    link += str[i] == '-' ? 1 : 0;
	return (link < 1 ? 0 : 1);
}

_Bool	is_comand(char *str)
{
	int		i;

	i = -1;
	if (ft_strcmp("##start", str) == 0)
	{
		g_start++;
		return (1);
	}
	else if (ft_strcmp("##end", str) == 0)
	{
		g_start++;
		return (1);
	}
	return (0);
}

_Bool	is_comment(char *str)
{
	int	i;
	int	hash;

	i = -1;
	hash = 0;
	if (str[0] != '#')
		return (0);
	while (str[++i] != '\0')
	{
		if (str[i] == '#')
			hash++;
		if (hash != 1)
			return (0);
	}
	return (1);
}

_Bool	is_unknown(char *str)
{
	int	i;
	int	hash;
	int	word;

	i = -1;
	hash = 0;
	word = 0;
	while (str[++i] != '\0')
	{
		if (!is_comand(str) && !is_comment(str) && !is_room(str) &&
			(!ft_isascii((int)str[i]) || !ft_isprint((int)str[i])))
			return (1);
		hash += str[i] == '#' ? 1 : 0;
		word += ft_iswhitespace(str[i]);
	}
	if (hash > 2 || word > 3)
		return (1);
	return (0);
}
