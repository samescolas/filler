/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 20:36:58 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/31 20:37:01 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_get_player_number(void)
{
	char	*input;

	get_next_line(STDIN_FILENO, &input);
	if (ft_strlen(input) > 9 && ft_isdigit(input[10]))
		return (ft_atoi(&input[10]));
	return (-1);
}

static int	ft_get_board_dims(t_coord *dims)
{
	char	*input;

	if (get_next_line(STDIN_FILENO, &input) < 0)
		return (-1);
	if (ft_flush_lines(1) < 0)
		return (-1);
	if (ft_strlen(input) > 8 && ft_isdigit(input[8]))
		dims->r = ft_atoi(&input[8]);
	else
		return (-1);
	if ((input = ft_strchr(&input[8], ' ') + 1) && ft_isdigit(*input))
	{
		dims->c = ft_atoi(input);
		return (0);
	}
	return (-1);
}

int			ft_new_game(t_game *game, t_piece *piece)
{
	piece->dim.r = 0;
	piece->dim.c = 0;
	piece->pos.r = 0;
	piece->pos.c = 0;
	game->first_turn = 1;
	if ((game->player = ft_get_player_number()) < 0)
		return (-1);
	game->marker = (game->player == 1 ? 'O' : 'X');
	game->opponent = (game->player == 1 ? 'X' : 'O');
	if (ft_get_board_dims(&game->dim) < 0)
		return (-1);
	if (!(game->board = (char **)malloc(game->dim.r * sizeof(char *))))
		return (-1);
	game->piece = piece;
	return (0);
}
