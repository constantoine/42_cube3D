/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 15:14:32 by cleo              #+#    #+#             */
/*   Updated: 2020/03/30 20:12:38 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECT_H
# define RECT_H

# include "stddef.h"
# include "colors.h"
# include "cube3D.h"
# include <mlx.h>
# include <stdbool.h>

typedef struct s_game	t_game;

typedef struct			s_rect
{
	size_t	x;
	size_t	y;
	size_t	width;
	size_t	heigth;
}						t_rect;

void					put_rect(t_game *game, t_rect *rect, t_color color);
t_rect					*new_rect
							(size_t x, size_t y, size_t width, size_t heigth);
bool					is_inside(size_t x, size_t y, t_rect *rect);
bool					is_rect_inside(t_rect *a, t_rect *b);

#endif
