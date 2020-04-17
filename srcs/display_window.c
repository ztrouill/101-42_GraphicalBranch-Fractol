/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_window.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/17 16:47:39 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/14 06:43:38 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			compute_and_display_window(t_data *data)
{
	main_fract_loop(data);
	mlx_put_image_to_window(data->utilities->mlx_ptr,
	data->utilities->window_ptr, data->bg_image.image_ptr, 0, 0);
	mlx_put_image_to_window(data->utilities->mlx_ptr,
	data->utilities->window_ptr, data->image.image_ptr,
	(data->utilities->width - data->numbers.zoom_x) / 2, 0);
}

void			refresh_window(t_data *data)
{
	mlx_destroy_image(data->utilities->mlx_ptr, data->image.image_ptr);
	data->image.y = 0;
	data->image.x = 0;
	data->image.i = 0;
	data->image.image_ptr = mlx_new_image(data->utilities->mlx_ptr,
	data->numbers.zoom_x, data->numbers.zoom_y);
	data->image.image_str = (int*)mlx_get_data_addr(data->image.image_ptr,
	&data->image.bits_per_pixel, &data->image.size_line,
	&data->image.endian);
	data->tmp = 0;
	compute_and_display_window(data);
}

int				quit_and_close_window(t_data *data)
{
	mlx_destroy_image(data->utilities->mlx_ptr, data->image.image_ptr);
	mlx_destroy_window(data->utilities->mlx_ptr,
						data->utilities->window_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}
