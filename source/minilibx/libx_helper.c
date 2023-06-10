/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:24:52 by snaggara          #+#    #+#             */
/*   Updated: 2023/06/10 20:02:18 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

int	ft_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = img->addr + (y * img->ll + x * (img->bpp / 8));
// 	*(unsigned int *)dst = color;
// }
// A utiliser avec cette structure alors
// typedef struct	s_img {
// 	void	*img;
// 	char	*addr;
// 	int		bpp;
// 	int		ll;
// 	int		end;
// 	int		x_offset;
// 	int		y_offset;
// 	int		width;
// 	int		height;
// }	t_img;
