#include "filler.h"

int	ft_flush_lines(size_t lines)
{
	char	*trash;

	while (lines--)
		if (get_next_line(STDIN_FILENO, &trash) < 0)
			return (-1);
	return (0);
}

