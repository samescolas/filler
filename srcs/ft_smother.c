/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smother.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 20:40:15 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/31 20:55:49 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_count_adjacent(t_game game, int row, int col)
{
	int		ret;

	ret = 0;
	if (row > 0)
	{
		ret += (game.board[row - 1][col] == game.opponent);
		ret += (col > 0 && game.board[row - 1][col - 1] == game.opponent);
		ret += (col + 1 < game.dim.c &&
								game.board[row - 1][col + 1] == game.opponent);
	}
	ret += (game.board[row][col] == game.opponent);
	ret += (col > 0 && game.board[row][col - 1] == game.opponent);
	ret += (col + 1 < game.dim.c && game.board[row][col + 1] == game.opponent);
	if (row + 1 < game.dim.r)
	{
		ret += (game.board[row + 1][col] == game.opponent);
		ret += (col > 0 && game.board[row + 1][col - 1] == game.opponent);
		ret += (col + 1 < game.dim.c &&
								game.board[row + 1][col + 1] == game.opponent);
	}
	return (ret);
}

static int	ft_count_touching_enemy(t_game game, t_coord pos)
{
	int		count;
	int		row;
	int		col;

	count = 0;
	row = -1;
	while (++row < game.piece->dim.r)
	{
		col = -1;
		while (++col < game.piece->dim.c)
		{
			if (game.piece->str[row][col] == '*')
				count += ft_count_adjacent(game, pos.r + row, pos.c + col);
		}
	}
	return (count);
}

static void	ft_line_saver(t_coord *max, t_coord *new)
{
	max->r = new->r;
	max->c = new->c;
}

int			ft_place_smother(t_game *game)
{
	t_coord	placement;
	t_coord	maxplacement;
	int		maxscore;

	maxscore = 0;
	ft_bzero(&maxplacement, sizeof(maxplacement));
	placement.r = 0;
	while (placement.r < game->dim.r)
	{
		placement.c = 0;
		while (placement.c < game->dim.c)
		{
			if (ft_valid_placement(*game, placement) &&
						ft_count_touching_enemy(*game, placement) > maxscore)
			{
				ft_line_saver(&maxplacement, &placement);
				maxscore = ft_count_touching_enemy(*game, placement);
			}
			placement.c += 1;
		}
		placement.r += 1;
	}
	if (maxscore > 0 || maxplacement.r > 0 || maxplacement.c > 0)
		return (ft_place_move(maxplacement));
	return (-1);
}
