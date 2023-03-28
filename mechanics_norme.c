/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanics_norme.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreher <nreher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:28:40 by nreher            #+#    #+#             */
/*   Updated: 2023/03/28 15:03:05 by nreher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_while(t_all *all)
{
	char	temp;
	int		c;
	int		i;

	c = 0;
	i = ft_strlen(all->moves);
	while (c < ft_strlen(all->moves) / 2)
	{
		temp = all->moves[c];
		all->moves[c] = all->moves[i - 1];
		all->moves[i - 1] = temp;
		c++;
		i--;
	}
}

void	pink_while(t_all *all)
{
	char	temp;
	int		c;
	int		i;

	c = 0;
	i = ft_strlen(all->pink);
	while (c < i / 2)
	{
		temp = all->pink[c];
		all->pink[c] = all->pink[i - 1];
		all->pink[i - 1] = temp;
		c++;
		i--;
	}
}
