/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:21:05 by snaggara          #+#    #+#             */
/*   Updated: 2023/06/28 12:36:09 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

int	ft_stop_program(t_canva *canva)
{
	if (canva->player.img)
		mlx_destroy_image(canva->mlx, canva->player.img);
	if (canva->player_bis.img)
		mlx_destroy_image(canva->mlx, canva->player_bis.img);
	if (canva->player_happy.img)
		mlx_destroy_image(canva->mlx, canva->player_happy.img);
	if (canva->wall.img)
		mlx_destroy_image(canva->mlx, canva->wall.img);
	if (canva->item.img)
		mlx_destroy_image(canva->mlx, canva->item.img);
	if (canva->exit.img)
		mlx_destroy_image(canva->mlx, canva->exit.img);
	if (canva->empty.img)
		mlx_destroy_image(canva->mlx, canva->empty.img);
	if (canva->p_exit.img)
		mlx_destroy_image(canva->mlx, canva->p_exit.img);
	mlx_destroy_window(canva->mlx, canva->window);
	mlx_destroy_display(canva->mlx);
	free(canva->map_items);
	free(canva->mlx);
	ft_destroy_map(canva);
	exit(0);
}
