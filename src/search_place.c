/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:51:00 by esouza            #+#    #+#             */
/*   Updated: 2018/07/08 14:20:14 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		position_in_board_1(t_fill *f)
{
	int		x;
	int		y;

	x = 0;
	while (x < (*f).brd_x)
	{
		y = 0;
		while (y < (*f).brd_y)
		{
			if ((*f).board[x][y] == 1)
			{
				(*f).lstp1_x = x;
				(*f).lstp1_y = y;
			}
			y++;
		}
		x++;
	}
	return (0);
}

int		position_in_board_2(t_fill *f)
{
	int		x;
	int		y;

	x = 0;
	while (x < (*f).brd_x)
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
		x++;
	}
	return (0);
}

int		search_place(t_fill *f)
{
	(*f).c_x = (*f).chess_x;
	(*f).b_x = (*f).brd_x;
	check_col(f);
	check_row(f);
	path(f);
	return (0);
}
