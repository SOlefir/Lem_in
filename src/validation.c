/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 17:21:52 by solefir           #+#    #+#             */
/*   Updated: 2019/07/20 21:32:20 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static	void	save_data(t_list *input, char **buf, int size_buf)
{
	input->next = ft_lstnew(buf, size_buf);
	input = input->next;
	ft_strdel(buf);
}

static _Bool	valid_links(char *buf)
{
	int	i;

	i = 0;
	while (buf[++i] != '\0')
	{
		while (buf[i] != '-' && buf[i] != '\0')
		{
			if (buf[i] == '#' || ft_iswhitespace(buf[i]) || buf[0] == 'L' ||
				 buf[i] == '\0' ||  buf[i] == '\n')
				return(0);
			i++;
		}
	}
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
		while (!ft_iswhitespace(buf[i]) && buf[i] != '\0')
		{
			if (!coordinates && (!ft_isalpha((int)buf[i]) ||
				!ft_isdigit((int)buf[i]) || buf[i] == '#'))
				return (0);
			if (coordinates && !ft_isdigit((int)buf[i]))
				return (0);
			i++;
		}
		if (!ft_iswhitespace(buf[i])) ||
			(coordinates = ft_isdigit(buf[i + 1])) <= 0)
			return (0);
	}
	g_count_room += buf[0] != '#' ? 1 : 0;
	return (1);
}

static _Bool	valid_lemins(char *buf)
{
	int		i;

	i = -1;
	while (buf[i] != '\0')
		if (!ft_isdigit((int)buf[i]))
			return (0);
	g_count_lems = ft_atoi(*buf);
	return (1);
}

int				read_and_valid(t_list *input)
{
	char 	**buf;
	int		size_buf;

	buf = NULL;
	while ((size_buf = get_next_line(0, buf)) != 0 && buf[0] != '\n')
	{
		if (size_buf < 0 || buf[0] == '\n')
		{
			ft_strdel(buf);
			return (4);
		}
		if (is_comand(buf) && (g_start > 1 || g_end > 1))
			return (0);
		if (is_comment(buf))
			continue;
		if (g_count_lems == 0 && !valid_lemins(*buf))
			return (1);
		else if (is_room(*buf) && !valid_rooms(*buf) &&
				!uniq_coordinates(buf, input))
			return (2);
		else if (is_link(*buf) && !valid_links(*buf))
			return (3);
		save_data(input, buf, size_buf);
	}
	return (-1);
}
