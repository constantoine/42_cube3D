/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widget.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 15:22:05 by cleo              #+#    #+#             */
/*   Updated: 2020/03/30 20:17:47 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIDGET_H
# define WIDGET_H

# include <stddef.h>
# include <stdbool.h>
# include "cube3D.h"
# include "rect.h"

typedef struct	s_rect	t_rect;

typedef struct	s_widget
{
	t_rect	*rect;
	char	*name;
	void	(*action)(void *params);
}				t_widget;

typedef struct s_tree
{
	t_rect			*rect;
	t_widget		*button;
	struct s_tree	*top_left;
	struct s_tree	*top_right;
	struct s_tree	*bottom_left;
	struct s_tree	*bottom_right;
} t_tree;

t_widget	*tree_walk(int x, int y, t_tree *tree);
t_tree		*tree_create(t_rect *rect);
bool		tree_add(t_tree *tree, t_widget *widget);
t_widget	*widget_create(t_rect *rect, char *name, void (*action)(void *params));

#endif
