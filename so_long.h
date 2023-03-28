/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreher <nreher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:51:57 by nreher            #+#    #+#             */
/*   Updated: 2023/03/28 14:03:55 by nreher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include	"./minilibx-linux/include/MLX42/MLX42.h"
# include	"./libft/libft.h"
# include	<stdlib.h>
# include	<math.h>
# include	<stdio.h>
# include	<fcntl.h>

typedef struct s_readin
{
	char	*ln;
	int		c;
	int		len;
	int		linenbr;
	int		fd;
}t_readin;

typedef struct s_images
{
	mlx_image_t		*empty;
	mlx_image_t		*wall;
	mlx_image_t		*collect;
	mlx_image_t		*exit;
	mlx_image_t		*player;
}t_images;

typedef struct s_data
{
	char			*address;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}t_fdfdata;

typedef struct s_node
{
	int				x;
	int				y;
	char			contnt;
	int				zeile;
	int				spalte;
	int				been;
	struct s_node	*next;
	struct s_node	*previous;
	struct s_node	*up;
	struct s_node	*down;
	struct s_node	*next_c;
}t_node;

typedef struct s_head
{
	struct s_node	*first;
}t_head;

typedef struct s_colour
{
	int	t;
	int	r;
	int	g;
	int	b;
	int	trgb;
}t_colour;

typedef struct s_vars
{
	void	*mlx;
	void	*window;
}t_mlx;

typedef struct s_textures
{
	mlx_texture_t	*wall;
	mlx_texture_t	*player;
	mlx_texture_t	*empty;
	mlx_texture_t	*exit;
	mlx_texture_t	*collectable;
}t_textures;

typedef struct s_messages
{
	mlx_image_t	*not_all_collects;
	mlx_image_t	*moves;
	mlx_image_t	*move_count;
	mlx_image_t	*win;
	mlx_image_t	*collectables;
	mlx_image_t	*collectables_collected;
}t_messages;

typedef struct s_all
{
	t_head		head;
	t_node		*current;
	t_colour	clr;
	t_mlx		vars;
	t_fdfdata	dat;
	t_readin	rn;
	t_textures	textures;
	t_images	img;
	t_messages	messages;
	char		*moves;
	int			movsies;
	char		*pink;
	int			pinksies;
	int			zeilen;
	int			spalten;
	int			widh;
	int			height;
	int			playerx;
	int			playery;
	int			xstep;
	int			ystep;
	int			walls;
	int			empty;
	int			collectables;
	int			collectables_reachable;
	int			end_reachable;
}t_all;

void	my_mlx_put_pixel(t_all all);
void	make_trgb(t_colour *colour);
int		key_hook(int keycode, t_mlx *mlx_vars, t_all *all);
void	new_node_at_back(t_all *all);
int		read_in(char *file, t_all *all);
void	free_in(t_all *all);
void	free_all(t_all *all);
int		mlxer(t_all *all);
void	ft_hook(void *mlx);
void	clear(t_all *all);
void	mouse_hook(double xdelta, double ydelta, void *size);
int		check_map(t_all *all);
int		map_content_check(t_all *all, int checksum);
void	draw(t_all *all);
void	draw_map(t_all *all);
void	redraw(t_all *all);
void	load_textures(t_all *all);
void	make_images(t_all *all);
int		iwa(t_all *all);
int		iwb(t_all *all);
int		iwl(t_all *all);
int		iwr(t_all *all);
void	ft_key_hook(mlx_key_data_t keydata, void *param);
void	player_move_handler(t_all *all, int c);
void	count_missed(t_all *all);
void	load_messages(t_all *all);
void	do_move(t_all *all);
void	load_moves(t_all *all);
void	load_pink(t_all *all);
void	more_hooks(mlx_key_data_t keydata, void *all);
void	lena(t_all *all);
void	move_while(t_all *all);
void	pink_while(t_all *all);
void	do_pink(t_all *all);
void	collectables_handler(t_all *all);
void	up_down(t_all *all, t_node *this);
// test
void	connect_collectables(t_all *all);
int		goto_player(t_all *all);
int		pathcheck(t_all *all, t_node *check);
#endif