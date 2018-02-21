/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_dist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 12:09:31 by akorunsk          #+#    #+#             */
/*   Updated: 2018/02/16 12:09:33 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h> //

void		insert_piece(t_map *m, t_piece *p, int ins_i, int ins_j)
{
	int		i;
	int		j;

	i = -1;
	while (++i < p->h)
	{
		j = -1;
		while (++j < p->w)
		{
			if (p->layout[i][j] == '*')
				m->field[i + ins_i][j + ins_j] = '*';
		}
	}
}

int		check_put(t_map *map, int i, int j)
{
	if (i < 0 || i >= map->h || j < 0 || j >= map->w)
		return (-1);
	if (map->field[i][j] == map->enemy_ch ||
		map->field[i][j] == map->enemy_ch - ('a' - 'A'))
		return (0);
	if (map->field[i][j] == map->ch ||
		map->field[i][j] == map->ch - ('a' - 'A') || map->field[i][j] == '.')
		map->field[i][j] = '#';
	return (1);
}

int		insert_around(t_map *m, int i, int j)
{
	if (!check_put(m, i - 1, j - 1))
		return (0);
	if (!check_put(m, i - 1, j))
		return (0);
	if (!check_put(m, i - 1, j + 1))
		return (0);
	if (!check_put(m, i, j - 1))
		return (0);
	if (!check_put(m, i, j + 1))
		return (0);
	if (!check_put(m, i + 1, j - 1))
		return (0);
	if (!check_put(m, i + 1, j))
		return (0);
	if (!check_put(m, i + 1, j + 1))
		return (0);
	return (1);
}

void	replase_stars(t_map *m)
{
	int		i;
	int		j;

	i = -1;
	while (++i < m->h)
	{
		j = -1;
		while (++j < m->w)
		{
			if (m->field[i][j] == '#')
				m->field[i][j] = '*';
		}
	}
}

int		count_dist(t_map *m, t_piece *p, int ins_i, int ins_j)
{
	int		i;
	int		j;
	int		occured;
	int		wave;

	insert_piece(m, p, ins_i, ins_j);
	occured = 0;
	wave = 0;
	while (!occured)
	{
		i = -1;
		while (++i < m->h && !occured)
		{
			j = -1;
			while (++j < m->w && !occured)
			{
				if (m->field[i][j] == '*')
					if (!insert_around(m, i, j))
						occured = 1;
			}
		}
		replase_stars(m);
		wave++;
	}
	return (wave);
}