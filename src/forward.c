/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:22:30 by esouza            #+#    #+#             */
/*   Updated: 2018/07/13 09:10:04 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int				free_way(t_fill *f, int x, int y)
{
	while (++y < (*f).brd_y)
	{
		if ((*f).board[x][y] != 0)
			return (0);
	}
	return (1);
}

static int				find_position(t_fill *f)
{
	int	x;
	int	y;

	x = (*f).brd_x / 2;
	while (++x < (*f).brd_x)
	{
		y = -1;
		while (++y < (*f).brd_y)
		{
			if ((*f).board[x][y] == 2)
			{
				if (free_way(f, x, y))
				{
					(*f).lstp2_x = x;
					(*f).lstp2_y = y;
					return (1);
				}
			}
			else if ((*f).board[x][y] == 1)
				break ;
		}
	}
	return (0);
}

static int				check_all_down(t_fill *f)
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
	return (free_all(f, 1, 1, 1));
}

int						forward(t_fill *f)
{
	if ((*f).chess_x == 1)
	{
		if (find_position(f))
		{
			if (put_horizontally(f))
				return (check_all_down(f));
			else
				return (0);
		}
		else
			return (check_all_down(f));
	}
	else if ((*f).chess_y == 1)
	{
		if (vertically(f))
			return (check_all_down(f));
		return (0);
	}
	else
	{
		return (check_all_down(f));
	}
	return (1);
}
