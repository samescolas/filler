#include "filler.h"

static int	ft_play_game(t_game *game)
{
	int		i;

	while (1)
	{
		if (ft_read_board(&game->board, game->dim.y) < 0)
			return (-1);
		if (ft_get_piece(game->piece) < 0)
			return (-1);
		write(1, "2 4", 3);
	}
	return (0);
}

int	main(void)
{
	t_piece	piece;
	t_game	game;

	if (ft_new_game(&game, &piece) < 0)
		return (1);
	ft_play_game(&game);
	return (0);
}
