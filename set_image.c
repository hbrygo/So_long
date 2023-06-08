/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:43:37 by hubrygo           #+#    #+#             */
/*   Updated: 2023/06/08 11:09:58 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_set_sprite(t_window *image, t_struct *data, int y, int x)
{
	if ((y + x) % 2 == 0)
		mlx_put_image_to_window(image->mlx,
			image->window, image->white, 32 * y, 32 * x);
	else
		mlx_put_image_to_window(image->mlx,
			image->window, image->green, 32 * y, 32 * x);
	if (data->tab[x][y] == '1')
		mlx_put_image_to_window(image->mlx,
			image->window, image->wall, y * 32, x * 32);
	else if (data->tab[x][y] == 'c')
		mlx_put_image_to_window(image->mlx,
			image->window, image->item, y * 32, x * 32);
	else if (data->tab[x][y] == 'M')
		mlx_put_image_to_window(image->mlx,
			image->window, image->enemy, y * 32, x * 32);
}

void	ft_set_image(t_window *image, t_struct *data)
{
	int		y;
	int		x;
	char	*temp;

	x = 0;
	while (x < data->x)
	{
		y = -1;
		while (++y < data->map_height)
			ft_set_sprite(image, data, y, x);
		x++;
	}
	if (data->collectible == 0)
		mlx_put_image_to_window(image->mlx, image->window,
			image->exit_open, image->exit_x * 32, image->exit_y * 32);
	else
		mlx_put_image_to_window(image->mlx, image->window,
			image->exit_close, image->exit_x * 32, image->exit_y * 32);
	temp = ft_itoa(data->input);
	if (!temp)
		ft_exit(image);
	mlx_string_put(image->mlx, image->window, 64, 10, 0xFF0000, temp);
	mlx_string_put(image->mlx, image->window, 0, 10, 0xFF0000, "Score: ");
	free(temp);
}

void	set_spawn(t_window *image, t_struct *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->tab[++i])
	{
		j = 0;
		while (data->tab[i][j] && data->tab[i][j] != 'P')
			j++;
		if (data->tab[i][j] == 'P')
			break ;
	}
	image->player_x = j;
	image->player_y = i;
	i = -1;
	while (data->tab[++i])
	{
		j = 0;
		while (data->tab[i][j] && data->tab[i][j] != 'e')
			j++;
		if (data->tab[i][j] == 'e')
			break ;
	}
	image->exit_x = j;
	image->exit_y = i;
}
