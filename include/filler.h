/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 17:33:29 by akorunsk          #+#    #+#             */
/*   Updated: 2018/02/07 16:41:43 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

typedef	struct		s_map
{
	char	**field;
	int		w;
	int		h;
	char	ch;
	char	enemy_ch;
}					t_map;

typedef struct		s_piece
{
	char	**layout;
	int		w;
	int		h;
	int		i_start;
	int		i_end;
	int		j_start;
	int		j_end;
}					t_piece;

typedef struct		s_point
{
	int		i;
	int		j;
	int		min_dist;
}					t_point;

int					place_piece(int num);

char				**read_map(int *w, int *h, int is_map);

void				trim_piece(t_piece *p);

int					count_dist(t_map m, t_piece p, int ins_i, int ins_j);

#endif
