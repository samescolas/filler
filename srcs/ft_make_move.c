/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 15:24:55 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/30 15:31:08 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_count_distance_r(t_game game, t_coord pos)
{
	int		width;
	int		row;

	width = 0;
	row = -1;
	while (++row < game.piece->dim.r)
	{
		if (ft_strfind(game.piece->str[row], '*') > width)
				width = ft_strfind(game.piece->str[row], '*');
	}
	return (game.maxima[right].r - pos.r + width);
}

static int	ft_place_right(t_game game)
{
	t_coord	placement;
	t_coord	maxplacement;
	int		max;

	max = 0;
	placement.r = 0;
	while (placement.r < game.dim.r)
	{
		placement.c = game.dim.c - 1;
		while (placement.c > 0)
		{
			if (ft_valid_placement(game, placement))
			{
				if (ft_count_distance_r(game, placement) > max)
				{
					max = ft_count_distance_r(game, placement);
					maxplacement.r = placement.r;
					maxplacement.c = placement.c;
				}
			}
			placement.c -= 1;
			if (placement.c == 0)
				break ;
		}
		placement.r += 1;
	}
	if (max > 0)
	{
		ft_putnbr(maxplacement.r);
		write(1, " ", 1);
		ft_putnbr(maxplacement.c);
		write(1, "\n", 1);
		return (0);
	}
	return (-1);
}

int 		ft_place_piece(t_game game)
{
	if (ft_place_right(game) == 0)
		return (0);
	if (ft_place_br(game) < 0 && ft_place_tr(game) < 0 && ft_place_bl(game) < 0 && ft_place_tl(game) < 0)
		return (-1);
	return (0);
}
