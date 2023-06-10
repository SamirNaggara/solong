/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_tile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:21:26 by snaggara          #+#    #+#             */
/*   Updated: 2023/06/10 19:38:20 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

int	ft_replace_by_player(t_canva *canva, t_point *tile)
{
	if (tile->type == 'C')
	{
		canva->is_happy = 1;
		canva->nb_items--;
	}
	if (tile->type == 'E')
	{
		mlx_put_image_to_window(canva->mlx, canva->window,
			canva->p_exit.img, 64 * tile->y + canva->x_off,
			64 * tile->x + canva->y_off);
		return (1);
	}
	ft_display_player(canva, tile);
	tile->type = 'P';
	return (1);
}

int	ft_replace_by_empty(t_canva *canva, t_point *tile)
{
	if (tile->type == 'E')
		mlx_put_image_to_window(canva->mlx, canva->window,
			canva->exit.img, 64 * tile->y + canva->x_off,
			64 * tile->x + canva->y_off);
	else
		mlx_put_image_to_window(canva->mlx, canva->window,
			canva->empty.img, 64 * tile->y + canva->x_off,
			64 * tile->x + canva->y_off);
	if (tile->type == 'C' || tile->type == 'P')
		tile->type = '0';
	return (1);
}
