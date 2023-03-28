/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_messages.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreher <nreher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:33:00 by nreher            #+#    #+#             */
/*   Updated: 2023/03/28 14:11:59 by nreher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_messages(t_all *all)
{
	all->messages.not_all_collects
		= mlx_put_string(all->vars.mlx, "I still need more PINK",
			1, all->height - 50);
	all->messages.not_all_collects->enabled = 0;
	all->messages.win
		= mlx_put_string(all->vars.mlx, "YOU WON!",
			1, all->height - 50);
	all->messages.win->enabled = 0;
	all->moves = ft_calloc(20, sizeof(char));
	all->pink = ft_calloc(20, sizeof(char));
	all->pink[0] = '0';
	all->moves[0] = '0';
	load_moves(all);
	load_pink(all);
}

void	load_pink(t_all *all)
{
	all->messages.collectables
		= mlx_put_string(all->vars.mlx, "PINK consumed:",
			200, all->height - 20);
	all->messages.collectables->enabled = 1;
	all->messages.collectables_collected
		= mlx_put_string(all->vars.mlx, all->pink,
			350, all->height - 20);
	all->messages.collectables_collected->enabled = 1;
}

void	load_moves(t_all *all)
{
	all->messages.moves = mlx_put_string(all->vars.mlx,
			"moves:", 1, all->height - 20);
	all->messages.move_count = mlx_put_string(all->vars.mlx,
			all->moves, 65, all->height - 20);
	all->messages.move_count->enabled = 1;
	all->messages.moves->enabled = 1;
}
