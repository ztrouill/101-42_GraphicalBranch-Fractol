/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 10:30:18 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/14 06:07:49 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void			init_utilities(t_utilities *utilities, t_numbers *numbers)
{
	utilities->width = ceil((2 + 2) * numbers->zoom);
	utilities->height = floor((numbers->y2 - numbers->y1) * numbers->zoom);
	utilities->mlx_ptr = mlx_init();
	utilities->window_ptr = mlx_new_window(utilities->mlx_ptr,
	utilities->width, utilities->height, "Fract'ol");
	utilities->info_win_ptr = mlx_new_window(utilities->mlx_ptr,
	WINWI, WINHE, "I          N          F          O          S");
}

void				init_struct(t_utilities *utilities, t_data *data)
{
	t_numbers		numbers;
	t_color			color;
	t_image			bg_image;
	t_image			image;

	init_numbers(&numbers, utilities->type);
	init_color(&color);
	data->numbers = numbers;
	init_utilities(utilities, &numbers);
	data->utilities = utilities;
	init_main_image(&image, data);
	init_background_screen(utilities, &bg_image);
	init_info_window(utilities);
	data->utilities = utilities;
	data->image = image;
	data->color = color;
	data->bg_image = bg_image;
	data->bol = 0;
	data->tmp = 0;
}

int					main(int argc, char **argv)
{
	t_utilities		utilities;
	t_data			data;

	if ((check_error(argc, argv[1], &utilities) == 0))
		exit(EXIT_FAILURE);
	init_struct(&utilities, &data);
	compute_and_display_window(&data);
	mlx_hook(utilities.window_ptr, 2, 0L, manage_key_events, &data);
	mlx_hook(utilities.window_ptr, 4, 0L, manage_mouse_events, &data);
	mlx_hook(utilities.window_ptr, 6, 0L, mouse_move, &data);
	mlx_loop(utilities.mlx_ptr);
	return (0);
}
