/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   straight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:22:08 by esouza            #+#    #+#             */
/*   Updated: 2018/07/08 13:53:31 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		fuckingnorme(t_fill *f, int x, int p)
{
	free_all(f, 0, 1, 0);
	ft_printf("%d %d\n", x - (*f).bar_y, p - (*f).bar_x);
	return (0);
}

static int		put_locally(t_fill *f)
{
	int		j;
	int		p;
	int		x;
	int		flag;

	x = ((*f).brd_x % 2) + ((*f).brd_x / 2);
	p = 0;
	while ((p + (*f).chess_y) < (*f).brd_y)
	{
		j = -1;
		flag = 0;
		while (++j < (*f).chess_y)
		{
			if ((*f).board[x][j + p] == (*f).mplayer &&
					(*f).chess[0][j] == (*f).mplayer)
				flag++;
		}
		if (flag == 1)
			return (fuckingnorme(f, x, p));
		p++;
	}
	free_all(f, 1, 1, 1);
	return (1);
}

static int		check_all_up(t_fill *f)
{
	int		x;
	int		y;

	x = (*f).brd_x;
	while (--x >= 0)
	{
		y = (*f).brd_y;
		while (--y >= 0)
		{
			if (compare(f, x, y) == 1)
			{
				free_all(f, 0, 1, 0);
				ft_printf("%d %d\n", (x - (*f).bar_y),
						(y - (*f).bar_x));
				return (0);
			}
		}
	}
	return (free_all(f, 1, 1, 1));
}

int				straight(t_fill *f)
{
	if ((*f).chess_x == 1)
	{
		if (check_line(f))
			put_locally(f);
		else
			check_all_up(f);
		return (0);
	}
	else if ((*f).chess_y == 1)
	{
		if (all_way_up(f))
			return (check_all_up(f));
		else
			return (0);
	}
	else
	{
		check_all_up(f);
		return (0);
	}
	return (1);
}
