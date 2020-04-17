/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_init.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/13 05:03:40 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/14 07:57:49 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void			init_c_numbers(t_numbers *numbers, int type)
{
	if (type == 1)
	{
		numbers->c_r = -0.770968;
		numbers->c_i = -0.112903;
	}
	if (type == 2)
	{
		numbers->c_r = -0.725806;
		numbers->c_i = -0.329032;
	}
	if (type == 4)
	{
		numbers->c_r = -0.271247;
		numbers->c_i = -0.879538;
	}
	if (type == 6)
	{
		numbers->c_r = 0.349853;
		numbers->c_i = -0.495583;
	}
	if (type == 7)
	{
		numbers->c_r = -1.010949;
		numbers->c_i = 0.168613;
	}
}

void				init_numbers(t_numbers *numbers, int type)
{
	if (type == 0 || type == 5)
	{
		numbers->x1 = -2.1;
		numbers->x2 = 0.6;
	}
	else
	{
		numbers->x1 = -2;
		numbers->x2 = 2;
	}
	numbers->y1 = -1.125;
	numbers->y2 = 1.125;
	numbers->tmp = 0;
	numbers->zoom = 320;
	init_c_numbers(numbers, type);
	numbers->zoom_x = ceil((numbers->x2 - numbers->x1) * numbers->zoom);
	numbers->zoom_y = floor((numbers->y2 - numbers->y1) * numbers->zoom);
	numbers->scale = 0.1;
	numbers->it_max = MAX_ITERATION;
	numbers->mouse_x = 0;
	numbers->mouse_y = 0;
}

void				init_color(t_color *color)
{
	color->amplitude = 127;
	color->center = 128;
	color->frequency = 0.3;
	color->var_1 = 40;
	color->var_2 = 50;
	color->key_color = 3;
}

void				init_background_screen(t_utilities *util,
										t_image *img)
{
	img->x = 0;
	img->y = 0;
	img->image_ptr = mlx_new_image(util->mlx_ptr, util->width,
							util->height);
	img->image_str = (int*)mlx_get_data_addr(img->image_ptr,
					&(img->bits_per_pixel), &(img->size_line), &(img->endian));
	while (img->y < util->height)
	{
		while (img->x < util->width)
		{
			img->x++;
			img->i = img->y * util->width + img->x;
			if (img->y % 2 == 0)
				img->image_str[img->i] = WHITE;
			else
				img->image_str[img->i] = rand();
			img->i++;
			img->x++;
		}
		img->x = 0;
		img->y++;
	}
	mlx_put_image_to_window(util->mlx_ptr, util->window_ptr,
							img->image_ptr, 0, 0);
}

void				init_main_image(t_image *image, t_data *data)
{
	image->image_ptr = mlx_new_image(data->utilities->mlx_ptr,
					data->numbers.zoom_x, data->numbers.zoom_y);
	image->image_str = (int*)mlx_get_data_addr(image->image_ptr,
					&(image->bits_per_pixel), &(image->size_line),
					&(image->endian));
	image->x = 0;
	image->y = 0;
	image->i = image->y * data->numbers.zoom_x + image->x;
}
