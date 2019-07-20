/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:14:24 by solefir           #+#    #+#             */
/*   Updated: 2019/07/20 21:06:05 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

_Bool       is_room(char *str)
{
    while (!ft_iswhitespace((int)buf[--i]));
		is_room = (ft_isdigit((int)buf[i + 1]) && buf[i] == ' ') ? 1 : 0;
		
}
_Bool       uniq_coordinates(char *str, t_list *input);
_Bool       is_link(char *str);
_Bool       is_comand(char *str);
_Bool       is_comment(char *str);
