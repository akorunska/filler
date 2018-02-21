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
#include "stdio.h" //

int		check_coords(t_map *map, int i, int j)
{
	if (i < 0 || i >= map->h || j < 0 || j >= map->w)
		return (0);
	return (1);
}

int		placing_possible(t_map *map, t_piece *p, int ins_i, int ins_j)
{
	int		i;
	int		j;
	int		map_i;
	int		map_j;
	int		intersections;

	intersections = 0;
	i = p->i_start - 1;
	while (++i <= p->i_end)
	{
		map_i = ins_i + i - p->i_start;
		j = p->j_start - 1;
		while (++j <= p->j_end)
		{
			map_j = ins_j + j - p->j_start;
			if (p->layout[i][j] == '*')
			{
				if (!check_coords(map, map_i, map_j))
					return (0);
				if (map->field[map_i][map_j] == map->enemy_ch || 
					map->field[map_i][map_j] == map->enemy_ch - ('a' - 'A'))
					return (0);
				if (map->field[map_i][map_j] != '.')
					intersections += 1;
			}
		}
	}
	return ((intersections == 1) ? 1 : 0);
}

int		find_solution(t_map map, t_piece piece, t_point *solution)
{
	int			i;
	int			j;
	int			temp;
	t_map		*map_cpy;

	temp = -1;
	i = 0;
	while (i < map.h)
	{
		j = 0;
		while (j < map.w)
		{
			if (placing_possible(&map, &piece, i, j) && 
				check_coords(&map, i - piece.i_start, j - piece.j_start))
			{
				map_cpy = copy_map(&map);
				temp = count_dist(map_cpy, &piece, \
					i - piece.i_start, j - piece.j_start);
				free_map(map_cpy);
				if (temp <= solution->min_dist)
				{
					solution->i = i - piece.i_start;
					solution->j = j - piece.j_start;
					solution->min_dist = temp;
				}
			}
			j++;
		}
		i++;
	}
	return ((temp == -1) ? 0 : 1);
}

void	output_result(t_point *solution, int rv)
{
	if (rv)
	{
		ft_putnbr(solution->i);
		ft_putchar(' ');
		ft_putnbr(solution->j);
		ft_putnbr('\n');
	}
	else
		ft_putstr("0 0\n");
}

int		place_piece(int num)
{
	t_map		map;
	t_piece 	piece;
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