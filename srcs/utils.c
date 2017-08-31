/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 15:24:51 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/30 18:21:00 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_valid_placement(t_game game, t_coord pos)
{
	int		i;
	int		j;
	int		shared_pieces;
	int		adjacent_pieces;

	if (pos.r + game.piece->dim.r > game.dim.r || pos.c + game.piece->dim.c > game.dim.c)
		return (0);
	shared_pieces = 0;
	adjacent_pieces = 0;
	i = -1;
	while (++i < game.piece->dim.r)
	{
		j = -1;
		while (++j < game.piece->dim.c)
		{
			if (game.piece->str[i][j] == '.')
				continue ;
			if (game.board[pos.r + i][pos.c + j] == '.')
				continue ;
			else if (ft_toupper(game.board[pos.r + i][pos.c + j]) == game.marker)
			{
				if (++shared_pieces > 1)
					return (0);
				if (i > 0 && ft_toupper(game.board[pos.r + i - 1][pos.c + j]) == game.marker)
					adjacent_pieces++;
				else if (i + 1 < game.piece->dim.r && ft_toupper(game.board[pos.r + i + 1][pos.c + j]) == game.marker)
					adjacent_pieces++;
				else if (j > 0 && ft_toupper(game.board[pos.r + i][pos.c + j - 1]) == game.marker)
					adjacent_pieces++;
				else if (j + 1 < game.piece->dim.c && ft_toupper(game.board[pos.r + i][pos.c + j + 1]) == game.marker)
					adjacent_pieces++;
			}
			else if (ft_toupper(game.board[pos.r + i][pos.c + j]) == game.opponent)
				return (0);
		}
	}
	return (shared_pieces == 1 || adjacent_pieces >  0);
}


int	ft_flush_lines(size_t lines)
{
	char	*trash;

	while (lines--)
		if (get_next_line(STDIN_FILENO, &trash) < 0)
			return (-1);
	return (0);
}

