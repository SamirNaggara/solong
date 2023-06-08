/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:17:00 by snaggara          #+#    #+#             */
/*   Updated: 2023/06/07 09:59:28 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

/*
	On dois avoir au moins 1 item
*/
int	ft_verify_items(t_canva *canva)
{
	t_point *browse;
	int 	nb_items;

	nb_items = 0;
	browse = canva->map_first;
	while (browse)
	{
		if (browse->type == 'C')
			nb_items++;
		browse = browse->next;
	}
	if (!nb_items)
	{
		printf(E_ITEMS);
		return (0);
	}
	canva->nb_items = nb_items;
	if (!ft_register_map_items(canva, nb_items))
		return (0);
	return (1);
}

int	ft_register_map_items(t_canva *canva, int nb_items)
{
	t_point *browse;
	int		i;

	browse = canva->map_first;
	canva->map_items = (t_point **)malloc(sizeof(t_point *) * (nb_items));
	if (!canva->map_items)
		return (0);
	i = 0;
	while (browse)
	{
		if (browse->type == 'C')
		{
			canva->map_items[i] = browse;
			i++;
		}
		browse = browse->next;
	}
	return (1);
}


int	ft_verify_one_exit(t_canva *canva)
{
	t_point *browse;
	int nb_exit;

	nb_exit = 0;
	browse = canva->map_first;
	while (browse)
	{
		if (browse->type == 'E')
		{
			canva->map_exit = browse;
			nb_exit++;
		}
		browse = browse->next;
	}
	if (nb_exit > 1)
	{
		printf(E_EXIT);
		return (0);
	}
	return (1);
}

int	ft_verify_one_start(t_canva *canva)
{
	t_point *browse;
	int nb_start;

	nb_start = 0;
	browse = canva->map_first;
	while (browse)
	{
		if (browse->type == 'P')
		{
			canva->map_start = browse;
			nb_start++;
		}
		browse = browse->next;
	}
	if (nb_start > 1)
	{
		printf(E_START);
		return (0);
	}
	return (1);
}

/*
	Verifions qu'il n'y a pas de caractere imprevu
*/

int	ft_verify_auth_char(t_canva *canva)
{
	t_point *browse;

	browse = canva->map_first;
	while (browse)
	{
		if (!ft_type_exist(browse->type))
		{
			ft_printf(E_TYPE);
			return (0);
		}
		browse = browse->next;
	}
	return (1);
}

int	ft_type_exist(char c)
{
	if (c == '0')
		return (1);
	if (c == '1')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'P')
		return (1);
	if (c == 'C')
		return (1);
	return (0);
}