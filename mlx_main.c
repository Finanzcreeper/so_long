/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreher <nreher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:51:37 by nreher            #+#    #+#             */
/*   Updated: 2023/03/28 16:23:52 by nreher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "./minilibx-linux/mlx.h"
#include "so_long.h"

int	mlxer(t_all *all)
{
	all->widh = all->spalten * all->textures.wall->width;
	all->height = (all->zeilen * all->textures.wall->height) + 50;
	if (all->widh < 400)
		all->vars.mlx = mlx_init(400, all->height, "get the PINK!", 1);
	else
		all->vars.mlx = mlx_init(all->widh, all->height, "get the PINK!", 1);
	load_messages(all);
	make_images(all);
	if (all->vars.mlx == NULL)
	{
		write(2, "error\n", 6);
		return (0);
	}
	draw(all);
	if (goto_player(all) != 0)
	{
		write(2, "error\n", 6);
		return (0);
	}
	mlx_key_hook(all->vars.mlx, ft_key_hook, all);
	mlx_loop(all->vars.mlx);
	return (0);
}

void	make_trgb(t_colour *colour)
{
	colour->trgb = colour->r << 24 | colour->g << 16
		| colour->b << 8 | colour->t;
}

void	my_mlx_put_pixel(t_all all)
{
	char	*dst;

	dst = all.dat.address + (all.current->y * all.dat.line_length
			+ all.current->x * (all.dat.bits_per_pixel / 8));
	*(unsigned int *)dst = all.clr.trgb;
}

void	ft_key_hook(mlx_key_data_t keydata, void *all)
{
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(((t_all *)all)->vars.mlx);
	if (keydata.key == MLX_KEY_W && iwa(all) != 1
		&& (keydata.action == 1 || keydata.action == 2))
	{
		((t_all *)all)->img.player->instances[0].y
			-= ((t_all *)all)->img.empty->height;
		((t_all *)all)->movsies++;
	}
	if (keydata.key == MLX_KEY_S && iwb(all) != 1
		&& (keydata.action == 1 || keydata.action == 2))
	{
		((t_all *)all)->img.player->instances[0].y
			+= ((t_all *)all)->img.empty->height;
		((t_all *)all)->movsies++;
	}
	more_hooks(keydata, all);
}

void	more_hooks(mlx_key_data_t keydata, void *all)
{
	if (keydata.key == MLX_KEY_A && iwl(all) != 1
		&& (keydata.action == 1 || keydata.action == 2))
	{
		((t_all *)all)->img.player->instances[0].x
			-= ((t_all *)all)->img.empty->width;
		((t_all *)all)->movsies++;
	}
	if (keydata.key == MLX_KEY_D && iwr(all) != 1
		&& (keydata.action == 1 || keydata.action == 2))
	{
		((t_all *)all)->img.player->instances[0].x
			+= ((t_all *)all)->img.empty->width;
		((t_all *)all)->movsies++;
	}	
	if (keydata.action == 1 || keydata.action == 2)
		redraw(all);
}

// void	resize(int width, int height, void *all)
// {
// 	mlx_resize_image(((t_all *)all)->img.collect, height
// 		/ ((t_all *)all)->zeilen, width / ((t_all *)all)->spalten);
// 	mlx_resize_image(((t_all *)all)->img.empty, height
// 		/ ((t_all *)all)->zeilen, width / ((t_all *)all)->spalten);
// 	mlx_resize_image(((t_all *)all)->img.exit, height
// 		/ ((t_all *)all)->zeilen, width / ((t_all *)all)->spalten);
// 	mlx_resize_image(((t_all *)all)->img.player, height
// 		/ ((t_all *)all)->zeilen, width / ((t_all *)all)->spalten);
// 	mlx_resize_image(((t_all *)all)->img.wall, height
// 		/ ((t_all *)all)->zeilen, width / ((t_all *)all)->spalten);
// 	redraw_all(((t_all *)all));
// }

// void	mouse_hook(double xdelta, double ydelta, void *all)
// {
// 	if (ydelta > 0)
// 	{
// 		((t_all *)all)->height += 10;
// 		if (((t_all *)all)->height > ((t_all *)all)->dat.img->height)
// 			((t_all *)all)->height = ((t_all *)all)->dat.img->height;
// 		draw((t_all *)all);
// 	}
// 	if (ydelta < 0)
// 	{
// 		((t_all *)all)->height -= 10;
// 		if (((t_all *)all)->height < 0)
// 			((t_all *)all)->height = 0;
// 		draw((t_all *)all);
// 	}
// }

// void	ft_hook(void *all)
// {
// 	more_hooks(((t_all *)all));
// 	if (mlx_is_key_down(((t_all *)all)->vars.mlx,
// 			MLX_KEY_W) && iwa(all) != 1)
// 		((t_all *)all)->img.player->instances[0].y
// 			-= ((t_all *)all)->img.empty->height;
// 	if (mlx_is_key_down(((t_all *)all)->vars.mlx,
// 			MLX_KEY_S) && iwb(all) != 1)
// 		((t_all *)all)->img.player->instances[0].y
// 			+= ((t_all *)all)->img.empty->height;
// 	if (mlx_is_key_down(((t_all *)all)->vars.mlx,
// 			MLX_KEY_A) && iwl(all) != 1)
// 		((t_all *)all)->img.player->instances[0].x
// 			-= ((t_all *)all)->img.empty->width;
// 	if (mlx_is_key_down(((t_all *)all)->vars.mlx,
// 			MLX_KEY_D) && iwr(all) != 1)
// 		((t_all *)all)->img.player->instances[0].x
// 			+= ((t_all *)all)->img.empty->width;
// 	redraw(all);
// }

//cc main.c  -lmlx -L minilibx-linux/ -lXext -lX11 -lm
