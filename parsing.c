/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:06:58 by hubrygo           #+#    #+#             */
/*   Updated: 2023/06/08 11:09:52 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_size(t_struct *data)
{
	size_t	len;
	int		i;

	i = 1;
	len = ft_strlen(data->tab[0]);
	while (i < data->x - 1)
	{
		if (len != ft_strlen(data->tab[i]))
			return (0);
		i++;
	}
	if (len != ft_strlen(data->tab[i]))
		return (0);
	data->map_height = len;
	data->map_width = i + 1;
	return (1);
}

static void	ft_check_path(int i, int j, t_struct *data)
{
	if (i < 0 || j < 0 || j >= data->y || i >= data->x)
		data->error = 1;
	if (data->error == 1 || data->tab[i][j] == '1' || data->tab[i][j] == '2' ||
	data->tab[i][j] == 'e' || data->tab[i][j] == 'c' || data->tab[i][j] == 'M')
		return ;
	if (data->tab[i][j] == 'E' && !data->exit)
	{
		data->exit = 1;
		data->tab[i][j] = 'e';
	}
	else if (data->tab[i][j] == 'E' && data->exit)
		data->error = 1;
	else if (data->tab[i][j] == 'C')
	{
		data->count++;
		data->tab[i][j] = 'c';
	}
	if (data->tab[i][j] == '0')
		data->tab[i][j] = '2';
	ft_check_path(i + 1, j, data);
	ft_check_path(i, j + 1, data);
	ft_check_path(i - 1, j, data);
	ft_check_path(i, j - 1, data);
}

static int	ft_check_items(char **line, t_struct *data)
{
	int	i;
	int	j;
	int	item[2];

	i = -1;
	item[0] = 0;
	item[1] = 0;
	while (line[++i])
	{
		j = 0;
		while (line[i][j])
		{
			if (line[i][j] == 'C')
			{
				data->collectible++;
				item[0]++;
			}
			if (line[i][j] == 'P')
				item[1]++;
			j++;
		}
	}
	if (item[0] == 0 || item[1] != 1)
		return (0);
	return (1);
}

int	ft_check(t_struct *data)
{
	int	i;
	int	j;

	i = 0;
	if (ft_check_size(data) == 0)
		return (0);
	if (ft_check_items(data->tab, data) == 0)
		return (0);
	while (data->tab[i])
	{
		j = 0;
		while (data->tab[i][j] && data->tab[i][j] != 'P')
			j++;
		if (data->tab[i][j] == 'P')
			break ;
		i++;
	}
	ft_check_path(i, j, data);
	if (data->error == 1 || data->exit != 1 || data->collectible != data->count)
		return (0);
	return (1);
}
