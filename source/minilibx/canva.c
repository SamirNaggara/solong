/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canva.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:19:14 by snaggara          #+#    #+#             */
/*   Updated: 2023/06/08 11:04:00 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"


int	ft_make_canva(t_canva *canva)
{
	canva->mlx = mlx_init();
	canva->window = mlx_new_window(canva->mlx, WINDOW_X_SIZE, WINDOW_Y_SIZE, "Help Bilal to playerch the players !");
	mlx_do_key_autorepeatoff(canva->mlx);
	ft_create_sprites(canva);
	ft_create_maze(canva);
	
		


	mlx_key_hook(canva->window, ft_keyboard_action, &canva);
	// mlx_loop_hook(canva.mlx, ft_render_next_frame, &canva);
	mlx_hook(canva->window, 17, 0, ft_close_win_ui, &canva);
	mlx_loop(canva->mlx);
	return (1);
}

int	ft_keyboard_action(int keycode, t_canva *canva)
{
	if (keycode == 65361)
		ft_printf("gauche : %d\n", keycode);
	if (keycode == 65362)
		ft_printf("haut : %d\n", keycode);
	if (keycode == 65363)
		ft_printf("droite : %d\n", keycode);
	if (keycode == 65364)
		ft_printf("bas : %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(canva->mlx, canva->window);
		//mlx_loop_end(canva->mlx);
		//mlx_destroy_display(canva->mlx); 
	}
	return (1);
}

int	ft_calculate_screen(t_canva *canva)
{

	canva->x_off = (WINDOW_X_SIZE - 64 * canva->ll) / 2;
	canva->y_off = (WINDOW_Y_SIZE - 64 * canva->nb_l) / 2;
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
			mlx_put_image_to_window(canva->mlx, canva->window, canva->wall.img, 64 * browse->y + canva->x_off, 64 * browse->x + canva->y_off);
		else if (browse->type == 'E')
			mlx_put_image_to_window(canva->mlx, canva->window, canva->exit.img, 64 * browse->y + canva->x_off, 64 * browse->x + canva->y_off);
		else if (browse->type == 'P')
			mlx_put_image_to_window(canva->mlx, canva->window, canva->player.img, 64 * browse->y + canva->x_off, 64 * browse->x + canva->y_off);
		else if (browse->type == 'C')
			mlx_put_image_to_window(canva->mlx, canva->window, canva->item.img, 64 * browse->y + canva->x_off, 64 * browse->x + canva->y_off);
		browse = browse->next;
	}
	return (1);
}

int	ft_create_sprites(t_canva *canva)
{
	canva->player.img = mlx_xpm_file_to_image(canva->mlx, S_PLAYER, &(canva->player.width), &(canva->player.height));
	canva->wall.img = mlx_xpm_file_to_image(canva->mlx, S_WALL, &(canva->wall.width), &(canva->wall.height));
	canva->item.img = mlx_xpm_file_to_image(canva->mlx, S_ITEM, &(canva->item.width), &(canva->item.height));
	canva->exit.img = mlx_xpm_file_to_image(canva->mlx, S_EXIT, &(canva->exit.width), &(canva->exit.height));
	return (1);
}





int	ft_message_to_cmd(t_canva *canva)
{
	(void)canva;
	ft_printf("Destroy notify  !!\n");
	return (0);
}


int	ft_close_win_ui(t_canva *canva)
{


	mlx_destroy_window(canva->mlx, canva->window);
	//mlx_destroy_display(canva->mlx); 
	return (0);
}



int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->ll + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}