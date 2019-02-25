/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:52:14 by esouza            #+#    #+#             */
/*   Updated: 2018/07/13 09:23:37 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int			check_input(char **tmp)
{
	if (check_data_player(&(*tmp)))
	{
		free(*tmp);
		ft_printf("FATAL ERROR, invalid input\n");
		return (42);
	}
	return (0);
}

static int			player(t_fill *f, char **tmp)
{
	if ((ft_strcmp("$$$ exec p1 : [./players/esouza.filler]", *tmp) == 0))
		(*f).mplayer = 1;
	else if ((ft_strcmp("$$$ exec p1 : [../esouza.filler]", *tmp) == 0))
		(*f).mplayer = 1;
	else if ((ft_strcmp("$$$ exec p1 : [./esouza.filler]", *tmp) == 0))
		(*f).mplayer = 1;
	else if ((ft_strncmp("$$$ exec p2 : [./players/esouza.", *tmp, 32) == 0) ||
			(ft_strncmp("$$$ exec p2 : [../esouza.filler", *tmp, 31) == 0 ||
			(ft_strcmp("$$$ exec p2 : [./esouza.filler]", *tmp) == 0)))
	{
		(*f).mplayer = 2;
		(*f).lstp1_x = (*f).brd_x;
		(*f).lstp1_y = (*f).brd_y;
	}
	if ((*f).mplayer > 0)
		return (1);
	return (0);
}

int					get_player(t_fill *f)
{
	short	x;
	char	*tmp;

	x = 0;
	tmp = NULL;
	while ((*f).mplayer == 0)
	{
		get_next_line(0, &tmp);
		if (player(f, &tmp))
			;
		else
			return (check_input(&tmp));
		free(tmp);
		tmp = NULL;
	}
	return (0);
}

static int			malloc_board(t_fill *f)
{
	int		x;
	int		y;

	x = 0;
	if (!((*f).board = (int **)malloc(sizeof(int **) * (*f).brd_x)))
		return (1);
	while (x < (*f).brd_x)
	{
		if (!((*f).board[x] = (int *)malloc(sizeof(int *) * (*f).brd_y)))
			return (1);
		x++;
	}
	x = 0;
	while (x < (*f).brd_x)
	{
		y = 0;
		while (y < (*f).brd_y)
		{
			(*f).board[x][y] = 0;
			y++;
		}
		x++;
	}
	return (0);
}

int					create_board(t_fill *f)
{
	char	*tmp;

	tmp = NULL;
	if ((*f).chess_x == 0)
		if (malloc_board(f))
			return (42);
	while (get_next_line(0, &tmp))
	{
		if (tmp[0] >= '0' && tmp[0] <= '9')
			update_board(f, &tmp);
		else if (tmp[0] == ' ' && tmp[1] == ' ' && tmp[2] == ' ')
			;
		else if ((ft_strncmp("Piece", tmp, 5) == 0))
		{
			get_chessman(f, &tmp);
			free(tmp);
			tmp = NULL;
			search_place(f);
		}
		free(tmp);
		tmp = NULL;
		if ((*f).lstp1_x > 0)
			(*f).lstp1_x = 0;
	}
	return (42);
}
