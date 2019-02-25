/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:22:19 by esouza            #+#    #+#             */
/*   Updated: 2018/07/08 15:58:58 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int			last_ahead_try(t_fill *f)
{
	int		x;
	int		y;

	x = 0;
	while (x < (*f).brd_x)
	{
		y = (*f).brd_y - 1;
		while (y >= 0)
		{
			if (compare(f, x, y) == 1)
			{
				free_all(f, 0, 1, 0);
				ft_printf("%d %d\n", (x - (*f).bar_y),
						(y - (*f).bar_x));
				return (0);
			}
			y--;
		}
		x++;
	}
	return (1);
}

static int			last_back_try(t_fill *f)
{
	int		x;
	int		y;

	x = ((*f).lstp1_x > (*f).lstp2_x) ? (*f).lstp2_x : (*f).lstp1_x;
	while (x >= 0)
	{
		y = (*f).brd_y - 1;
		while (y >= 0)
		{
			if (compare(f, x, y) == 1)
			{
				free_all(f, 0, 1, 0);
				ft_printf("%d %d\n", (x - (*f).bar_y),
						(y - (*f).bar_x));
				return (0);
			}
			y--;
		}
		x--;
	}
	return (1);
}

static int			start_point(t_fill *f)
{
	int		x;
	int		y;

	x = ((*f).lstp1_x < (*f).lstp2_x) ? (*f).lstp2_x : (*f).lstp1_x;
	while (x >= 0)
	{
		y = (*f).brd_y - 1;
		while (y >= 0)
		{
			if (compare(f, x, y) == 1)
			{
				free_all(f, 0, 1, 0);
				ft_printf("%d %d\n", (x - (*f).bar_y),
						(y - (*f).bar_x));
				return (0);
			}
			y--;
		}
		x--;
	}
	if (last_back_try(f))
		last_ahead_try(f);
	return (free_all(f, 1, 1, 1));
}

static int			end_point(t_fill *f)
{
	int		x;
	int		y;

	x = ((*f).lstp1_x > (*f).lstp2_x) ? (*f).lstp2_x : (*f).lstp1_x;
	while ((x + (*f).chess_x) < (*f).brd_x)
	{
		y = (*f).brd_y - 1;
		while (y >= 0)
		{
			if (compare(f, x, y) == 1)
			{
				free_all(f, 0, 1, 0);
				ft_printf("%d %d\n", (x - (*f).bar_y),
						(y - (*f).bar_x));
				return (0);
			}
			y--;
		}
		x++;
	}
	if (last_ahead_try(f))
		last_back_try(f);
	return (free_all(f, 1, 1, 1));
}

int					path(t_fill *f)
{
	int		x;

	position_in_board_1(f);
	position_in_board_2(f);
	if ((*f).mplayer == 1)
	{
		if (straight(f) == 1)
		{
			if ((*f).lstp1_x < (*f).lstp2_x)
				return (start_point(f));
			else if ((*f).lstp1_x > (*f).lstp2_x)
				return (end_point(f));
			else
				last_ahead_try(f);
		}
	}
	else if ((*f).mplayer == 2)
	{
		x = forward(f);
		if (x == 1)
			return (all_down(f));
		else
			return (0);
	}
	return (1);
}
