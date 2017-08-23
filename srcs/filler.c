#include "filler.h"

static int	ft_new_game(t_game *game)
{
	
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
