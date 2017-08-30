#include "filler.h"

static int	ft_valid_placement(t_game game, t_coord pos)
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

static void	ft_print_piece(t_piece piece)
{
	int	i;
	int	j;

	i = -1;
	while (++i < piece.dim.r)
		ft_putendl_fd(piece.str[i], 2);
}

static int ft_place_piece(t_game game)
{
	t_coord	placement;

	placement.r = 0;
	placement.c = 0;
	while (placement.r < game.dim.r)
	{
		placement.c = 0;
		while (placement.c < game.dim.c)
		{
			if (ft_valid_placement(game, placement))
			{
				ft_putnbr(placement.r);
				write(1, " ", 1);
				ft_putnbr(placement.c);
				write(1, "\n", 1);
				return (1);
			}
			placement.c += 1;
		}
		placement.r += 1;
	}
	return (-1);
}

static int	ft_play_turn(t_game *game)
{
	int		i;
	int		waiting;

	while (ft_read_board(&game->board, game->dim.r) < 0)
		continue;
	if (ft_get_piece(game->piece) < 0)
		return (-1);
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
