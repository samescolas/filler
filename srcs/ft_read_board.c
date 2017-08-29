#include "filler.h"

int	ft_read_board(char ***board, size_t rows)
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
		(*board)[i] = ft_strdup(&input[4]);
		ft_strdel(&input);
	}
	return (0);
}

