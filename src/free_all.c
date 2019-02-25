/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:23:23 by esouza            #+#    #+#             */
/*   Updated: 2018/07/08 15:55:23 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		free_board(t_fill *f)
{
	int	x;

	x = -1;
	while (++x < (*f).b_x)
	{
		free((*f).board[x]);
	}
	free((*f).board);
}

static void		free_chessman(t_fill *f)
{
	int	x;

	x = -1;
	while (++x < (*f).c_x)
	{
		free((*f).chess[x]);
	}
	free((*f).chess);
}

int				free_all(t_fill *f, _Bool b, _Bool c, _Bool p)
{
	if (b)
		free_board(f);
	if (c)
		free_chessman(f);
	if (p == 1)
	{
		ft_printf("0 0\n");
		return (42);
	}
	return (0);
}
