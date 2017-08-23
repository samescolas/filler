#include "filler.h"

static int	ft_get_player_number(void)
{
	char	*input;

	get_next_line(STDIN_FILENO, &input);
	if (ft_strlen(input) > 9 && ft_isdigit(input[10]))
		return (ft_atoi(&input[10]));
	return (-1);
}

static int	ft_get_board_dims(t_coord *dims)
{
	char	*input;

	if (get_next_line(STDIN_FILENO, &input) < 0)
		return (-1);
	if (ft_strlen(input) > 8 && ft_isdigit(input[8]))
		dims->y = ft_atoi(&input[8]);
	else
		return (-1);
	if ((input = ft_strchr(&input[8], ' ') + 1) && ft_isdigit(*input))
	{
		dims->x = ft_atoi(input);
		return (0);
	}
	return (-1);
}

int	ft_new_game(t_game *game, t_piece *piece)
{
	piece->dim.x = 0;
	piece->dim.y = 0;
	piece->pos.x = 0;
	piece->pos.y = 0;
	if ((game->player = ft_get_player_number()) < 0)
		return (-1);
	game->marker = (game->player == 1 ? 'o' : 'x');
	if (ft_get_board_dims(&game->dim) < 0)
		return (-1);
	if (!(game->board = (char **)malloc(game->dim.y * sizeof(char *))))
		return (-1);
	game->piece = piece;
	return (0);
}
