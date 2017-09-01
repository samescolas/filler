/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 20:58:33 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/31 21:32:38 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_validation_help(t_game game, t_coord pos, t_coord *ix, int pc[2])
{
	if (++pc[0] > 1)
		return (0);
	if (ix->r > 0 &&
					game.board[pos.r + ix->r - 1][pos.c + ix->c] == game.marker)
		pc[1]++;
	else if (ix->r + 1 < game.piece->dim.r &&
					game.board[pos.r + ix->r + 1][pos.c + ix->c] == game.marker)
		pc[1]++;
	else if (ix->c > 0 &&
					game.board[pos.r + ix->r][pos.c + ix->c - 1] == game.marker)
		pc[1]++;
	else if (ix->c + 1 < game.piece->dim.c &&
					game.board[pos.r + ix->r][pos.c + ix->c + 1] == game.marker)
		pc[1]++;
	return (1);
}

static int	ft_validate_row(t_game game, t_coord pos, t_coord *ix, int pc[2])
{
	ix->c = 0;
	while (ix->c < game.piece->dim.c)
	{
		if (game.piece->str[ix->r][ix->c] == '.' ||
							game.board[pos.r + ix->r][pos.c + ix->c] == '.')
		{
			ix->c += 1;
			continue ;
		}
		else if (game.board[pos.r + ix->r][pos.c + ix->c] == game.marker)
		{
			if (ft_validation_help(game, pos, ix, pc) == 0)
				return (0);
		}
		else
			return (0);
		ix->c += 1;
	}
	ix->r += 1;
	return (1);
}

int			ft_valid_placement(t_game game, t_coord pos)
{
	t_coord	ix;
	int		pieces[2];

	if (pos.r + game.piece->dim.r > game.dim.r ||
										pos.c + game.piece->dim.c > game.dim.c)
		return (0);
	ft_bzero(pieces, sizeof(int) * 2);
	ft_bzero(&ix, sizeof(t_coord));
	while (ix.r < game.piece->dim.r)
	{
		if (ft_validate_row(game, pos, &ix, pieces) == 0)
			return (0);
	}
	return (pieces[0] == 1 || pieces[1] > 0);
}
