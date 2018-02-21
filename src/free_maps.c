/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 09:37:02 by akorunsk          #+#    #+#             */
/*   Updated: 2018/02/21 09:37:07 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdlib.h>

t_map	*copy_map(t_map *orig)
{
	t_map	*res;
	int		i;

	res = (t_map*)malloc(sizeof(t_map));
	if (!res)
		return (NULL);
	i = 0;
	res->field = (char **)malloc(sizeof(char *) * (orig->h + 1));
	while (i < orig->h)
	{
		res->field[i] = (char *)malloc(sizeof(char) * (orig->w + 1));
		ft_strcpy(res->field[i], orig->field[i]);
		i++;
	}
	res->h = orig->h;
	res->w = orig->w;
	res->ch = orig->ch;
	res->enemy_ch = orig->enemy_ch;
	return (res);
}

void	free_map(t_map *to_del)
{
	free_field(to_del->field, to_del->h);
	free(to_del);
}

void	free_field(char **field, int h)
{
	int		i;

	i = 0;
	while (i < h)
	{
		free(field[i]);
		i++;
	}
	free(field);
}
