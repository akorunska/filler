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

int		placing_possible(t_map *map, t_piece *p, int ins_i, int ins_j)
{
	int		i;
	int		j;
	int		map_j;
	int		intersections;

	intersections = 0;
	i = p->i_start - 1;
	while (++i <= p->i_end)
	{
		j = p->j_start - 1;
		while (++j <= p->j_end)
		{
			map_j = ins_j + j - p->j_start;
			if (p->layout[i][j] == '*')
			{
				if (!check_coords(map, ins_i + i - p->i_start, map_j) ||
	map->field[ins_i + i - p->i_start][map_j] == map->enemy_ch - ('a' - 'A'))
					return (0);
				if (map->field[ins_i + i - p->i_start][map_j] != '.')
					intersections += 1;
			}
		}
	}
	return ((intersections == 1) ? 1 : 0);
}

void	try_placing(int temp, t_point *solution, int i, int j)
{
	if (temp <= solution->min_dist)
	{
		solution->i = i;
		solution->j = j;
		solution->min_dist = temp;
	}
}

int		find_solution(t_map map, t_piece piece, t_point *solution)
{
	int			i;
	int			j;
	int			temp;
	t_map		*map_cpy;

	temp = -1;
	i = -1;
	while (++i < map.h)
	{
		j = -1;
		while (++j < map.w)
		{
			if (placing_possible(&map, &piece, i, j) &&
			check_coords(&map, i - piece.i_start, j - piece.j_start))
			{
				map_cpy = copy_map(&map);
				temp = count_dist(map_cpy, &piece, \
					i - piece.i_start, j - piece.j_start);
				free_map(map_cpy);
				try_placing(temp, solution, \
					i - piece.i_start, j - piece.j_start);
			}
		}
	}
	return ((temp == -1) ? 0 : 1);
}

int		place_piece(int num)
{
	t_map		map;
	t_piece		piece;
	t_point		solution;
	int			rv;

	map.field = read_map(&map.w, &map.h, 1);
	map.ch = (num == 1) ? 'o' : 'x';
	map.enemy_ch = (num == 1) ? 'x' : 'o';
	piece.layout = read_map(&piece.w, &piece.h, 0);
	trim_piece(&piece);
	solution.min_dist = 2147483647;
	if (!map.field || !piece.layout)
		return (-1);
	rv = find_solution(map, piece, &solution);
	output_result(&solution, rv);
	free_field(map.field, map.h);
	free_field(piece.layout, piece.h);
	return (!rv);
}
