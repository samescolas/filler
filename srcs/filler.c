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

static int	ft_new_game(t_game *game, t_piece *piece)
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

static int	ft_flush_lines(size_t lines)
{
	char	*trash;

	while (lines--)
		if (get_next_line(STDIN_FILENO, &trash) < 0)
			return (-1);
	return (0);
}

static int	ft_read_board(char ***board, size_t rows)
{
	char	*input;
	int		i;

	if (ft_flush_lines(2) < 0)
		return (-1);
	i = -1;
	while (++i < rows - 1)
	{
		if (get_next_line(STDIN_FILENO, &input) < 0)
			return (-1);
		(*board)[i] = &input[4];
	}
	return (0);
}

static int	ft_read_piece(char ***piece, size_t rows)
{
	char	*input;
	int		i;

	ft_putstr_fd("Reading in ", 2);
	ft_putnbr_fd(rows, 2);
	ft_putendl_fd(" rows.", 2);
	i = -1;
	while (++i < rows)
	{
		if (get_next_line(STDIN_FILENO, &input) < 0)
			return (-1);
		ft_putendl_fd("Reading in row...", 2);
		(*piece)[i] = input;
	}
	return (0);
}

static int	ft_get_piece_dims(t_coord *dims)
{
	char	*input;

	if (get_next_line(STDIN_FILENO, &input) < 0)
		return (-1);
	if (ft_strlen(input) > 6 && ft_isdigit(input[6]))
		dims->y = ft_atoi(&input[6]);
	else
		return (-1);
	if ((input = ft_strchr(&input[6], ' ')) && ft_isdigit(*(input + 1)))
	{
		dims->x = ft_atoi(input);
		return (0);
	}
	return (-1);
}

static int	ft_get_piece(t_piece *piece)
{
	int		i;

	if (ft_get_piece_dims(&piece->dim) < 0)
		return (-1);
	ft_putstr_fd("Allocating space for ", 2);
	ft_putnbr_fd(piece->dim.y, 2);
	ft_putendl_fd(" rows.", 2);
	if (!(piece->str = (char **)malloc(piece->dim.y * sizeof(char *))))
		return (-1);
	if (ft_read_piece(&piece->str, piece->dim.y) < 0)
		return (-1);
	i = -1;
	while (++i < piece->dim.y - 1)
		ft_putendl_fd(piece->str[i], 2);
	return (0);
}

static int	ft_play(t_game *game)
{
	int		i;

	if (ft_read_board(&game->board, game->dim.y) < 0)
		return (-1);
	else
	{
		ft_putstr_fd("Board dims: ", 2);
		ft_putnbr_fd(game->dim.x, 2);
		ft_putstr_fd(", ", 2);
		ft_putnbr_fd(game->dim.y, 2);
		ft_putendl_fd("", 2);
		i = -1;
		while (++i < game->dim.y - 1)
			ft_putendl_fd(game->board[i], 2);
	}
	if (ft_get_piece(game->piece) < 0)
		return (-1);
	else
	{
		ft_putstr_fd("Piece dims: ", 2);
		ft_putnbr_fd(game->piece->dim.x, 2);
		ft_putstr_fd(", ", 2);
		ft_putnbr_fd(game->piece->dim.y, 2);
		ft_putendl_fd("", 2);
		ft_putstr_fd("\nPiece:", 2);
		i = -1;
		while (++i < game->piece->dim.y - 1)
			ft_putendl_fd(game->piece->str[i], 2);
	}
	return (0);
}

int	main(void)
{
	t_piece	piece;
	t_game	game;

	if (ft_new_game(&game, &piece) < 0)
		return (1);
	ft_play(&game);
	return (0);
}
