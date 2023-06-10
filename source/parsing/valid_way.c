/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 09:28:26 by snaggara          #+#    #+#             */
/*   Updated: 2023/06/10 19:48:29 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

int	ft_valid_items_way(t_canva *canva)
{
	int	i;

	i = 0;
	while (i < canva->nb_items)
	{
		if (!ft_valid_way(canva, canva->map_player, canva->map_items[i++]))
			return (0);
	}
	return (1);
}
/*
	On regarde s'il y a un chemin valable entre a et b
*/

int	ft_valid_way(t_canva *canva, t_point *a, t_point *b)
{
	t_point	*browse;

	browse = canva->map_first;
	while (browse)
	{
		browse->tmp = 0;
		browse = browse->next;
	}
	if (!ft_check_ways(canva, a, b))
	{
		printf(E_WAYS);
		printf("Case %d %d inaccesible depuis %d %d\n", b->x, b->y, a->x, a->y);
		return (0);
	}
	return (1);
}

int	ft_check_ways(t_canva *canva, t_point *a, t_point *b)
{
	if (!ft_check_valid_tile(a))
		return (0);
	if (a == b)
		return (1);
	else
		a->tmp = 1;
	if (ft_check_ways(canva, a->up, b))
		return (1);
	if (ft_check_ways(canva, a->rg, b))
		return (1);
	if (ft_check_ways(canva, a->dw, b))
		return (1);
	if (ft_check_ways(canva, a->lf, b))
		return (1);
	return (0);
}

int	ft_check_valid_tile(t_point *point)
{
	if (point->type == '1')
		return (0);
	if (point->tmp == 1)
		return (0);
	return (1);
}
