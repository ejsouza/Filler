/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:26:58 by esouza            #+#    #+#             */
/*   Updated: 2018/07/13 09:46:13 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		initialize_struct(t_fill *f)
{
	(*f).mplayer = 0;
	(*f).brd_x = 0;
	(*f).brd_y = 0;
	(*f).chess_x = 0;
	(*f).chess_y = 0;
	(*f).bar_x = 0;
	(*f).bar_y = 0;
	(*f).board = NULL;
}

int				main(void)
{
	t_fill f;

	initialize_struct(&f);
	while (1)
	{
		if (parser(&f) > 1)
		{
			return (1);
		}
	}
	return (0);
}
