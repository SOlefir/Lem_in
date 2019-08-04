/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 20:44:09 by solefir           #+#    #+#             */
/*   Updated: 2019/07/26 16:51:24 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <stdio.h>

void	test(t_list *input)
{
    t_list  *temp;

    temp = input;
	if (temp == NULL)
		printf("input == NULL\n");
	else
	{
		while (temp != NULL)
		{
			printf("%s\n", (char *)temp->content);
			temp = temp->next;
		}
	}
}
