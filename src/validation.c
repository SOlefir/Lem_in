/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 17:21:52 by solefir           #+#    #+#             */
/*   Updated: 2019/08/07 16:15:09 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		g_start = 0;
int		g_end = 0;
int		g_error_nbr = -1;

static _Bool	uniq_rm_crd(char *str, t_list *input)
{
	int	i;

	i = 0;
	if (g_count_room <= 1)
		return (1);
	while (input)
	{
		if (input->content != NULL && is_room((char*)input->content))
		{
			while (!ft_iswhitespace(str[i]) && str[i] != '\0')
				i++;
			if (ft_strcmp(str, (char*)input->content) == 0)
				return(0);
			if ((atoi_coordinates((char*)input->content) ==
				atoi_coordinates(str)))
				return (0);
		}
		input = input->next;
	}
	return (1);
}

static _Bool	valid_links(char *buf)
{
	int	i;
	int	links;

	i = -1;
	links = 0;
	while (buf[++i] != '\0')
	{
		if (links > 1 || buf[i] == '#' || ft_iswhitespace(buf[i]))
			return (0);
		links += buf[i] == '-' ? 1 : 0;
		if (buf[0] == 'L' || (buf[i] == '-' && buf[i + 1] == 'L'))
			return (0);
	}
	g_count_links++;
	return (links == 1 ? 1 : 0);
}

static _Bool	valid_rooms(char *buf)
{
	int	i;
	int	coordinates;

	i = 0;
	coordinates = 0;
	if (buf[0] == 'L')
		return (0);
	while (buf[i] != '\0')
	{
		while (!ft_iswhitespace(buf[i]) && buf[i] != '\0')
		{
			if (buf[i] == '#' || buf[i] == '\n' || buf[i] == '-')
				return (0);
			if (coordinates && !ft_isdigit((int)buf[i]))
				return (0);
			i++;
		}
		if (buf[i] != '\0' && (coordinates += ft_isdigit(buf[i + 1])) <= 0)
			return (0);
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
			return (0);
	g_count_ants = ft_atoi(buf);
	return (1);
}

t_list			*validation_and_write_in_lst(void)
{
	char	*buf;
	t_list	*head;

	buf = NULL;
	head = NULL;
	while (get_next_line(fd, &buf) > 0 && g_error_nbr < 0)
	{
		if (buf == NULL || buf[0] == '\n' || buf[0] == '\0')
			g_error_nbr = 0;
		if (is_comand(buf) && (g_start > 1 && g_end > 1))
			g_error_nbr = g_error_nbr > -1 ? g_error_nbr : 1;
		else if (g_count_ants == 0 && !valid_ants(buf))
			g_error_nbr = g_error_nbr > -1 ? g_error_nbr : 2;
		else if (is_room(buf) && (!valid_rooms(buf) || !uniq_rm_crd(buf, head)))
			g_error_nbr = g_error_nbr > -1 ? g_error_nbr : 3;
		else if (is_link(buf) && !valid_links(buf))
			g_error_nbr = g_error_nbr > -1 ? g_error_nbr : 4;
		else if (!g_count_ants && is_unknown(buf))
			g_error_nbr = g_error_nbr > -1 ? g_error_nbr : 5;
		write_in_list(&head, ft_lstnew(buf, (ft_strlen(buf) + 1)));
		ft_strdel(&buf);
	}
	//if (g_error_nbr >= 0 || !last_validation(head))
	//	ft_memdel((void**)&head);
	ft_strdel(&buf);
	return (head);
}
