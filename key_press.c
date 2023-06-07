/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:55:52 by hubrygo           #+#    #+#             */
/*   Updated: 2023/06/07 16:50:15 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	key_press_down(t_struct *data, t_window *image)
{
	if (data->tab[image->player_y + 1][image->player_x] == 'M')
		ft_exit(image);
	if (data->tab[image->player_y + 1][image->player_x] != '1')
	{
		data->tab[image->player_y][image->player_x] = '2';
		(image->player_y)++;
		if (data->tab[image->player_y][image->player_x] == 'c')
			(data->collectible)--;
		data->tab[image->player_y][image->player_x] = 'P';
		data->input++;
		ft_printf("%d\n", image->struct_1->input);
	}
	if (image->player_y == image->exit_y
		&& image->player_x == image->exit_x && data->collectible == 0)
		ft_exit(image);
	ft_set_image(image, data);
	if ((image->player_y + image->player_x) % 2 == 0)
		mlx_put_image_to_window(image->mlx, image->window,
			image->player_front, image->player_x * 32, image->player_y * 32);
	else
		mlx_put_image_to_window(image->mlx, image->window,
			image->player_front_2, image->player_x * 32, image->player_y * 32);
}

static void	key_press_up(t_struct *data, t_window *image)
{
	if (data->tab[image->player_y - 1][image->player_x] == 'M')
		ft_exit(image);
	if (data->tab[image->player_y - 1][image->player_x] != '1')
	{
		data->tab[image->player_y][image->player_x] = '0';
		(image->player_y)--;
		if (data->tab[image->player_y][image->player_x] == 'c')
			(data->collectible)--;
		data->tab[image->player_y][image->player_x] = 'P';
		data->input++;
		ft_printf("%d\n", image->struct_1->input);
	}
	if (image->player_y == image->exit_y
		&& image->player_x == image->exit_x && data->collectible == 0)
		ft_exit(image);
	ft_set_image(image, data);
	if ((image->player_y + image->player_x) % 2 == 0)
		mlx_put_image_to_window(image->mlx, image->window,
			image->player_back, image->player_x * 32, image->player_y * 32);
	else
		mlx_put_image_to_window(image->mlx, image->window,
			image->player_back_2, image->player_x * 32, image->player_y * 32);
}

static void	key_press_right(t_struct *data, t_window *image)
{
	if (data->tab[image->player_y][image->player_x + 1] == 'M')
		ft_exit(image);
	if (data->tab[image->player_y][image->player_x + 1] != '1')
	{
		data->tab[image->player_y][image->player_x] = '0';
		(image->player_x)++;
		if (data->tab[image->player_y][image->player_x] == 'c')
			(data->collectible)--;
		data->tab[image->player_y][image->player_x] = 'P';
		data->input++;
		ft_printf("%d\n", image->struct_1->input);
	}
	if (image->player_y == image->exit_y
		&& image->player_x == image->exit_x && data->collectible == 0)
		ft_exit(image);
	ft_set_image(image, data);
	if ((image->player_y + image->player_x) % 2 == 0)
		mlx_put_image_to_window(image->mlx, image->window,
			image->player_right, image->player_x * 32, image->player_y * 32);
	else
		mlx_put_image_to_window(image->mlx, image->window,
			image->player_right_2, image->player_x * 32, image->player_y * 32);
}

static void	key_press_left(t_struct *data, t_window *image)
{
	if (data->tab[image->player_y][image->player_x - 1] == 'M')
		ft_exit(image);
	if (data->tab[image->player_y][image->player_x - 1] != '1')
	{
		data->tab[image->player_y][image->player_x] = '0';
		(image->player_x)--;
		if (data->tab[image->player_y][image->player_x] == 'c')
			(data->collectible)--;
		data->tab[image->player_y][image->player_x] = 'P';
		data->input++;
		ft_printf("%d\n", image->struct_1->input);
	}
	if (image->player_y == image->exit_y
		&& image->player_x == image->exit_x && data->collectible == 0)
		ft_exit(image);
	ft_set_image(image, data);
	if ((image->player_y + image->player_x) % 2 == 0)
		mlx_put_image_to_window(image->mlx, image->window,
			image->player_left, image->player_x * 32, image->player_y * 32);
	else
		mlx_put_image_to_window(image->mlx, image->window,
			image->player_left_2, image->player_x * 32, image->player_y * 32);
}

int	key_press(int keycode, t_window *image)
{
	if (keycode == 13 || keycode == 126)
		key_press_up(image->struct_1, image);
	else if (keycode == 1 || keycode == 125)
		key_press_down(image->struct_1, image);
	else if (keycode == 0 || keycode == 123)
		key_press_left(image->struct_1, image);
	else if (keycode == 2 || keycode == 124)
		key_press_right(image->struct_1, image);
	else if (keycode == 53)
		ft_exit(image);
	return (1);
}
