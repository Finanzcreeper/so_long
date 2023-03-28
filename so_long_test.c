/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreher <nreher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:18:09 by nreher            #+#    #+#             */
/*   Updated: 2023/03/28 15:19:46 by nreher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_all	*all;
	int		err;

	all = ft_calloc(1, sizeof(t_all));
	if (all == NULL)
		return (0);
	if (argc == 1)
		return (0);
	err = read_in(argv[1], all);
	if (err == 0)
		err += check_map(all);
	connect_collectables(all);
	load_textures(all);
	up_down(all, all->head.first);
	if (err != 0)
	{
		write(2, "error\n", 6);
		free_all(all);
		return (0);
	}
	mlxer(all);
	mlx_terminate(all->vars.mlx);
	free_all(all);
	return (0);
}

void	free_all(t_all *all)
{
	while (all->head.first != NULL)
	{
		all->current = all->head.first;
		all->head.first = all->current->next;
		free(all->current);
	}
	free(all->head.first);
	free(all->moves);
	free(all->pink);
	mlx_delete_texture(all->textures.collectable);
	mlx_delete_texture(all->textures.player);
	mlx_delete_texture(all->textures.wall);
	mlx_delete_texture(all->textures.empty);
	mlx_delete_texture(all->textures.exit);
	free(all);
}
