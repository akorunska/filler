/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 10:51:47 by akorunsk          #+#    #+#             */
/*   Updated: 2018/02/21 10:51:49 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		check_coords(t_map *map, int i, int j)
{
	if (i < 0 || i >= map->h || j < 0 || j >= map->w)
		return (0);
	return (1);
}

void	output_result(t_point *solution, int rv)
{
	if (rv)
	{
		ft_putnbr(solution->i);
		ft_putchar(' ');
		ft_putnbr(solution->j);
		ft_putchar('\n');
	}
	else
		ft_putstr("0 0\n");
}
