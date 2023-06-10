/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:03:03 by snaggara          #+#    #+#             */
/*   Updated: 2023/06/10 19:45:07 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

int	ft_add_vertical(t_canva *canva)
{
	t_point	*browse;
	t_point	*down;

	browse = canva->map_first;
	while (browse)
	{
		if (browse->x == 0)
			browse->up = NULL;
		down = ft_found_down(browse);
		if (down)
		{
			browse->dw = down;
			down->up = browse;
		}
		else
			browse->dw = NULL;
		browse = browse->next;
	}
	return (1);
}

t_point	*ft_found_down(t_point *point)
{
	t_point	*browse;

	browse = point;
	while (browse)
	{
		if (point->y == browse->y && point->x + 1 == browse->x)
			return (browse);
		browse = browse->next;
	}
	return (NULL);
}

int	ft_add_horizontal(t_canva *canva)
{
	t_point	*browse;

	browse = canva->map_first;
	browse->lf = NULL;
	while (browse)
	{
		if (browse->next && browse->next->y != 0)
		{
			browse->rg = browse->next;
			browse->next->lf = browse;
		}
		else if (browse->next && browse->next->y == 0)
		{
			browse->rg = NULL;
			browse->next->lf = NULL;
		}
		else
			browse->rg = NULL;
		browse = browse->next;
	}
	return (1);
}
