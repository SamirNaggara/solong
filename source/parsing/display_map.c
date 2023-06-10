/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:03:35 by snaggara          #+#    #+#             */
/*   Updated: 2023/06/10 19:47:55 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

// void	ft_display_map(t_canva *canva)
// {
// 	t_point	*browse;
// 	int		i;

// 	browse = canva->map_first;
// 	ft_printf("Line len : %d\n", canva->ll);
// 	while (browse)
// 	{
// 		ft_printf("Addrs : %p, x : %d, y : %d, type : %c, gauche : %p,
// 				droite %p, haut %p, bas %p\n", browse,
// 				browse->x, browse->y, browse->type, browse->lf,
// 				browse->rg, browse->up, browse->dw);
// 		browse = browse->next;
// 	}
// 	browse = canva->map_first;
// 	i = 0;
// 	ft_printf("Obstacle : %d\n", canva->nb_items);

// 	while (i < canva->nb_items)
// 	{
// 		ft_printf("Addrs : %p, x : %d, y : %d, type : %c\n",
// 				canva->map_items[i], canva->map_items[i]->x,
// 				canva->map_items[i]->y, canva->map_items[i]->type);
// 		i++;
// 	}
// }
