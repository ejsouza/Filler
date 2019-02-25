/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:28:29 by esouza            #+#    #+#             */
/*   Updated: 2018/07/13 09:14:39 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		compare(t_fill *f, int lstp1_x, int lstp1_y)
{
	int		x;
	int		y;
	int		count;

	x = -1;
	count = 0;
	while (++x < (*f).chess_x && ((x + lstp1_x) < (*f).brd_x))
	{
		y = -1;
		while (++y < (*f).chess_y && ((y + lstp1_y) < (*f).brd_y))
		{
			if ((*f).chess[x][y] != 0 &&
					((*f).board[x + lstp1_x][y + lstp1_y] != 0))
				count++;
			if ((x + lstp1_x > (*f).brd_x - 1 || y + lstp1_y > (*f).brd_y - 1))
				count += 2;
			if ((lstp1_x + (*f).chess_x) > (*f).brd_x || lstp1_y +
					(*f).chess_y > (*f).brd_y)
				count += 2;
			if ((*f).chess[x][y] != 0 &&
					((*f).board[x + lstp1_x][y + lstp1_y] == 2))
				count += 2;
		}
	}
	return (count);
}

int		compare2(t_fill *f, int lstp2_x, int lstp2_y)
{
	int		x;
	int		y;
	int		count;

	x = -1;
	count = 0;
	while (++x < (*f).chess_x && ((x + lstp2_x) < (*f).brd_x))
	{
		y = -1;
		while (++y < (*f).chess_y && ((y + lstp2_y) < (*f).brd_y))
		{
			if ((*f).chess[x][y] != 0 &&
					((*f).board[x + lstp2_x][y + lstp2_y] != 0))
				count++;
			if ((x + lstp2_x > (*f).brd_x - 1 || y + lstp2_y > (*f).brd_y - 1))
				count += 2;
			if ((lstp2_x + (*f).chess_x) > (*f).brd_x || lstp2_y +
					(*f).chess_y > (*f).brd_y)
				count += 2;
			if ((*f).chess[x][y] != 0 &&
					((*f).board[x + lstp2_x][y + lstp2_y] == 1))
				count += 2;
		}
	}
	return (count);
}
