/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:04:08 by snaggara          #+#    #+#             */
/*   Updated: 2023/06/10 20:26:07 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

int	ft_destroy_map(t_canva *canva)
{
	t_point	*browse;
	t_point	*tmp;

	if (!canva->map_first)
		return (0);
	browse = canva->map_first;
	while (browse)
	{
		tmp = browse;
		browse = browse->next;
		free(tmp);
	}
	canva->map_first = NULL;
	canva->map_end = NULL;
	//free(canva->map_items);
	free(canva->mlx);
	return (0);
}
