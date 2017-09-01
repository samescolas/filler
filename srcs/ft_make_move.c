/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 15:24:55 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/31 20:57:01 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_place_piece(t_game *game)
{
	int	success;

	success = -1;
	if (ft_place_smother(game) == 0)
		return (0);
	if (game->bullseye.r == top)
	{
		if (game->bullseye.c == left)
			success = ft_place_tl(*game);
		else
			success = ft_place_tr(*game);
	}
	else
	{
		if (game->bullseye.c == left)
			success = ft_place_bl(*game);
		else
			success = ft_place_br(*game);
	}
	if (success < 0 && ft_place_br(*game) < 0 && ft_place_tr(*game) < 0
						&& ft_place_bl(*game) < 0 && ft_place_tl(*game) < 0)
		return (-1);
	return (0);
}
