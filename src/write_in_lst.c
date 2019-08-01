/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_in_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:06:39 by solefir           #+#    #+#             */
/*   Updated: 2019/08/01 15:06:54 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	write_in_list(t_list **head, t_list *new)
{
	t_list	*temp;

	temp = *head;
	if (*head == NULL)
		*head = new;
	else
    {
	    while ((*head)->next != NULL)
	        (*head) = (*head)->next;
	    (*head)->next = new;
	    *head = temp;
    }
}
