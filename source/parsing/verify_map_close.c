/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map_close.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 09:05:20 by snaggara          #+#    #+#             */
/*   Updated: 2023/06/07 09:33:49 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	ft_verify_map_close(t_canva *canva)
{
	t_point	*browse;

	browse = canva->map_first;
	while(browse->rg)	
	{
		if (!ft_verify_is_wall(browse))
			return (0);
		browse = browse->rg;
	}
	while(browse->dw)
	{
		if (!ft_verify_is_wall(browse))
			return (0);
		browse = browse->dw;
	}
	if (!ft_verify_map_close2(browse))
		return (0);
	return (1);
}

int	ft_verify_map_close2(t_point *browse)
{
	while(browse->lf)
	{
		if (!ft_verify_is_wall(browse))
			return (0);
		browse = browse->lf;
	}
	while(browse->up)
	{
		if (!ft_verify_is_wall(browse))
			return (0);
		browse = browse->up;
	}
	return (1);
}


int	ft_verify_is_wall(t_point *point)
{
	if (point->type == '1')
		return (1);
	ft_printf(E_NCLOSE);
	return (0);
}