/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 18:20:34 by akorunsk          #+#    #+#             */
/*   Updated: 2018/01/29 15:07:10 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h> //

int		place_piece(int num)
{
	char	**map;
	int		w;
	int		h;
	
	map = read_map(&w, &h);
	fprintf(stderr, "map %i * %i\n", h, w);
	int i = -1;
	while (++i < h)
		fprintf(stderr, "%s\n", map[i]);
	num++;
	return (0);
}
