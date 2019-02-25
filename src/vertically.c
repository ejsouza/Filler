/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertically.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 18:35:41 by esouza            #+#    #+#             */
/*   Updated: 2018/07/13 09:26:15 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		finder(t_fill *f)
{
	int	x;
	int	y;

	x = (*f).brd_x;
	while (--x >= 0)
	{
		y = -1;
		while (++y < (*f).brd_y)
		{
			if ((*f).board[x][y] == 2)
			{
				(*f).lstp2_x = x;
				(*f).lstp2_y = y;
				return (0);
			}
		}
	}
	return (0);
}

static void		fuckingnorme(t_fill *f)
{
	ft_printf("%d %d\n", ((*f).lstp2_x - (*f).bar_y),
			(*f).lstp2_y - (*f).bar_x);
}

int				vertically(t_fill *f)
{
	int		x;
	int		count;
	int		len;

	finder(f);
	if (((*f).lstp2_x + ((*f).chess_x - 1) < (*f).brd_x))
	{
		x = (*f).lstp2_x;
		count = 0;
		len = (*f).chess_x - 1;
		while (--len >= 0 && (x + 1) < (*f).brd_x)
		{
			if ((*f).board[x++][(*f).lstp2_y] == 2)
				count++;
			else if ((*f).board[x++][(*f).lstp2_y] == 1)
				count += 2;
		}
		if (count == 1)
		{
			free_all(f, 0, 1, 0);
			fuckingnorme(f);
			return (0);
		}
	}
	return (1);
}
