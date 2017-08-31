#include "filler.h"

int	ft_read_board(t_game *game)
{
	static int	first = 1;
	char		*input;
	int			i;
	int			set;

	ft_putendl_fd("entering  read_board", 2);
	set = 0;
	i = -1;
	while (++i < game->dim.r)
	{
		if (get_next_line(STDIN_FILENO, &input) < 0)
			return (-1);
		if (ft_strncmp(input, "Plateau", 7) == 0)
		{
			if (ft_flush_lines(1) < 0 || get_next_line(STDIN_FILENO, &input) < 0)
				return (-1);
		}
		ft_putendl_fd("here!", 2);
		if (!first)
			ft_putendl_fd("NOT FIRST", 2);
		if (!first && ft_strcount(input, game->opponent) > ft_strcount(game->board[i], game->opponent))
		{
			game->changed.r = i;
			game->changed.c = 0;
			ft_putendl_fd("checking for row...", 2);
			while (game->changed.c < game->dim.c)
			{
				if (input[4 + game->changed.c] == game->opponent &&
							game->board[i][game->changed.c] != game->opponent)
					break ;
				set = 1;
			}
		}
	}
	ft_putendl_fd("leaving read_board", 2);
	return ((first = 0));
}

/*
int	ft_read_board(char ***board, size_t rows, t_coord *changed)
{
	static int	first = 1;
	char		*input;
	int			i;

	i = -1;
	while (++i < rows)
	{
		if (get_next_line(STDIN_FILENO, &input) < 0)
			return (-1);
		if (ft_strncmp(input, "Plateau", 7) == 0)
		{
			if (ft_flush_lines(1) < 0 || get_next_line(STDIN_FILENO, &input) < 0)
				return (-1);
		}
		if (!first && ft_strchr(input, 'x'))
		{
			ft_putstr_fd("FOUND ONE\n", 2);
			changed->r = i;
			changed->c = ft_strfind(input, 'x');;
		}
		else if (!first && (*board)[i])
		{
			ft_putstr_fd("Old: ", 2);
			ft_putendl_fd((*board)[i], 2);
			ft_putstr_fd("New: ", 2);
			ft_putendl_fd(&input[4], 2);
		}
		(*board)[i] = ft_strdup(&input[4]);
		ft_strdel(&input);
	}
	first = 0;
	return (0);
}
*/

