/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 20:44:09 by solefir           #+#    #+#             */
/*   Updated: 2019/07/24 19:29:17 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <stdio.h>

void	test(t_list *input)
{
    t_list  *temp;

    temp = input->next;
	if (temp == NULL)
		printf("input == NULL\n");
    temp = temp->next;
	while (temp->next != NULL)
	{
		printf("%s\n", (char*)temp->content);
		//input = input->next;
	}
}
