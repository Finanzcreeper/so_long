/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreher <nreher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:59:03 by nreher            #+#    #+#             */
/*   Updated: 2023/03/27 17:48:26 by nreher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw(t_all *all)
{
	int	x;
	int	y;

	all->xstep = all->widh / all->spalten;
	all->ystep = (all->height - 50) / all->zeilen;
	x = 0;
	y = 0;
	all->current = all->head.first;
	while (all->current != NULL)
	{
		if (all->current->zeile != y / all->ystep)
			y += all->ystep;
		all->current->y = y;
		while (all->current->spalte != x / all->xstep)
			x += all->xstep;
		all->current->x = x;
		x = 0;
		draw_map(all);
		all->current = all->current->next;
	}
}

void	load_textures(t_all *all)
{
	all->textures.empty = mlx_load_png("./textures/empty.png");
	all->textures.wall = mlx_load_png("./textures/wall.png");
	all->textures.collectable = mlx_load_png("./textures/collect.png");
	all->textures.exit = mlx_load_png("./textures/exit.png");
	all->textures.player = mlx_load_png("./textures/player.png");
}

void	make_images(t_all *all)
{
	all->img.empty = mlx_texture_to_image(all->vars.mlx, all->textures.empty);
	all->img.wall = mlx_texture_to_image(all->vars.mlx, all->textures.wall);
	all->img.player = mlx_texture_to_image(all->vars.mlx, all->textures.player);
	all->img.collect = mlx_texture_to_image(all->vars.mlx,
			all->textures.collectable);
	all->img.exit = mlx_texture_to_image(all->vars.mlx, all->textures.exit);
}

void	draw_map(t_all *all)
{
	if (all->current->contnt == '0')
		mlx_image_to_window(all->vars.mlx, all->img.empty,
			all->current->x, all->current->y);
	if (all->current->contnt == '1')
		mlx_image_to_window(all->vars.mlx, all->img.wall,
			all->current->x, all->current->y);
	if (all->current->contnt == 'P')
	{
		mlx_image_to_window(all->vars.mlx, all->img.empty,
			all->current->x, all->current->y);
		mlx_image_to_window(all->vars.mlx, all->img.player,
			all->current->x, all->current->y);
	}
	if (all->current->contnt == 'C')
	{
		mlx_image_to_window(all->vars.mlx, all->img.empty,
			all->current->x, all->current->y);
		mlx_image_to_window(all->vars.mlx, all->img.collect,
			all->current->x, all->current->y);
	}
	if (all->current->contnt == 'E')
		mlx_image_to_window(all->vars.mlx, all->img.exit,
			all->current->x, all->current->y);
}
