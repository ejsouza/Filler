/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 18:33:34 by esouza            #+#    #+#             */
/*   Updated: 2018/07/07 22:24:02 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int				update_board(t_fill *f, char **tmp)
{
	int		i;
	int		x;

	i = 0;
	while ((*tmp)[i] == '0')
		i++;
	x = ft_atoi(&(*tmp)[i]);
	while ((*tmp)[i])
	{
		if ((*tmp)[i] == 'O')
			(*f).board[x][i - 4] = 1;
		else if ((*tmp)[i] == 'X')
			(*f).board[x][i - 4] = 2;
		i++;
	}
	return (0);
}

static int		malloc_chess(t_fill *f)
{
	int		x;
	int		y;

	x = 0;
	if (!((*f).chess = (int **)malloc(sizeof(int **) * (*f).chess_x)))
		return (42);
	while (x < (*f).chess_x)
	{
		if (!((*f).chess[x] = (int *)malloc(sizeof(int *) *
						(*f).chess_y)))
			return (42);
		x++;
	}
	x = 0;
	while (x < (*f).chess_x)
	{
		y = 0;
		while (y < (*f).chess_y)
		{
			(*f).chess[x][y] = 0;
			y++;
		}
		x++;
	}
	return (0);
}

void			get_chessman(t_fill *f, char **tmp)
{
	int		i;
	int		j;
	char	*tab;

	i = 6;
	tab = NULL;
	(*f).chess_x = ft_atoi(&(*tmp)[i]);
	i += ft_intlen((*f).chess_x);
	(*f).chess_y = ft_atoi(&(*tmp)[i]);
	malloc_chess(f);
	i = -1;
	while (++i < (*f).chess_x)
	{
		j = 0;
		get_next_line(0, &tab);
		while (tab[j])
		{
			if (tab[j] == '*')
				(*f).chess[i][j] = 1;
			else
				(*f).chess[i][j] = 0;
			j++;
		}
		free(tab);
	}
}
