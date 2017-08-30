/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 15:25:00 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/30 15:25:00 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_print_piece(t_piece piece)
{
	int	i;
	int	j;

	i = -1;
	while (++i < piece.dim.r)
		ft_putendl_fd(piece.str[i], 2);
}

void	ft_set_maxima(t_game *game)
{
	int		rows;
	int		cols;
	int		unset[4];

	rows = -1;
	unset[top] = 1;
	unset[bottom] = 1;
	unset[left] = 1;
	unset[right] = 1;
	while (++rows < game->dim.r)
	{
		cols = -1;
		while (++cols < game->dim.c)
		{
			if (ft_toupper(game->board[rows][cols]) == game->marker)
			{
				if (unset[top])
				{
					game->maxima[top].r = rows;
					game->maxima[top].c = cols;
				}
				game->maxima[bottom].r = rows;
				game->maxima[bottom].c = cols;
				if (unset[left])
				{
					game->maxima[left].r = rows;
					game->maxima[left].c = cols;
				}
				if (cols > game->maxima[right].c)
				{
					game->maxima[right].r = rows;
					game->maxima[right].c = cols;
				}
			}
		}
	}
}
static int	ft_play_turn(t_game *game)
{
	static int	first = 1;

	while (ft_read_board(&game->board, game->dim.r) < 0)
		continue;
	if (first--)
		ft_set_maxima(game);
	if (ft_get_piece(game->piece) < 0)
		return (-1);
	ft_set_maxima(game);
	return (ft_place_piece(*game));
}

int	main(void)
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
