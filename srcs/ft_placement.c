/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 15:25:25 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/31 17:32:38 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_place_tr(t_game game)
{
	t_coord	placement;

	placement.r = 0;
	while (placement.r < game.dim.r)
	{
		placement.c = game.dim.c - 1;
		while (placement.c > 0)
		{
			if (ft_valid_placement(game, placement))
			{
				ft_putnbr(placement.r);
				write(1, " ", 1);
				ft_putnbr(placement.c);
				write(1, "\n", 1);
				return (1);
			}
			placement.c -= 1;
			if (placement.c == 0)
				break ;
		}
		placement.r += 1;
	}
	return (-1);
}

int	ft_place_tl(t_game game)
{
	t_coord	placement;

	placement.r = 0;
	while (placement.r < game.dim.r)
	{
		placement.c = 0;
		while (placement.c < game.dim.c)
		{
			if (ft_valid_placement(game, placement))
			{
				ft_putnbr(placement.r);
				write(1, " ", 1);
				ft_putnbr(placement.c);
				write(1, "\n", 1);
				return (1);
			}
			placement.c += 1;
		}
		placement.r += 1;
	}
	return (-1);
}

int	ft_place_br(t_game game)
{
	t_coord	placement;

	placement.r = game.dim.r - 1;
	while (placement.r > 0)
	{
		placement.c = game.dim.c - 1;
		while (placement.c > 0)
		{
			if (ft_valid_placement(game, placement))
			{
				ft_putnbr(placement.r);
				write(1, " ", 1);
				ft_putnbr(placement.c);
				write(1, "\n", 1);
				return (1);
			}
			placement.c -= 1;
			if (placement.c == 0)
				break ;
		}
		placement.r -= 1;
		if (placement.r == 0)
			break ;
	}
	return (-1);
}

int	ft_place_bl(t_game game)
{
	t_coord	placement;

	placement.r = game.dim.r - 1;
	while (placement.r > 0)
	{
		placement.c = 0;
		while (placement.c < game.dim.c)
		{
			if (ft_valid_placement(game, placement))
			{
				ft_putnbr(placement.r);
				write(1, " ", 1);
				ft_putnbr(placement.c);
				write(1, "\n", 1);
				return (1);
			}
			placement.c += 1;
		}
		placement.r -= 1;
		if (placement.r == 0)
			break ;
	}
	return (-1);
}
