/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   calcul.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/18 11:28:09 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/14 05:53:31 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void			ft_quintuple_set(t_numbers *numbers)
{
	numbers->tmp = numbers->z_r;
	numbers->z_r = numbers->z_r * numbers->z_r * numbers->z_r * numbers->z_r *
		numbers->z_r - 10 * numbers->z_r * numbers->z_r *
		numbers->z_r * numbers->z_i * numbers->z_i + 5 * numbers->z_r *
		numbers->z_i * numbers->z_i * numbers->z_i * numbers->z_i +
		numbers->c_r;
	numbers->z_i = 5 * numbers->tmp * numbers->tmp * numbers->tmp *
		numbers->tmp * numbers->z_i - 10 * numbers->tmp * numbers->tmp *
		numbers->z_i * numbers->z_i * numbers->z_i + numbers->z_i *
		numbers->z_i * numbers->z_i * numbers->z_i * numbers->z_i +
		numbers->c_i;
	numbers->i++;
}

static void			ft_burning_ship(t_numbers *numbers, int type)
{
	numbers->tmp = numbers->z_r;
	numbers->z_r = fabs(numbers->z_r * numbers->z_r -
				numbers->z_i * numbers->z_i + numbers->c_r);
	if (type == 5 || type == 6)
		numbers->z_i = fabs(2 * numbers->z_i * numbers->tmp + numbers->c_i);
	if (type == 7)
		numbers->z_i = fabs(numbers->z_i * numbers->tmp + numbers->c_i);
	numbers->i++;
}

static void			ft_classic_set(t_numbers *numbers, int type)
{
	numbers->tmp = numbers->z_r;
	numbers->z_r = numbers->z_r * numbers->z_r -
				numbers->z_i * numbers->z_i + numbers->c_r;
	if (type == 0 || type == 1)
		numbers->z_i = 2 * numbers->z_i * numbers->tmp + numbers->c_i;
	if (type == 4)
		numbers->z_i = numbers->z_i * numbers->tmp + numbers->c_i;
	numbers->i++;
}

static void			reset_point(t_numbers *numbers, t_image *image, int type)
{
	if (type == 0 || type == 3 || type == 5)
	{
		numbers->c_r = (float)image->x / numbers->zoom + numbers->x1;
		numbers->c_i = (float)image->y / numbers->zoom + numbers->y1;
		numbers->z_r = 0;
		numbers->z_i = 0;
	}
	else
	{
		if (numbers->mouse_x != 0 || numbers->mouse_y != 0)
		{
			numbers->c_r = numbers->mouse_x;
			numbers->c_i = numbers->mouse_y;
		}
		numbers->z_r = (float)image->x / numbers->zoom + numbers->x1;
		numbers->z_i = (float)image->y / numbers->zoom + numbers->y1;
	}
	numbers->i = 0;
}

void				main_fract_loop(t_data *data)
{
	while (data->image.x < data->numbers.zoom_x)
	{
		while (data->image.y < data->numbers.zoom_y)
		{
			reset_point(&data->numbers, &data->image, data->utilities->type);
			while (data->numbers.z_r * data->numbers.z_r + data->numbers.z_i *
					data->numbers.z_i
					< 4 && data->numbers.i < data->numbers.it_max)
			{
				if (data->utilities->type == 0 || data->utilities->type == 1 ||
					data->utilities->type == 4)
					ft_classic_set(&data->numbers, data->utilities->type);
				if (data->utilities->type == 3 || data->utilities->type == 2)
					ft_quintuple_set(&data->numbers);
				if (data->utilities->type == 5 || data->utilities->type == 6 ||
					data->utilities->type == 7)
					ft_burning_ship(&data->numbers, data->utilities->type);
			}
			draw(data->numbers.i, &data->color, &data->numbers, &data->image);
			data->image.y++;
		}
		data->image.y = 0;
		data->image.x++;
	}
}
