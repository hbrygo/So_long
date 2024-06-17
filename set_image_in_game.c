/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image_in_game.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo <hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:35:58 by hugo              #+#    #+#             */
/*   Updated: 2023/06/17 15:03:27 by hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_set_sprite_in_game(t_window *image, t_struct *data, int y, int x)
{
	if ((y + x) % 2 == 0 && (data->tab[x][y] == 2 || data->tab[x][y] == 'P'))
		mlx_put_image_to_window(image->mlx,
			image->window, image->white, 32 * y, 32 * x);
	else if (data->tab[x][y] == 2 || data->tab[x][y] == 'P')
		mlx_put_image_to_window(image->mlx,
			image->window, image->green, 32 * y, 32 * x);
	else
		mlx_put_image_to_window(image->mlx,
			image->window, image->black, 32 * y, 32 * x);
	if (data->tab[x][y] == '1' && data->tab[x][y] == 2)
		mlx_put_image_to_window(image->mlx,
			image->window, image->wall, y * 32, x * 32);
	else if (data->tab[x][y] == 'c')
		mlx_put_image_to_window(image->mlx,
			image->window, image->item, y * 32, x * 32);
	else if (data->tab[x][y] == 'M' && data->tab[x][y] == 2)
		mlx_put_image_to_window(image->mlx,
			image->window, image->enemy, y * 32, x * 32);
}

void	ft_set_image_in_game(t_window *image, t_struct *data)
{
	int		y;
	int		x;
	char	*temp;

	x = 0;
	while (x < data->x)
	{
		y = -1;
		while (++y < data->map_height)
			ft_set_sprite_in_game(image, data, y, x);
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
	mlx_string_put(image->mlx, image->window, 64, 30, 0xFF0000, temp);
	mlx_string_put(image->mlx, image->window, 0, 30, 0xFF0000, "Score: ");
	free(temp);
}
