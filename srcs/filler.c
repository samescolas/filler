#include "filler.h"

static int	ft_new_game(t_game *game, t_piece *piece)
{
	piece->dim->x = 0;
	piece->dim->y = 0;
	piece->pos->x = 0;
	piece->pos->y = 0;
	game->player = ft_get_player_number();
	game->marker = (game->player == 1 ? 'o' : 'x');
	game->dim->x = 0;
	game->dim->y = 0;
	game->board = (void *)0;
	game->piece = piece;
}

int	main(void)
{
	t_piece	piece;
	t_game	game;

	if (!ft_new_game(&game))
		return (1);
	ft_play(&game, &piece);
	return (0);
}
