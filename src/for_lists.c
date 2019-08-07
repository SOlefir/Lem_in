/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 12:55:14 by solefir           #+#    #+#             */
/*   Updated: 2019/08/07 21:57:59 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_way		*copy_list(t_way *meta)
{

}

t_way		*new_list(int id, t_way *parent)
{
	t_way	*new;

	new = malloc(sizeof(t_way));
	new->id = id;
	new->len = 0;
	new->parent = parent;
	new->next = NULL;
	return (new);
}

int			len_way(t_way *way)
{
	int		n;

	n = 0;
	while ((way = way->parent))
		n++;
	return (n);
}

void		del_list(t_way **list)
{
	t_way	*next_node;

	if (list != NULL)
	{
		while (*list != NULL)
		{
			next_node = (*list)->next;
			free(*list);
			*list = next_node;
		}
		list = NULL;
	}
}

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
