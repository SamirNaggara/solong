/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:23:38 by snaggara          #+#    #+#             */
/*   Updated: 2023/06/11 07:37:57 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

int	ft_display_player(t_canva *canva, t_point *tile)
{
	if (canva->is_happy)
	{
		mlx_put_image_to_window(canva->mlx, canva->window,
			canva->player_happy.img, 64 * tile->y + canva->x_off,
			64 * tile->x + canva->y_off);
		canva->is_happy = 0;
	}
	else if (canva->nb_move % 2 == 0)
		mlx_put_image_to_window(canva->mlx, canva->window,
			canva->player.img, 64 * tile->y + canva->x_off,
			64 * tile->x + canva->y_off);
	else
		mlx_put_image_to_window(canva->mlx, canva->window,
			canva->player_bis.img, 64 * tile->y + canva->x_off,
			64 * tile->x + canva->y_off);
	return (1);
}

int	ft_create_sprites(t_canva *canva)
{
	canva->player.img = mlx_xpm_file_to_image(canva->mlx, S_PLAYER,
			&(canva->player.width), &(canva->player.height));
	canva->player_bis.img = mlx_xpm_file_to_image(canva->mlx, S_PLAYER_BIS,
			&(canva->player_bis.width), &(canva->player_bis.height));
	canva->player_happy.img = mlx_xpm_file_to_image(canva->mlx, S_PLAYER_HAPPY,
			&(canva->player_happy.width), &(canva->player_happy.height));
	canva->wall.img = mlx_xpm_file_to_image(canva->mlx, S_WALL,
			&(canva->wall.width), &(canva->wall.height));
	canva->item.img = mlx_xpm_file_to_image(canva->mlx, S_ITEM,
			&(canva->item.width), &(canva->item.height));
	canva->exit.img = mlx_xpm_file_to_image(canva->mlx, S_EXIT,
			&(canva->exit.width), &(canva->exit.height));
	canva->empty.img = mlx_xpm_file_to_image(canva->mlx, S_EMPTY,
			&(canva->empty.width), &(canva->empty.height));
	canva->p_exit.img = mlx_xpm_file_to_image(canva->mlx, S_P_EXIT,
			&(canva->p_exit.width), &(canva->p_exit.height));
	return (1);
}
