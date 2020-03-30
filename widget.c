/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widget.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 15:25:52 by cleo              #+#    #+#             */
/*   Updated: 2020/03/30 18:06:30 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "widget.h"
#include "libft.h"
#include "rect.h"

t_widget	*widget_create(t_rect *rect, void (*action)(void *params))
{
	t_widget	*widget;

	if (!(widget = malloc(sizeof(t_widget))))
		return (NULL);
	widget->rect = *rect;
	widget->action = action;
	return (widget);
}

t_widget	*tree_create(t_rect *rect, void (*action)(void *params))
{
	t_tree		*tree;
	t_rect		rect;
	t_widget	widget;

	if (!(tree = malloc(sizeof(t_tree))))
		return (NULL);
	ft_bzero(tree, sizeof(t_tree));
	return (tree);
}

t_widget	*tree_walk(int x, int y, t_tree *tree)
{
	t_widget	*widget;

	if (!tree)
		return (NULL);
	if (!is_inside(x, y, tree))
		return (NULL);
	if ((widget = walk_tree(x, y, tree->top_left)))
		return (widget);
	if ((widget = walk_tree(x, y, tree->top_right)))
		return (widget);
	if ((widget = walk_tree(x, y, tree->bottom_left)))
		return (widget);
	if ((widget = walk_tree(x, y, tree->bottom_right)))
		return (widget);
	return (&(tree->button));
}

void	tree_fill_children(t_rect child[4], t_tree *tree)
{
	size_t	center_x;
	size_t	center_y;

	center_x = (tree->rect.width + tree->rect.x - tree->rect.x) / 2;
	center_y = (tree->rect.heigth + tree->rect.y - tree->rect.y) / 2;
	child[0] = new_rect(tree->rect.x, tree->rect.y,
		center_x - tree->rect.x,
		center_y - tree->rect.y);
	child[1] = new_rect(center_x, tree->rect.y,
		tree->rect.x + tree->rect.width - center_x,
		center_y - tree->rect.y);
	child[2] = new_rect(tree->rect.x, center_y,
		center_x - tree->rect.x,
		tree->rect.y + tree->rect.heigth - center_y);
	child[3] = new_rect(center_x, center_y,
		tree->rect.x + tree->rect.width - center_x,
		tree->rect.y + tree->rect.heigth - center_y);
}

t_tree	*tree_add(t_tree *tree, t_widget *widget)
{
	t_tree	*tmp;
	t_rect	child[4];

	if (widget->rect.heigth <= 4 ||
		(is_inside(widget->rect.x, widget->rect.y, &(tree->rect)) &&
		is_inside(widget->rect.x + widget->rect.width,
		widget->rect.y + widget->rect.heigth, &(tree->rect))))
	{
		tree->button = *widget;
		return (tree);
	}
	tree_fill_children(child, tree);
}

