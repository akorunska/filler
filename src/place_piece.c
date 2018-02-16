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
	while (i_shift + p->i_start < p->i_end + 1)
	{
		j_shift = 0;
		while (j_shift + p->j_start < p->j_end + 1)
		{
			if (p->layout[i_shift + p->i_start][j_shift + p->j_start] == '*')
			{
				if (i + i_shift >= map->h || j + j_shift >= map->w)
					return (0);
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

void	trim_piece(t_piece *p)
{
	int		i;
	int		j;
	int		occured;

	i = -1;
	occured = 0;
	p->i_start = 0;
	p->j_start = 0;
	p->i_end = p->h - 1;
	p->j_end = p->w - 1;
	while (++i < p->h && !occured)
	{
		occured = 0;
		j = -1;
		while (++j < p->w)
			if (p->layout[i][j] == '*')
				occured = 1;
		if (!occured)
			p->i_start = i + 1;
	}
	i = p->h;
	while (--i > -1 && !occured)
	{
		occured = 0;
		j = -1;
		while (++j < p->w)
			if (p->layout[i][j] == '*')
				occured = 1;
		if (!occured)
			p->i_end = i - 1;
	}
	j = -1;
	occured = 0;
	while (++j < p->w && !occured)
	{
		occured = 0;
		i = -1;
		while (++i < p->h)
			if (p->layout[i][j] == '*')
				occured = 1;
		if (!occured)
			p->j_start = j + 1;	
	}
	j = p->w;
	occured = 0;
	while (--j > -1 && !occured)
	{
		occured = 0;
		i = -1;
		while (++i < p->h)
			if (p->layout[i][j] == '*')
				occured = 1;
		if (!occured)
			p->j_end = j - 1;
	}
}

void	print_map(char **map, int h)
{
	int		i;

	i = 0;
	while (i < h)
	{
		fprintf(stderr, "\t\t++ %s ++\n", map[i]);
		i++;
	}
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
	trim_piece(&piece);
	//print_map(map.field, map.h);
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
				ft_printf("%i %i\n", i - piece.i_start, j - piece.j_start);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
