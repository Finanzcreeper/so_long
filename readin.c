/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreher <nreher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:55:16 by nreher            #+#    #+#             */
/*   Updated: 2023/03/28 13:30:46 by nreher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_in(char *file, t_all *all)
{
	all->rn.fd = open(file, O_RDONLY);
	while (1)
	{
		all->rn.ln = get_next_line(all->rn.fd);
		if (all->rn.ln == NULL)
			return (0);
		all->rn.c = 0;
		while (all->rn.ln[all->rn.c] != '\n' && all->rn.ln[all->rn.c] != '\0')
		{
			if (all->rn.ln[all->rn.c] != '0' && all->rn.ln[all->rn.c] != '1'
				&& all->rn.ln[all->rn.c] != 'C' && all->rn.ln[all->rn.c] != 'E'
				&& all->rn.ln[all->rn.c] != 'P')
			{
				free(all->rn.ln);
				return (1);
			}
			new_node_at_back(all);
		}
		lena(all);
		if (all->rn.c != all->rn.len)
			return (1);
		all->spalten = all->rn.len;
	}
	return (0);
}

void	lena(t_all *all)
{
	all->rn.linenbr ++;
	free(all->rn.ln);
	if (all->rn.len == 0)
		all->rn.len = all->rn.c;
}

void	connect_collectables(t_all *all)
{
	t_node	*temp;

	all->current = all->head.first;
	temp = all->current;
	while (all->current != NULL)
	{
		if (all->current->contnt == 'C')
		{
			temp->next_c = all->current;
			temp = all->current;
			all->collectables++;
		}
		all->current = all->current->next;
	}
}

void	up_down(t_all *all, t_node *this)
{
	t_node	*temp;

	if (this == NULL)
		return ;
	all->current = all->head.first;
	temp = this;
	while (all->current != NULL)
	{
		if (all->current->spalte == temp->spalte && all->current->zeile
			!= temp->zeile)
		{
			all->current->up = temp;
			temp->down = all->current;
			temp = all->current;
		}
		all->current = all->current->next;
	}
	if (this != NULL)
	{
		this = this->next;
		up_down(all, this);
	}
}

void	new_node_at_back(t_all *all)
{
	t_node	*new;
	t_node	*temp;

	new = ft_calloc (1, sizeof(t_node));
	temp = all->current;
	if (all->head.first == NULL)
	{
		all->head.first = new;
		all->current = all->head.first;
	}
	else
	{
		all->current = all->head.first;
		while (all->current->next != NULL)
			all->current = all->current->next;
		all->current->next = new;
		all->current = all->current->next;
	}
	all->current->previous = temp;
	all->current->contnt = all->rn.ln[all->rn.c];
	all->current->zeile = all->rn.linenbr;
	all->current->spalte = all->rn.c;
	all->rn.c++;
	all->zeilen = all->current->zeile + 1;
}
