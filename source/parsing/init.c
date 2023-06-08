/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:01:11 by snaggara          #+#    #+#             */
/*   Updated: 2023/06/07 11:28:22 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	ft_init(t_canva *canva, int ac, char **av)
{
	if (ac > 1)
		canva->map_name = av[1];
	else
		canva->map_name = "basic.ber";
	canva->map_first = (t_point *)0;
	canva->map_end = (t_point *)0;
	canva->nb_l = 0;
	return (1);
}