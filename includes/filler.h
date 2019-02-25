/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 20:09:25 by esouza            #+#    #+#             */
/*   Updated: 2018/07/08 14:17:37 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

typedef struct		s_fill
{
	int				mplayer;
	int				brd_x;
	int				brd_y;
	int				chess_x;
	int				chess_y;
	int				lstp1_x;
	int				lstp1_y;
	int				lstp2_x;
	int				lstp2_y;
	int				bar_x;
	int				bar_y;
	int				**board;
	int				**chess;
	int				c_x;
	int				b_x;
}					t_fill;

int					parser(t_fill *f);
int					get_player(t_fill *f);
int					get_board_dimention(t_fill *f);
int					create_board(t_fill *f);
int					update_board(t_fill *f, char **tmp);
int					update_last_position(t_fill *f, int i, int j);
int					check_data_player(char **line);
void				get_chessman(t_fill *f, char **tmp);
int					search_place(t_fill *f);
int					compare(t_fill *f, int lstp_x, int lstp_y);
int					compare2(t_fill *f, int lstp_x, int lstp_y);
void				check_col(t_fill *f);
void				check_row(t_fill *f);
int					path(t_fill *f);
int					straight(t_fill *f);
int					forward(t_fill *f);
int					all_way_up(t_fill *f);
int					position_in_board_1(t_fill *f);
int					position_in_board_2(t_fill *f);
void				print_chessman(t_fill *f);
int					vertically(t_fill *f);
int					free_all(t_fill *f, _Bool b, _Bool c, _Bool p);
int					put(t_fill *f);
int					all_down(t_fill *f);
int					check_line(t_fill *f);
int					put_horizontally(t_fill *f);

#endif
