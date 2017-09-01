/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 15:25:00 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/31 20:36:16 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_play_turn(t_game *game)
{
	static int	first = 1;
	int			waiting;

	waiting = 0;
	while (ft_read_board(&game->board, game->dim.r, game->first_turn) < 0)
		waiting += 1;
	if (game->first_turn)
		ft_get_bullseye(game);
	if (ft_get_piece(game->piece) < 0)
		return (-1);
	game->first_turn = 0;
	return (ft_place_piece(game));
}

int			main(void)
{
	t_piece	piece;
	t_game	game;
	char	*input;

	if (ft_new_game(&game, &piece) < 0)
		return (1);
	while (1)
	{
		if (ft_play_turn(&game) < 0)
			break ;
	}
	write(1, "0 0\n", 4);
	return (0);
}
