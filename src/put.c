/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 18:11:39 by esouza            #+#    #+#             */
/*   Updated: 2018/07/13 09:24:48 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int				check_line(t_fill *f)
{
	int		y;
	int		x;
	int		enemy;
	int		flag;

	x = ((*f).brd_x % 2) + (*f).brd_x / 2;
	flag = 0;
	enemy = ((*f).mplayer == 1) ? 2 : 1;
	y = -1;
	while (++y < (*f).brd_y)
	{
		if ((*f).board[x][y] == enemy)
			return (0);
		else if ((*f).board[x][y] == (*f).mplayer)
			flag++;
		if ((((*f).brd_y - 1) - flag) < (*f).chess_y)
			return (0);
	}
	y = -1;
	while (++y < (*f).brd_y)
	{
		if ((*f).board[x][y] == (*f).mplayer)
			return (1);
	}
	return (0);
}

int				all_down(t_fill *f)
{
	int	x;
	int	y;

	x = -1;
	while (++x < (*f).brd_x)
	{
		y = -1;
		while (++y < (*f).brd_y)
		{
			if (compare2(f, x, y) == 1)
			{
				free_all(f, 0, 1, 0);
				ft_printf("%d %d\n", (x - (*f).bar_y),
						(y - (*f).bar_x));
				return (0);
			}
		}
	}
	return (42);
}

static int		calculate(t_fill *f)
{
	int		y;
	int		j;

	y = (*f).lstp2_y;
	j = (*f).chess_y;
	while (--j >= 0)
	{
		if ((*f).board[(*f).lstp2_x][--y] != 0)
			return (1);
	}
	if ((y + 1) >= 0)
	{
		free_all(f, 0, 1, 0);
		ft_printf("%d %d\n", (*f).lstp2_x - (*f).bar_y,
				(y + 1) - (*f).bar_x);
		return (0);
	}
	return (1);
}

int				put(t_fill *f)
{
	int	y;
	int	j;

	j = (*f).chess_y;
	y = check_line(f);
	if ((((*f).brd_y - 1) - (y)) >= ((*f).chess_y - 1) &&
			compare2(f, (*f).lstp2_x, y) == 1)
	{
		free_all(f, 0, 1, 0);
		ft_printf("%d %d\n", (*f).lstp2_x - (*f).bar_y, (y) - (*f).bar_x);
		return (0);
	}
	else if (((*f).brd_y - 1) - (*f).lstp2_y >= 0)
		return (calculate(f));
	return (1);
}
