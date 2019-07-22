/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 20:44:09 by solefir           #+#    #+#             */
/*   Updated: 2019/07/22 15:54:32 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <stdio.h>

void	test(t_list *input)
{
	if (input != NULL)
	{
		while (input)
		{
			printf("%s\n", (char*)input->content);
			input = input->next;
		}
	}
	else
		printf("input == NULL\n");
}
