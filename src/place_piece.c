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
#include "stdio.h"

int		placing_possible(t_map *map, t_piece *p, int i, int j)
{
	int		intersections;
	int		i_shift;
	int		j_shift;

	intersections = 0;
	i_shift = -1;
	while (++i_shift + p->i_start < p->i_end + 1)
	{
		j_shift = -1;
		while (++j_shift + p->j_start < p->j_end + 1)
		{
			if (p->layout[i_shift + p->i_start][j_shift + p->j_start] == '*')
			{
				if (i + i_shift >= map->h || j + j_shift >= map->w)
					return (0);
				if (map->field[i + i_shift][j + j_shift] == map->ch ||
			map->field[i + i_shift][j + j_shift] == map->ch - ('a' - 'A'))
					intersections++;
				if (map->field[i + i_shift][j + j_shift] == map->enemy_ch ||
			map->field[i + i_shift][j + j_shift] == map->enemy_ch - ('a' - 'A'))
					return (0);
			}
		}
	}
	return ((intersections == 1) ? 1 : 0);
}

int		find_solution(t_map *map, t_piece *piece, t_point *solution)
{
	int			i;
	int			j;
	int			temp;

	i = -1;
	temp = -1;
	while (++i < map->h)
	{
		j = -1;
		while (++j < map->w)
		{
			if (placing_possible(map, piece, i, j))
			{
				temp = count_dist(*map, *piece, i, j);
				if (temp < solution->min_dist)
				{
					solution->min_dist = temp;
					solution->i = i - piece->i_start;
					solution->j = j - piece->j_start;
				}
			}
		}
	}
	return ((temp == -1) ? 0 : 1);
}

void		print_map(char **map, int h)
{
	int		i;

	i = 0;
	while (i < h)
	{
		fprintf(stderr, "\t%s\n", map[i]);
		i++;
	}
	fprintf(stderr, "\n\n");
}


int		place_piece(int num)
{
	t_map		map;
	t_piece		piece;
	t_point		solution;

	map.field = read_map(&map.w, &map.h, 1);
	print_map(map.field, map.h);
	map.ch = (num == 1) ? 'o' : 'x';
	map.enemy_ch = (num == 1) ? 'x' : 'o';
	piece.layout = read_map(&piece.w, &piece.h, 0);
	solution.min_dist = 2147483647;
	trim_piece(&piece);
	if (!map.field || !piece.layout)
		return (-1);
	if (!find_solution(&map, &piece, &solution))
		return (1);
	ft_printf("%i %i\n", solution.i, solution.j);
	return (0);
}
