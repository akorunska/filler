/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 18:34:45 by akorunsk          #+#    #+#             */
/*   Updated: 2018/02/07 16:41:28 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

void	fill_size(int *w, int *h)
{
	char	*buf;
	int		i;
	
	get_next_line(0, &buf);
	i = 0;
	while (!ft_isdigit(buf[i]))
		i++;
	*h = ft_atoi(buf + i);
	while (ft_isdigit(buf[i]))
		i++;
	*w = ft_atoi(buf + i);
	free(buf);
}

char	**read_map(int *w, int *h, int is_map)
{
	char	**map;
	char 	*buf;
	int		i;
	int		j;
	int		shift;
	
	fill_size(w, h);
	map = (char **)malloc(sizeof(char *) * (*h + 1));
	ft_bzero(map,  (*h + 1) * sizeof(char *));
	if (is_map)
	{
		get_next_line(0, &buf);
		ft_strdel(&buf);
	}
	i = 0;
	fprintf(stderr, "map is %i x %i\n", *h, *w);
	while (i < *h)
	{
		map[i] = (char *)malloc(sizeof(char) * (*w + 1));
		ft_bzero(map[i], (*w + 1) * sizeof(char));
		get_next_line(0, &buf);
		j = 0;
		shift = (is_map) ? 4 : 0;
		while (buf[j + shift])
		{
			map[i][j] = buf[j + shift];
			j++;
		}
		fprintf(stderr, "got: {%s} || i = %i\n", map[i], i);
		ft_strdel(&buf);
		i++;
	}
	return (map);	
}