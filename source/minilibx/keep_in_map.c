/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep_in_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:20:41 by snaggara          #+#    #+#             */
/*   Updated: 2023/06/10 19:37:03 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

int	ft_keep_player_in_map(t_canva *canva)
{
	canva->player_x = canva->map_player->y * 64 + canva->x_off;
	canva->player_y = canva->map_player->x * 64 + canva->y_off;
	if (canva->player_x < WINDOW_X_SIZE / 3)
	{
		mlx_clear_window(canva->mlx, canva->window);
		ft_create_maze(canva);
	}
	if (canva->player_x > (2 * WINDOW_X_SIZE) / 3)
	{
		mlx_clear_window(canva->mlx, canva->window);
		ft_create_maze(canva);
	}
	if (canva->player_y < WINDOW_Y_SIZE / 3)
	{
		mlx_clear_window(canva->mlx, canva->window);
		ft_create_maze(canva);
	}
	if (canva->player_y > (2 * WINDOW_Y_SIZE) / 3)
	{
		mlx_clear_window(canva->mlx, canva->window);
		ft_create_maze(canva);
	}
	return (1);
}

int	ft_calculate_screen(t_canva *canva)
{
	canva->player_x = canva->map_player->y * 64 + canva->x_off;
	canva->player_y = canva->map_player->x * 64 + canva->y_off;
	if (canva->ll * 64 > (WINDOW_X_SIZE * 4) / 5)
		ft_adjust_screen_x(canva);
	else
		canva->x_off = (WINDOW_X_SIZE - canva->ll * 64) / 2;
	ft_adjust_screen_y(canva);
	return (1);
}

int	ft_adjust_screen_x(t_canva *canva)
{
	while (canva->player_x < WINDOW_X_SIZE / 2)
	{
		canva->x_off++;
		canva->player_x = canva->map_player->y * 64 + canva->x_off;
	}
	while (canva->player_x > (WINDOW_X_SIZE) / 2)
	{
		canva->x_off--;
		canva->player_x = canva->map_player->y * 64 + canva->x_off;
	}
	return (1);
}

int	ft_adjust_screen_y(t_canva *canva)
{
	while (canva->player_y < WINDOW_Y_SIZE / 2)
	{
		canva->y_off++;
		canva->player_y = canva->map_player->x * 64 + canva->y_off;
	}
	while (canva->player_y > (WINDOW_Y_SIZE) / 2)
	{
		canva->y_off--;
		canva->player_y = canva->map_player->x * 64 + canva->y_off;
	}
	return (1);
}
