/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 15:14:03 by cleo              #+#    #+#             */
/*   Updated: 2020/03/30 16:31:53 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rect.h"

void	put_rect(t_game *game, t_rect *rect, t_color color)
{
	t_image	img;
	size_t	x;
	size_t	y;

	img.img = mlx_new_image(game->mlx_ptr, rect->width, rect->heigth);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	y = 0;
	while (y <= rect->heigth)
	{
		x = 0;
		while (x <= rect->width)
		{
			my_mlx_pixel_put(&img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, img.img, rect->x, rect->y);
}

t_rect	new_rect(int x, int y, int width, int heigth)
{
	t_rect	rect;

	rect.x = x;
	rect.width = width;
	rect.y = y;
	rect.heigth = heigth;
	return (rect);
}

bool	is_inside(int x, int y, t_rect *rect)
{
	if (x >= rect->x && x <= rect->x + rect->width)
		if (y >= rect->y && y <= rect->y + rect->heigth)
			return true;
	return false;
}

bool	is_rect_inside(t_rect *a, t_rect *b)
{
	if (a->x < b->x + b->width && a->x + a->width > b->x &&
		a->y < b->y + b->heigth && a->heigth + a->y > b->y)
		return (true);
	return (false);
}
