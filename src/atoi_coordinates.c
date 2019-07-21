/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 20:10:16 by solefir           #+#    #+#             */
/*   Updated: 2019/07/21 20:13:40 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		atoi_coordinates(char *str)
{
	int	i;
	int	len;
	int	nbr;
	int	n;

	i = 0;
	len = 1;
	nbr = 0;
	while (!ft_iswhitespace((int)str[i]))
		i++;
	while (str[++i] != '\0')
	{
		if (ft_iswhitespace((int)str[i]))
			i++;
		n = '0' + str[i];
		nbr *= len;
		nbr += n;
		len *= 10;
		i++;
	}
	return (nbr);
}
