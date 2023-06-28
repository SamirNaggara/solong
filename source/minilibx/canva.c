/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canva.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:19:14 by snaggara          #+#    #+#             */
/*   Updated: 2023/06/28 12:36:58 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

int	ft_make_canva(t_canva *canva)
{
	canva->mlx = mlx_init();
	canva->window = mlx_new_window(canva->mlx, WINDOW_X_SIZE,
			WINDOW_Y_SIZE, W_TITLE);
	mlx_do_key_autorepeaton(canva->mlx);
	if (!ft_create_sprites(canva))
	{
		ft_stop_program(canva);
		return (0);
	}
	ft_create_maze(canva);
	mlx_key_hook(canva->window, ft_keyboard_action, canva);
	mlx_hook(canva->window, 17, 0, ft_stop_program, canva);
	mlx_loop(canva->mlx);
	mlx_destroy_window(canva->mlx, canva->window);
	mlx_destroy_display(canva->mlx);
	return (1);
}

int	ft_create_maze(t_canva *canva)
{
	t_point	*browse;

	ft_calculate_screen(canva);
	browse = canva->map_first;
	while (browse)
	{
		if (browse->type == '1')
			mlx_put_image_to_window(canva->mlx, canva->window,
				canva->wall.img, 64 * browse->y + canva->x_off,
				64 * browse->x + canva->y_off);
		else if (browse->type == 'E')
			mlx_put_image_to_window(canva->mlx, canva->window,
				canva->exit.img, 64 * browse->y + canva->x_off,
				64 * browse->x + canva->y_off);
		else if (browse->type == 'P')
			ft_display_player(canva, browse);
		else if (browse->type == 'C')
			mlx_put_image_to_window(canva->mlx, canva->window,
				canva->item.img, 64 * browse->y + canva->x_off,
				64 * browse->x + canva->y_off);
		browse = browse->next;
	}
	return (1);
}
