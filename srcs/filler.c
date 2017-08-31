/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 15:25:00 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/31 10:46:23 by sescolas         ###   ########.fr       */
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

static void	assign_bounds(t_coord *bounds, int row, int col, char *set)
{
	if (!set[top])
	{
		bounds[top].r = row;
		bounds[top].c = col;
		set[top] = 1;
	}
	if (!set[left] || col < bounds[left].r)
	{
		bounds[left].r = row;
		bounds[left].c = col;
		set[left] = 1;
	}
	bounds[bottom].r = row;
	bounds[bottom].c = col;
	if (!set[right] || col > bounds[right].c)
	{
		bounds[right].r = row;
		bounds[right].c = col;
		set[right] = 1;
	}
}

void	ft_set_bounds(t_game *game, t_coord *bounds, char marker)
{
	int			row;
	int			col;
	char		set[4];

	set[top] = 0;
	set[left] = 0;
	set[right] = 0;
	row = -1;
	while (++row < game->dim.r)
	{
		col = -1;
		while (++col < game->dim.c)
			if (ft_toupper(game->board[row][col]) == marker)
				assign_bounds(bounds, row, col, (char *)&set);
	}
}

static int	ft_play_turn(t_game *game)
{
	static int	first = 1;

	while (ft_read_board(game))
		continue;
	if (ft_get_piece(game->piece) < 0)
		return (-1);
	if (first)
	{
		first = 0;
		return (ft_place_piece(*game));
	}
	ft_set_bounds(game, (t_coord *)&game->bounds_me, ft_toupper(game->marker));
	ft_set_bounds(game, (t_coord *)&game->bounds_op, ft_toupper(game->opponent));
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
