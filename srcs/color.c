/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 12:13:26 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/14 05:51:05 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		draw(int i, t_color *color, t_numbers *numbers,
									t_image *image)
{
	image->i = image->y * numbers->zoom_x + image->x;
	if (i == numbers->it_max)
	{
		if (color->key_color != 5 && color->key_color != 4)
			image->image_str[image->i] = WHITE;
		if (color->key_color == 4)
		{
			if (image->x % 2 == 0)
				image->image_str[image->i] = WHITE;
			else
				image->image_str[image->i] = rand();
		}
		if (color->key_color == 5)
			image->image_str[image->i] = BLACK;
		image->y++;
	}
	else
	{
		if (color->key_color == 5)
			color->color = rand();
		else
			color->color = find_color(color, i, numbers->z_i);
		image->image_str[image->i] = color->color;
	}
	image->i++;
}

void		psychedelic_gradient(t_color *color, int i, float z_i)
{
	int		step;

	step = 16;
	color->frequency = 2 * PI / step;
	color->r = sin(0.3 * i + color->var_1) * color->amplitude + color->center;
	color->g = sin(0.1 * i) * color->amplitude + color->center;
	color->b = sin(0.2 * i + z_i + color->var_2) * color->amplitude
				+ color->center;
}

int			find_color(t_color *c, int i, float z_i)
{
	if (c->key_color == 4)
		return (0);
	if (c->key_color == 0)
	{
		c->r = sin(c->frequency * i + z_i) * c->amplitude + c->center;
		c->g = sin(c->frequency * i + z_i) * c->amplitude + c->center;
		c->b = sin(c->frequency * i + z_i) * c->amplitude + c->center;
	}
	if (c->key_color == 1)
	{
		c->r = sin(c->frequency * i + z_i) * c->amplitude + c->center;
		c->g = sin(c->frequency * i) * c->amplitude + c->center;
		c->b = sin(c->frequency * i + z_i) * c->amplitude + c->center;
	}
	if (c->key_color == 2)
	{
		c->r = sin(c->frequency * i) * c->amplitude + c->center;
		c->g = sin(c->frequency * i + z_i) * c->amplitude + c->center;
		c->b = sin(c->frequency * i + z_i) * c->amplitude + c->center;
	}
	if (c->key_color == 3)
		psychedelic_gradient(c, i, z_i);
	return ((c->r << 16) | (c->g << 8) | c->b);
}
