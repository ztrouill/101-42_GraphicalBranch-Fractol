/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/07 11:05:58 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/13 07:56:10 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/minilibx_macos/mlx.h"
# include "x.h"
# include <stdio.h>
# include "../lib/libft/libft.h"
# include <math.h>
# include <pthread.h>
# include "fractol_struct.h"
# include "fractol_define.h"

/*
 *** FT_INIT ***
*/
void				init_numbers(t_numbers *numbers, int type);
void				init_struct(t_utilities *utilities, t_data *data);
void				init_info_window(t_utilities *utilities);
void				init_numbers(t_numbers *numbers, int type);
void				init_color(t_color *color);
void				init_background_screen(t_utilities *utilities, t_image
											*image);
void				init_main_image(t_image *image, t_data *data);
void				init_info_window(t_utilities *utilities);

/*
 *** FT_WINDOW ***
*/
void				compute_and_display_window(t_data *data);
void				refresh_window(t_data *data);
int					quit_and_close_window(t_data *data);

/*
 *** FT_EVENTS ***
*/
int					manage_mouse_events(int button, int x, int y, t_data *data);
int					mouse_move(int x, int y, t_data *data);
int					manage_key_events(int keycode, t_data *data);

/*
 *** FT_COLOR ***
*/
int					find_color(t_color *rgb, int i, float z_i);
void				draw(int i, t_color *color, t_numbers *numbers,
					t_image *image);
void				main_fract_loop(t_data *data);

/*
 *** FT_ERROR ***
*/
int					check_error(int argc, char *argv, t_utilities *utilities);

#endif
