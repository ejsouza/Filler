/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_horizontally.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:15:06 by esouza            #+#    #+#             */
/*   Updated: 2018/07/13 09:16:35 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		put_right(t_fill *f)
{
	int	y;
	int	len;

	y = (*f).lstp2_y;
	len = (*f).chess_y - 1;
	while (--len >= 0 && ++y < (*f).brd_y)
	{
		if ((*f).board[(*f).lstp2_x][y] != 0)
			return (1);
	}
	if (len == -1)
	{
		free_all(f, 0, 1, 0);
		ft_printf("%d %d\n", (*f).lstp2_x - (*f).bar_y,
				(*f).lstp2_y - (*f).bar_x);
		return (0);
	}
	return (1);
}

static int		put_left(t_fill *f)
{
	int	y;
	int	len;

	while ((*f).board[(*f).lstp2_x][(*f).lstp2_y] == 2)
		(*f).lstp2_y--;
	(*f).lstp2_y++;
	y = (*f).lstp2_y;
	len = (*f).chess_y - 1;
	while (--len >= 0 && --y >= 0)
	{
		if ((*f).board[(*f).lstp2_x][y] != 0)
			return (1);
	}
	if (len == -1)
	{
		free_all(f, 0, 1, 0);
		ft_printf("%d %d\n", (*f).lstp2_x - (*f).bar_y,
				(*f).lstp2_y - ((*f).chess_y - 1) - (*f).bar_x);
		return (0);
	}
	return (1);
}

int				put_horizontally(t_fill *f)
{
	if ((*f).lstp2_y + ((*f).chess_y - 1) < (*f).brd_y)
	{
		if (put_right(f))
			if (put_left(f))
				return (1);
	}
	else
	{
		if (put_left(f))
			return (1);
	}
	return (0);
}
