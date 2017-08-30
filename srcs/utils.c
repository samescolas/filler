/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 15:24:51 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/30 15:24:51 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_valid_placement(t_game game, t_coord pos)
{
	int		i;
	int		j;
	int		adjacent_pieces;

	if (pos.r + game.piece->dim.r > game.dim.r || pos.c + game.piece->dim.c > game.dim.c)
		return (0);
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
				if (++adjacent_pieces > 1)
					return (0);
			}
			else if (ft_toupper(game.board[pos.r + i][pos.c + j]) == game.oponent)
				return (0);
		}
	}
	return (adjacent_pieces == 1);
}


int	ft_flush_lines(size_t lines)
{
	char	*trash;

	while (lines--)
		if (get_next_line(STDIN_FILENO, &trash) < 0)
			return (-1);
	return (0);
}

