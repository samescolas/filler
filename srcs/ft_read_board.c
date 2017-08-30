#include "filler.h"

int	ft_read_board(char ***board, size_t rows)
{
	char	*input;
	int		i;

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
		(*board)[i] = ft_strdup(&input[4]);
		ft_strdel(&input);
	}
	return (0);
}

