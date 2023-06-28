/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:28:39 by snaggara          #+#    #+#             */
/*   Updated: 2023/06/28 12:26:45 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int ac, char **av)
{
	t_canva	canva;

	if (!ft_init(&canva, ac, av))
		return (0);
	if (!ft_create_map(&canva))
		return (0);
	if (!ft_verify_map(&canva))
		return (ft_destroy_map(&canva));
	if (!ft_make_canva(&canva))
		return (ft_destroy_map(&canva));
	ft_destroy_map(&canva);
}
