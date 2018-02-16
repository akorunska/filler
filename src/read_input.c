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

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

void	fill_size(int *w, int *h)
{
	char	*buf;
	int		i;
	int		rv;

	rv = get_next_line(0, &buf);
	i = 0;
	while (!ft_isdigit(buf[i]) && buf[i])
		i++;
	if (!buf[i])
	{
		*h = 0;
		*w = 0;
		return ;
	}
	*h = ft_atoi(buf + i);
	while (ft_isdigit(buf[i]))
		i++;
	*w = ft_atoi(buf + i);
	ft_strdel(&buf);
}

char	**read_map(int *w, int *h, int is_map)
{
	char	**map;
	char	*buf;
	int		i;
	int		j;
	int		shift;

	fill_size(w, h);
	if (!*w && !*h)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * (*h + 1));
	ft_bzero(map, (*h + 1) * sizeof(char *));
	if (is_map)
	{
		get_next_line(0, &buf);
		ft_strdel(&buf);
	}
	i = 0;
	while (i < *h)
	{
		map[i] = (char *)malloc(sizeof(char) * (*w + 1));
		ft_bzero(map[i], (*w + 1) * sizeof(char));
		get_next_line(0, &buf);
		j = 0;
		shift = (is_map) ? 4 : 0;
		while (j < *w)
		{
			map[i][j] = buf[j + shift];
			j++;
		}
		map[i][j] = '\0';
		ft_strdel(&buf);
		i++;
	}
	return (map);
}
