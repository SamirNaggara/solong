/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:04:58 by snaggara          #+#    #+#             */
/*   Updated: 2023/06/07 10:45:48 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	ft_verify_map(t_canva *canva)
{
	if (!ft_verify_line_len(canva))
		return (0);
	if (!ft_verify_auth_char(canva))
		return (0);
	if (!ft_verify_one_exit(canva))
		return (0);
	if (!ft_verify_one_start(canva))
		return (0);
	if (!ft_verify_items(canva))
		return (0);
	if (!ft_verify_map_close(canva))
		return (0);
	if (!ft_valid_way(canva, canva->map_start, canva->map_exit))
		return (0);
	if (!ft_valid_items_way(canva))
		return (0);
	return (1);
}

/*
	On verifie que chaque ligne a la bonne longueur
	En regardant le dernier element a droite
	Et en vérifiant qu'il a bien le y normal
	Egal à la longueur de ligne - 1
*/
int	ft_verify_line_len(t_canva *canva)
{
	t_point *browse;

	browse = canva->map_first;
	while (browse)
	{
		while (browse->rg)
			browse = browse->rg;
		if (browse->y != canva->ll - 1)
		{
			ft_printf(E_ROW);
			return (0);
		}
		browse = browse->next;
	}
	return (1);
}

