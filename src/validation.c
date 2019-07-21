/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 17:21:52 by solefir           #+#    #+#             */
/*   Updated: 2019/07/21 20:35:36 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static _Bool	uniq_coordinates(char *buf, t_list *input)
{
	int		i;
	int		j;

	while (input->next != NULL)
	{
		if (is_room(input->content))
			if ((atoi_coordinates(input->content) - atoi_coordinates(buf)) == 0)
				return (0);
		input = input->next;
	}
	return (1);
}

static _Bool	valid_links(char *buf)
{
	int	i;
	int	room;

	i = 0;
	room = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == 'L')
			return (0);
		while (buf[i] != '-' || buf[i] != '\0')
		{
			if (buf[i] == '#' || ft_iswhitespace(buf[i]) ||
				buf[i] == '\0' || buf[i] == '\n' || room == 2)
				return (0);
			i++;
		}
		i++;
		room++;
	}
	g_count_links++;
	ft_strdel(buf);
	return (1);
}

static _Bool	valid_rooms(char *buf)
{
	int	i;
	int	coordinates;

	i = -1;
	coordinates = 0;
	if (buf[0] == 'L')
		return (0);
	while (buf[++i] != '\0')
	{
		while (!ft_iswhitespace(buf[i]) || buf[i] != '\0')
		{
			if (!coordinates && (!ft_isascii((int)buf[i]) || buf[i] == '#' ||
				buf[i] == '\n'))
				return (0);
			if (coordinates && !ft_isdigit((int)buf[i]))
				return (0);
			i++;
		}
		if (!ft_iswhitespace(buf[i]) ||
			(coordinates = ft_isdigit(buf[i + 1])) <= 0)
			return (0);
	}
	g_count_room++;
	ft_strdel(buf);
	return (1);
}

static _Bool	valid_ants(char *buf)
{
	int		i;

	i = -1;
	while (buf[i] != '\0')
		if (!ft_isdigit((int)buf[i]))
			return (0);
	g_count_ants = ft_atoi(*buf);
	ft_strdel(buf);
	return (1);
}

int				read_and_valid(t_list *input)
{
	char	**buf;
	int		size_buf;

	buf == NULL;
	while ((size_buf = get_next_line(0, buf)) != 0)
	{
		if (size_buf < 0 || buf[0] == '\n' || buf[0] == '\0')
			return (0);
		if (is_comment(buf))
			continue;
		if (is_comand(*buf) && (g_start != 1 || g_end != 1))
			return (1);
		else if (g_count_ants == 0 && !valid_ants(*buf))
			return (2);
		else if (is_room(*buf) && !valid_rooms(*buf) &&
				!uniq_coordinates(*buf, input))
			return (3);
		else if (is_link(*buf) && !valid_links(*buf))
			return (4);
		input->next = ft_lstnew(buf, size_buf);
		input = input->next;
		ft_strdel(buf);
	}
	ft_strdel(buf);
	return (-1);
}
