/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:09:03 by esouza            #+#    #+#             */
/*   Updated: 2018/05/28 15:09:19 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(int nb)
{
	int	i;

	i = 0;
	if (nb == i)
		return (1);
	while (nb)
	{
		i++;
		nb /= 10;
	}
	return (i);
}
