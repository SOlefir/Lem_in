/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 17:21:52 by solefir           #+#    #+#             */
/*   Updated: 2019/07/24 19:47:15 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static _Bool	uniq_coordinates(char *buf, t_list *input)
{
	int	i;

	i = 0;
	if (g_count_room <= 1)
		return (1);
	while (input)
	{
		if (input->content != NULL && is_room((char*)input->content))
		{
			while (!ft_iswhitespace(buf[i]) && buf[i] != '\0')
				i++;
			if (ft_strncmp(buf, (char*)input->content, i) == 0)
			{	
				ft_strdel(&buf);
				return(0);
			}
			if ((atoi_coordinates((char*)input->content) ==
				atoi_coordinates(buf)))
			{
				ft_strdel(&buf);
				return (0);
			}
		}
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
		while (buf[i] != '-' && buf[i] != '\0')
		{
			if (buf[0] == 'L' || buf[i] == '#' || buf[i] == '\n' ||
				room == 2)
			{
				ft_strdel(&buf);
				return (0);
			}
			i++;
		}
		i++;
		room++;
	}
	g_count_links++;
	return (1);
}

static _Bool	valid_rooms(char *buf)
{
	int	i;
	int	coordinates;

	i = 0;
	coordinates = 0;
	while (buf[i] != '\0')
	{
		while (!ft_iswhitespace(buf[i]) && buf[i] != '\0')
		{
			if (buf[0] == 'L' || buf[i] == '#' || buf[i] == '\n')
			{
				ft_strdel(&buf);
				return (0);
			}
			if (coordinates && !ft_isdigit((int)buf[i]))
			{
				ft_strdel(&buf);
				return (0);
			}
			i++;
		}
		if (buf[i] != '\0' && (!ft_iswhitespace(buf[i]) ||
			(coordinates += ft_isdigit(buf[i + 1])) <= 0))
		{
			ft_strdel(&buf);
			return (0);
		}
		i += buf[i] == '\0'? 0 : 1;
	}
	g_count_room++;
	return (coordinates == 2 ? 1 : 0);
}

static _Bool	valid_ants(char *buf)
{
	int		i;

	i = -1;
	while (buf[++i] != '\0')
		if (!ft_isdigit((int)buf[i]))
		{
			ft_strdel(&buf);
			return (0);
		}
	g_count_ants = ft_atoi(buf);
	return (1);
}

int				read_and_valid(t_list *input)
{
	char	*buf;
	int		size_buf;
	t_list	*head;

	buf = NULL;
	head = input;
	while (get_next_line(fd, &buf) > 0 && (size_buf = (int)ft_strlen(buf)) > 0)
	{
		//printf("buf %s\n", buf);
		if (buf[0] == '\n' || buf[0] == '\0')
			return (0);
		if (is_comment(&buf))
			continue;
		if (is_comand(buf) && (g_start > 1 && g_end > 1))
			return (1);
		else if (g_count_ants == 0 && !valid_ants(buf))
			return (2);
		else if (is_room(buf) && (!valid_rooms(buf) ||
				    !uniq_coordinates(buf, head)))
			return (3);
		else if (is_link(buf) && !valid_links(buf))
			return (4);
        input->next = ft_lstnew(buf, size_buf + 1);
		input = input->next;
        printf("{%d %d}\n", (int)ft_strlen(buf), size_buf);
        printf("buf %s\n", buf);
        printf("con %s\n", (char*)input->content);
		ft_strdel(&buf);
	}

	ft_strdel(&buf);
	return (-1);
}
