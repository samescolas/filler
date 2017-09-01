/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 15:24:51 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/31 21:05:45 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_bullseye_help(t_game game, char *topmost, int cols[2], int row)
{
	if (ft_strchr(game.board[row], game.marker))
	{
		if (!*topmost)
			*topmost = game.marker;
		cols[0] = ft_strfind(game.board[row], game.marker);
	}
	if (ft_strchr(game.board[row], game.opponent))
	{
		if (!*topmost)
			*topmost = game.opponent;
		cols[1] = ft_strfind(game.board[row], game.opponent);
	}
}

void		ft_get_bullseye(t_game *game)
{
	int		row;
	char	topmost_marker;
	int		cols[2];

	row = -1;
	topmost_marker = '\0';
	cols[0] = 0;
	cols[1] = 0;
	while (++row < game->dim.r)
		ft_bullseye_help(*game, &topmost_marker, cols, row);
	if (topmost_marker == game->opponent)
		game->bullseye.r = top;
	else
		game->bullseye.r = bottom;
	if (cols[0] < cols[1])
		game->bullseye.c = right;
	else
		game->bullseye.c = left;
}

int			ft_place_move(t_coord pos)
{
	ft_putnbr(pos.r);
	write(1, " ", 1);
	ft_putnbr(pos.c);
	write(1, "\n", 1);
	return (0);
}

int			ft_flush_lines(size_t lines)
{
	char	*trash;

	while (lines--)
		if (get_next_line(STDIN_FILENO, &trash) < 0)
			return (-1);
	return (0);
}
