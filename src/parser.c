/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:27:56 by esouza            #+#    #+#             */
/*   Updated: 2018/07/13 09:13:52 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		get_board_dimention(t_fill *f)
{
	short	x;
	char	*tmp;

	x = 8;
	tmp = NULL;
	while (get_next_line(0, &tmp))
	{
		if ((ft_strncmp("Plateau", tmp, 7) == 0))
		{
			(*f).brd_x = ft_atoi(&tmp[x]);
			x += ft_intlen((*f).brd_x);
			(*f).brd_y = ft_atoi(&tmp[x]);
			free(tmp);
			break ;
		}
		else
		{
			free(tmp);
		}
	}
	return (0);
}

int		parser(t_fill *f)
{
	if ((*f).mplayer == 0)
		return (get_player(f));
	else if ((*f).brd_x == 0)
		return (get_board_dimention(f));
	else if ((*f).mplayer > 0)
		return (create_board(f));
	return (0);
}
