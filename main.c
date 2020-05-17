/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 17:06:38 by cleo              #+#    #+#             */
/*   Updated: 2020/03/30 20:25:43 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X11/Xlib.h>
#include <stdlib.h>
#include <X11/keysym.h>
#include <stdio.h>

#include "colors.h"
#include "libft.h"
#include "cube3D.h"

int	exit_hook(t_game *params)
{
	mlx_destroy_window(params->mlx_ptr, params->mlx_window);
	exit(0);
	return (0);
}

int	button_hook(int button, int x, int y, t_game *params)
{
	t_widget	*widget;

	(void)button;
	widget = tree_walk(x, y, params->menu_ui);
	if (widget)
		printf("Widget name: %s\n", widget->name);
	else
		printf("%s\n", "No widget");
	return (0);
}

int	key_hook(int key, t_game *params)
{
	printf("Key pressed: %s\n", XKeysymToString(key));
	if (key == XK_Escape)
		exit_hook(params);
	return (key);
}

void	my_mlx_pixel_put(t_image *img, int x, int y, t_color color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void		*mlx_ptr;
	void		*mlx_window;
	t_rect		*rect;
	t_tree		*quad_tree;
	t_widget	*widget;
	t_game		game;

	mlx_ptr = mlx_init();
	mlx_window = mlx_new_window(mlx_ptr, 720, 480, "Ma bite");

	game.mlx_ptr = mlx_ptr;
	game.mlx_window = mlx_window;

	rect = new_rect(0, 0, 720, 480);
	put_rect(&game, rect, color_get(255, 0, 0, 255));
	if (!(quad_tree = tree_create(rect)))
		return (0);
	game.menu_ui = quad_tree;

	rect = new_rect(125, 100, 200, 50);
	put_rect(&game, rect, color_get(0, 0, 255, 255));

	if (!(widget = widget_create(rect, ft_strdup("Test"), NULL)))
		return (1);
	if (!tree_add(quad_tree, widget))
		return (1);

	mlx_hook(mlx_window, KeyPress, KeyPressMask, key_hook, &game);
	mlx_hook(mlx_window, ButtonPress, ButtonPressMask, button_hook, &game);
	mlx_hook(mlx_window, DestroyNotify, StructureNotifyMask, exit_hook, &game);
	mlx_loop(mlx_ptr);
}
