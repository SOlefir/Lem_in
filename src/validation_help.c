/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:14:24 by solefir           #+#    #+#             */
/*   Updated: 2019/08/01 16:56:06 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

_Bool	is_room(char *str)
{
	int	i;
	int	s;

	i = -1;
	s = 0;
	if (str[0] == '#')
		return(0);
	while (str[++i] != '\0')
		if (ft_iswhitespace(str[i]))
			s++;
	return (s == 2 ? 1 : 0);
}

_Bool	is_link(char *str) // если это 2 слова с - посередине 
{
	int	i;
	int	link;

	i = -1;
	link = 0;
	if (str[0] == '#')
	    return (0);
	while (str[++i] != '\0')
	{
	    link += str[i] == '-' ? 1 : 0;
		if (ft_iswhitespace(str[i]))
			return (0);
	}
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
		g_end++;
		return (1);
	}
	return (0);
}

_Bool	is_comment(char *str)
{
	int	hash;

	hash = 0;
	if (str[0] == '#' && str[1] != '#')
		return (1);
	if (str[0] == 32 && str[1] == '#')
		return (1);
	return (0);
}

_Bool	is_unknown(char *str) // если это не похоже на всё, что выше. или если похоже на коммент но с ошибкой, то это не ок
{
	int	i;
	int	hash;
	int	word;

	i = -1;
	hash = 0;
	word = 0;
	while (str[++i] != '\0')
	{
		if ((!is_comand(str) && !is_comment(str) && !is_room(str) && !is_link(str)) ||
			(!ft_isascii((int)str[i]) || !ft_isprint((int)str[i])))
			return (1);
		hash += str[i] == '#' ? 1 : 0;
		word += ft_iswhitespace(str[i]);
	}
	if (hash > 2 || (word > 3 && str[0] != '#'))
		return (1);
	return (0);
}
