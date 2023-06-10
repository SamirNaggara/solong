/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:01:40 by snaggara          #+#    #+#             */
/*   Updated: 2023/06/10 19:44:07 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

int	ft_create_map(t_canva *canva)
{
	char	*line;
	int		fd;

	fd = open(canva->map_name, O_RDONLY);
	if (!fd)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	canva->ll = (int)ft_strlen(line) - 1;
	if (canva->ll == 0)
		return (0);
	while (line)
	{
		if (!ft_line_in_list(canva, line))
			return (0);
		free(line);
		line = get_next_line(fd);
		canva->nb_l++;
	}
	ft_add_horizontal(canva);
	ft_add_vertical(canva);
	return (1);
}
/*
	On ajoute un point à la fin de la map, ou on le créé si ça existe pas
*/

int	ft_add_point(t_canva *canva, char type)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
		return (0);
	point->type = type;
	point->next = NULL;
	if (!canva->map_first)
	{
		point->x = 0;
		point->y = 0;
		canva->map_first = point;
		canva->map_end = point;
		return (1);
	}
	canva->map_end->next = point;
	canva->map_end = point;
	return (1);
}

int	ft_line_in_list(t_canva *canva, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!ft_add_point(canva, line[i]))
		{
			ft_destroy_map(canva);
			return (0);
		}
		canva->map_end->x = canva->nb_l;
		canva->map_end->y = i;
		i++;
	}
	return (1);
}
