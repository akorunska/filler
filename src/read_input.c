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
	char	r;

	buf = malloc(sizeof(char) * 20);
	buf[20] = '\0';
	r = 0;
	i = 0;
	while (r != '\n')
	{
		read(0, &r, 1);
		if (r && r != '\n')
			buf[i] = r;
		i++;
	}
	buf[i] = '\0';
	i = 0;
	while (!ft_isdigit(buf[i]))
		i++;
	*h = ft_atoi(buf + i);
	while (ft_isdigit(buf[i]))
		i++;
	*w = ft_atoi(buf + i);
	free(buf);
}

char	*get_row(int width, int is_map)
{
	char	*buf;
	char 	temp[4];

	buf = (char *)malloc(sizeof(char) * (width + 1));
	if (is_map)
		read(0, &temp, 4);
	read(0, buf, width);
	read(0, &temp, 1);
	buf[width] = '\0';
	return (buf);
}

void	skip_row(void)
{
	char	buf;
	int		rv;

	buf = 1;
	rv = 1;
	while (buf != '\n' && rv)
		rv = read(0, &buf, 1);
}

void	skip_newlines(void)
{
	char	buf;
	int		rv;

	buf = 1;
	rv = 1;
	while (buf == '\n' && rv)
		rv = read(0, &buf, 1);
}

char	**read_map(int *w, int *h, int is_map)
{
	char	**map;
	int		i;
	
	skip_newlines();
	fill_size(w, h);
	map = (char **)malloc(sizeof(char *) * (*h + 1));
	ft_bzero(map,  (*h + 1) * sizeof(char *));
	if (is_map)
		skip_row();
	i = 0;
	while (i < *h)
	{
		map[i] = get_row(*w, is_map);
		fprintf(stderr, "±±±±± %s ±±±±\n", map[i]);
		i++;
	}
	return (map);
}
