/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shrink_chessman.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 18:31:51 by esouza            #+#    #+#             */
/*   Updated: 2018/07/07 18:33:15 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		shrink_col(t_fill *f)
{
	int		x;
	int		y;

	x = 0;
	while (x < (*f).chess_x)
	{
		y = 0;
		while (y < ((*f).chess_y))
		{
			(*f).chess[x][y] = (*f).chess[x][y + 1];
			y++;
		}
		x++;
	}
}

void			shrink_row(t_fill *f)
{
	int		x;
	int		y;

	x = 0;
	while (x < (*f).chess_x - 1)
	{
		y = 0;
		while (y < (*f).chess_y)
		{
			(*f).chess[x][y] = (*f).chess[x + 1][y];
			y++;
		}
		x++;
	}
}

void			check_col(t_fill *f)
{
	int		x;
	int		y;

	x = 0;
	y = (*f).chess_y;
	while ((*f).chess[x++][0] == 0)
	{
		if (x == (*f).chess_x)
		{
			x = 0;
			y--;
			shrink_col(f);
		}
	}
	(*f).bar_x = (*f).chess_y - y;
	x = 0;
	while ((*f).chess[x++][y - 1] == 0)
	{
		if (x == (*f).chess_x)
		{
			x = 0;
			y--;
		}
	}
	(*f).chess_y = y;
}

void			check_row(t_fill *f)
{
	int		x;
	int		y;

	y = 0;
	x = (*f).chess_x;
	while ((*f).chess[0][y++] == 0)
	{
		if (y == (*f).chess_y)
		{
			y = 0;
			x--;
			shrink_row(f);
		}
	}
	(*f).bar_y = (*f).chess_x - x;
	y = 0;
	while ((*f).chess[x - 1][y++] == 0)
	{
		if (y == (*f).chess_y)
		{
			y = 0;
			x--;
		}
	}
	(*f).chess_x = x;
}
