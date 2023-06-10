/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:21:05 by snaggara          #+#    #+#             */
/*   Updated: 2023/06/10 20:16:34 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

int	ft_stop_program(t_canva *canva)
{
	mlx_destroy_image(canva->mlx, canva->player.img);
	mlx_destroy_image(canva->mlx, canva->player_bis.img);
	mlx_destroy_image(canva->mlx, canva->player_happy.img);
	mlx_destroy_image(canva->mlx, canva->wall.img);
	mlx_destroy_image(canva->mlx, canva->item.img);
	mlx_destroy_image(canva->mlx, canva->exit.img);
	mlx_destroy_image(canva->mlx, canva->empty.img);
	mlx_destroy_image(canva->mlx, canva->p_exit.img);
	mlx_destroy_window(canva->mlx, canva->window);
	mlx_destroy_display(canva->mlx);
	ft_destroy_map(canva);
	exit(0);
}
