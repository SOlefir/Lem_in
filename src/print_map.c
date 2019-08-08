/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 20:44:09 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 20:14:09 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_map(t_list *input)
{
	t_list	*temp;

	temp = input;
	if (temp == NULL)
		ft_printf("input == NULL\n");
	else
	{
		while (temp != NULL)
		{
			ft_printf("%s\n", (char *)temp->content);
			temp = temp->next;
		}
	}
}
