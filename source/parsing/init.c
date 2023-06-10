/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:01:11 by snaggara          #+#    #+#             */
/*   Updated: 2023/06/10 20:21:43 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

int	ft_init(t_canva *canva, int ac, char **av)
{
	if (ac > 1)
	{
		if (!ft_verify_ber(av[1]))
		{
			ft_printf(E_BER);
			exit(0);
		}
		canva->map_name = av[1];
	}
	else
		canva->map_name = "basic.ber";
	canva->map_first = (t_point *)0;
	canva->map_end = (t_point *)0;
	canva->nb_l = 0;
	canva->x_off = 0;
	canva->y_off = 0;
	canva->nb_move = 0;
	canva->is_happy = 0;
	return (1);
}

int	ft_verify_ber(char *name)
{
	int	i;

	i = ft_strlen(name);
	if (name[i - 1] != 'r')
		return (0);
	if (name[i - 2] != 'e')
		return (0);
	if (name[i - 3] != 'b')
		return (0);
	if (name[i - 4] != '.')
		return (0);
	return (1);
}
