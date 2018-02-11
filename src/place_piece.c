/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 18:20:34 by akorunsk          #+#    #+#             */
/*   Updated: 2018/02/07 16:49:15 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdio.h> //

int		placing_possible(t_map *map, t_piece *p, int i, int j)
{
	int		intersections;
	int		i_shift;
	int		j_shift;

	intersections = 0;
	i_shift = 0;
	while (i_shift < p->h)
	{
		if (i + i_shift >= map->h)
			return (0);
		j_shift = 0;
		while (j_shift < p->w)
		{
			if (j + j_shift >= map->w)
				return (0);
			if (p->layout[i_shift][j_shift] == '*')
			{
				if (map->field[i + i_shift][j + j_shift] == map->ch ||
				map->field[i + i_shift][j + j_shift] == map->ch - ('a' - 'A'))
					intersections++;
				else if (map->field[i + i_shift][j + j_shift] == map->enemy_ch ||
				map->field[i + i_shift][j + j_shift] == map->enemy_ch - ('a' - 'A'))
					return (0);
			}
			j_shift++;
		}
		i_shift++;
	}
	return ((intersections == 1) ? 1 : 0);
}

int		place_piece(int num)
{
	int			i;
	int			j;
	t_map		map;
	t_piece 	piece;
//	t_point		solution;
	
	map.field = read_map(&map.w, &map.h, 1);
	map.ch = (num == 1) ? 'o' : 'x';
	map.enemy_ch = (num == 1) ? 'x' : 'o';
	piece.layout = read_map(&piece.w, &piece.h, 0);
	if (!map.field || !piece.layout)
		return (-1);
	i = 0;
	while (i < map.h)
	{
		j = 0;
		while (j < map.w)
		{
			if (placing_possible(&map, &piece, i, j))
			{
				ft_printf("%i %i\n", i, j);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
