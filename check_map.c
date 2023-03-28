/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreher <nreher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:33:00 by nreher            #+#    #+#             */
/*   Updated: 2023/03/28 13:27:37 by nreher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_all *all)
{
	int	checksum;

	checksum = 0;
	all->current = all->head.first;
	while (all->current->next != NULL)
	{
		if (all->current->zeile == 0 && all->current->contnt != '1')
			return (1);
		if (all->current->spalte == 0 && all->current->contnt != '1')
			return (1);
		if (all->current->zeile == all->zeilen
			- 1 && all->current->contnt != '1')
			return (1);
		if (all->current->spalte == all->spalten
			- 1 && all->current->contnt != '1')
			return (1);
		all->current = all->current->next;
	}
	checksum = map_content_check(all, checksum);
	if (checksum != 3)
		return (1);
	return (0);
}

int	map_content_check(t_all *all, int checksum)
{
	int	collectable;

	collectable = 0;
	all->current = all->head.first;
	while (all->current->next != NULL)
	{
		if (all->current->contnt == 'P')
			checksum += 1;
		if (all->current->contnt == 'C')
		{
			if (collectable == 0)
			{
				checksum += 1;
				collectable += 1;
			}
		}
		if (all->current->contnt == 'E')
			checksum += 1;
		all->current = all->current->next;
	}
	return (checksum);
}

int	goto_player(t_all *all)
{
	all->current = all->head.first;
	while (all->current->contnt != 'P')
	{
		all->current = all->current->next;
	}
	if (pathcheck(all, all->current) == 1)
		return (1);
	return (0);
}

int	pathcheck(t_all *all, t_node *check)
{
	if (check->contnt == 'C')
		all->collectables_reachable++;
	if (check->contnt == 'E')
		all->end_reachable = 1;
	check->been = 1;
	if (check->up->contnt != '1' && check->up->been == 0)
		pathcheck(all, check->up);
	if (check->down->contnt != '1' && check->down->been == 0)
		pathcheck(all, check->down);
	if (check->previous->contnt != '1' && check->previous->been == 0)
		pathcheck(all, check->previous);
	if (check->next->contnt != '1' && check->next->been == 0)
		pathcheck(all, check->next);
	if (all->collectables_reachable == all->collectables
		&& all->end_reachable == 1)
		return (0);
	else
		return (1);
}
