/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 10:31:14 by esouza            #+#    #+#             */
/*   Updated: 2018/06/07 10:20:00 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		check_data_player(char **line)
{
	if ((ft_strncmp("# -------------- VM  version", *line, 27) == 0))
		return (0);
	else if ((ft_strcmp("#                                              #",
					*line) == 0))
		return (0);
	else if ((ft_strcmp("# 42 / filler VM Developped by: Hcao - Abanlin #",
					*line) == 0))
		return (0);
	else if ((ft_strcmp("# -------------------------------------------- #",
					*line) == 0))
		return (0);
	else if ((ft_strncmp("launched ./players/", *line, 19) == 0))
		return (0);
	else if ((ft_strncmp("$$$ exec p1 : [./players/", *line, 25) == 0))
		return (0);
	else if ((ft_strncmp("$$$ exec p2 : [./players/", *line, 25) == 0))
		return (0);
	else if ((ft_strncmp("Plateau", *line, 7) == 0))
		return (0);
	else if ((ft_strncmp("Piece", *line, 5) == 0))
		return (0);
	else if ((ft_strcmp("    01234567890123456", *line) == 0))
		return (0);
	return (1);
}
