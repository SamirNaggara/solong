/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:19:36 by snaggara          #+#    #+#             */
/*   Updated: 2023/06/10 20:03:42 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

int	ft_keyboard_action(int keycode, t_canva *canva)
{
	canva->nb_move++;
	if (keycode == 65363)
		ft_move_right(canva);
	if (keycode == 65361)
		ft_move_left(canva);
	if (keycode == 65362)
		ft_move_up(canva);
	if (keycode == 65364)
		ft_move_down(canva);
	if (keycode == 65307)
		ft_stop_program(canva);
	if (!canva->nb_items && canva->map_player == canva->map_exit)
	{
		ft_printf(E_WIN);
		ft_stop_program(canva);
	}
	ft_keep_player_in_map(canva);
	return (1);
}

int	ft_move_down(t_canva *canva)
{	
	if (canva->map_player->dw && canva->map_player->dw->type == '1')
		return (0);
	ft_replace_by_empty(canva, canva->map_player);
	canva->map_player = canva->map_player->dw;
	ft_replace_by_player(canva, canva->map_player);
	return (1);
}

int	ft_move_up(t_canva *canva)
{	
	if (canva->map_player->up && canva->map_player->up->type == '1')
		return (0);
	ft_replace_by_empty(canva, canva->map_player);
	canva->map_player = canva->map_player->up;
	ft_replace_by_player(canva, canva->map_player);
	return (1);
}

int	ft_move_left(t_canva *canva)
{	
	if (canva->map_player->lf && canva->map_player->lf->type == '1')
		return (0);
	ft_replace_by_empty(canva, canva->map_player);
	canva->map_player = canva->map_player->lf;
	ft_replace_by_player(canva, canva->map_player);
	return (1);
}

int	ft_move_right(t_canva *canva)
{	
	if (canva->map_player->rg && canva->map_player->rg->type == '1')
		return (0);
	ft_replace_by_empty(canva, canva->map_player);
	canva->map_player = canva->map_player->rg;
	ft_replace_by_player(canva, canva->map_player);
	return (1);
}
