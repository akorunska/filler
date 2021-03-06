/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 13:27:23 by akorunsk          #+#    #+#             */
/*   Updated: 2018/02/07 19:43:15 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"
#include <stdlib.h>

int		get_player_num(void)
{
	int		num;
	char	*buf;
	int		i;

	get_next_line(0, &buf);
	i = 0;
	while (buf[i] && !ft_isdigit(buf[i]))
		i++;
	num = ft_atoi(buf + i);
	free(buf);
	return (num);
}

int		main(void)
{
	int		num;
	int		end;

	num = get_player_num();
	end = 0;
	while (!end)
		end = place_piece(num);
	return (0);
}
