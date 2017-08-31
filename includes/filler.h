#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

enum e_max
{
	top,
	bottom,
	left,
	right
};

typedef struct	s_coord
{
	size_t		r;
	size_t		c;
}				t_coord;

typedef struct	s_piece
{
	t_coord		dim;
	t_coord		pos;
	char		**str;
}				t_piece;

typedef struct	s_game
{
	char		player;
	char		marker;
	char		opponent;
	t_coord		dim;
	t_coord		bounds_me[4];
	t_coord		bounds_op[4];
	t_coord		changed;
	char		**board;
	t_piece		*piece;
}				t_game;

int		ft_place_tl(t_game game);
int		ft_place_tr(t_game game);
int		ft_place_bl(t_game game);
int		ft_place_br(t_game game);
int		ft_new_game(t_game *game, t_piece *piece);
int		ft_get_piece(t_piece *piece);
int		ft_read_board(t_game *game);
int		ft_flush_lines(size_t lines);
int		ft_place_piece(t_game game);
int		ft_valid_placement(t_game game, t_coord pos);
void	ft_set_maxima(t_game *game);

#endif
