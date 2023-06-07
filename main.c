/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:23:33 by hubrygo           #+#    #+#             */
/*   Updated: 2023/06/07 16:28:00 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_data(t_struct *data, t_window *image)
{
	data->collectible = 0;
	data->enemy = 0;
	data->error = 0;
	data->exit = 0;
	data->tab = NULL;
	data->x = 0;
	data->y = 0;
	data->count = 0;
	image->width = 0;
	image->height = 0;
	data->map_height = 0;
	data->map_width = 0;
	data->input = 0;
	image->struct_1 = data;
	image->window = NULL;
}

static void	ft_set_player(t_window *image)
{
	image->player_front = mlx_xpm_file_to_image(image->mlx,
			"image/perso_face.xpm", &image->width, &image->height);
	if (image->player_front == NULL)
		exit(0);
	image->player_front_2 = mlx_xpm_file_to_image(image->mlx,
			"image/perso_face_2.xpm", &image->width, &image->height);
	if (image->player_front_2 == NULL)
		exit(0);
	image->player_left = mlx_xpm_file_to_image(image->mlx,
			"image/perso_gauche.xpm", &image->width, &image->height);
	if (image->player_left == NULL)
		exit(0);
	image->player_left_2 = mlx_xpm_file_to_image(image->mlx,
			"image/perso_gauche_2.xpm", &image->width, &image->height);
	if (image->player_left_2 == NULL)
		exit(0);
	image->player_right = mlx_xpm_file_to_image(image->mlx,
			"image/perso_droite.xpm", &image->width, &image->height);
	if (image->player_right == NULL)
		exit(0);
	image->player_right_2 = mlx_xpm_file_to_image(image->mlx,
			"image/perso_droite_2.xpm", &image->width, &image->height);
	if (image->player_right_2 == NULL)
		exit(0);
}

static void	ft_set_sprite(t_window *image)
{
	image->green = mlx_xpm_file_to_image(image->mlx,
			"image/sol_vert.xpm", &image->width, &image->height);
	if (image->green == NULL)
		exit(0);
	image->white = mlx_xpm_file_to_image(image->mlx,
			"image/sol_blanc.xpm", &image->width, &image->height);
	if (image->white == NULL)
		exit(0);
	image->exit_close = mlx_xpm_file_to_image(image->mlx,
			"image/escalier_ferme.xpm", &image->width, &image->height);
	if (image->exit_close == NULL)
		exit(0);
	image->exit_open = mlx_xpm_file_to_image(image->mlx,
			"image/escalier.xpm", &image->width, &image->height);
	if (image->exit_close == NULL)
		exit(0);
	image->wall = mlx_xpm_file_to_image(image->mlx,
			"image/tombe.xpm", &image->width, &image->height);
	if (image->wall == NULL)
		exit(0);
	ft_set_player(image);
}

static void	ft_init_images(t_struct *data, t_window *image)
{
	image->mlx = mlx_init();
	if (!image->mlx)
		exit(0);
	image->player_x = 0;
	image->player_y = 0;
	image->exit_x = 0;
	image->exit_y = 0;
	ft_set_sprite(image);
	image->item = mlx_xpm_file_to_image(image->mlx,
			"image/collectible.xpm", &image->width, &image->height);
	if (image->item == NULL)
		exit(0);
	image->enemy = mlx_xpm_file_to_image(image->mlx,
			"image/enemi.xpm", &image->width, &image->height);
	if (image->enemy == NULL)
		exit(0);
		image->player_back = mlx_xpm_file_to_image(image->mlx,
			"image/perso_dos.xpm", &image->width, &image->height);
	if (image->player_back == NULL)
		exit(0);
	image->player_back_2 = mlx_xpm_file_to_image(image->mlx,
			"image/perso_dos_2.xpm", &image->width, &image->height);
	if (image->player_back_2 == NULL)
		exit(0);
	ft_init_data(data, image);
}

int	main(int argc, char **argv)
{
	t_struct	data;
	t_window	image;

	ft_init_images(&data, &image);
	if (argc != 2)
		ft_error(&image);
	if (!ft_map_to_tab(argv[1], &data, &image))
		return (1);
	set_spawn(&image, &data);
	image.window = mlx_new_window(image.mlx,
			data.map_height * 32, data.map_width * 32, "So_long");
	if (!image.window)
		ft_exit(&image);
	ft_set_image(&image, &data);
	mlx_put_image_to_window(image.mlx, image.window,
		image.player_front, image.player_x * 32, image.player_y * 32);
	mlx_hook(image.window, 2, 0, key_press, &image);
	mlx_hook(image.window, 17, 0, ft_exit, &image);
	mlx_loop(image.mlx);
}
