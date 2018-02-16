/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 09:52:44 by akorunsk          #+#    #+#             */
/*   Updated: 2018/02/16 09:52:47 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	trim_i(t_piece *p, int i, int j)
{
	int		occured;

	occured = 0;
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
}

void	trim_j(t_piece *p, int i, int j)
{
	int		occured;

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

void	trim_piece(t_piece *p)
{
	p->i_start = 0;
	p->j_start = 0;
	p->i_end = p->h - 1;
	p->j_end = p->w - 1;
	trim_i(p, -1, -1);
	trim_j(p, -1, -1);
}
