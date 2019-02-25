/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_way_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:23:53 by esouza            #+#    #+#             */
/*   Updated: 2018/07/08 15:53:29 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		find_upper_position(t_fill *f)
{
	int		x;
	int		y;

	x = -1;
	position_in_board_2(f);
	while (++x < (*f).lstp2_x)
	{
		y = (*f).brd_y - 1;
		while (y > 0)
		{
			if ((*f).board[x][y] == 1)
			{
				(*f).lstp1_x = x;
				(*f).lstp1_y = y;
				return (0);
			}
			y--;
		}
	}
	return (0);
}

static int		find_lowermost_position(t_fill *f)
{
	int		x;
	int		y;

	x = (*f).brd_x;
	position_in_board_2(f);
	while (--x > (*f).lstp1_x)
	{
		y = 0;
		while (y < (*f).brd_y)
		{
			if ((*f).board[x][y] == 2)
			{
				(*f).lstp2_x = x;
				(*f).lstp2_y = y;
				return (0);
			}
			y++;
		}
	}
	return (0);
}

static int		go_right(t_fill *f, int x, int y)
{
	while (y++ < (*f).brd_y && (*f).board[x][y] == (*f).mplayer)
		;
	y--;
	if ((x - ((*f).chess_x - 1) > 0))
	{
		free_all(f, 0, 1, 0);
		ft_printf("%d %d\n", ((x - ((*f).chess_x - 1)) - (*f).bar_y),
				(y) - (*f).bar_x);
		return (0);
	}
	return (1);
}

int				all_way_up(t_fill *f)
{
	if ((*f).mplayer == 1)
	{
		find_upper_position(f);
		if ((*f).lstp1_x < (*f).lstp2_x)
			return (go_right(f, (*f).lstp1_x, (*f).lstp1_y));
	}
	else if ((*f).mplayer == 2)
	{
		find_lowermost_position(f);
		if ((*f).lstp1_x < (*f).lstp2_x)
			return (go_right(f, (*f).lstp2_x, (*f).lstp2_y));
	}
	return (1);
}
