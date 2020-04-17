/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_events.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/13 03:13:57 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/14 07:54:11 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void			switch_color(int keycode, t_data *data)
{
	if (keycode == UNO)
		data->color.key_color = 0;
	if (keycode == DOS)
		data->color.key_color = 1;
	if (keycode == TRES)
		data->color.key_color = 2;
	if (keycode == QUATRO)
	{
		data->color.var_1 += 5;
		data->color.var_2 += 5;
		data->color.key_color = 3;
	}
	if (keycode == CINCO)
		data->color.key_color = 4;
	if (keycode == SIX)
		data->color.key_color = 5;
}

static void			find_scale(float *scale, int zoom)
{
	if (zoom > 3000 && *scale >= 0.1)
		*scale = 0.01;
	if (zoom > 8000)
		*scale = 0.005;
	if (zoom < 3000)
		*scale = 0.1;
}

static void			translate(int keycode, t_data *data)
{
	find_scale(&data->numbers.scale, data->numbers.zoom);
	if (keycode == KEY_LEFT)
	{
		data->tmp = 1;
		data->numbers.x1 -= data->numbers.scale;
	}
	if (keycode == KEY_RIGHT)
	{
		data->numbers.x1 += data->numbers.scale;
		data->numbers.x2 -= data->numbers.scale;
	}
	if (keycode == KEY_UP)
	{
		data->numbers.y2 += data->numbers.scale;
		data->numbers.y1 -= data->numbers.scale;
	}
	if (keycode == KEY_DOWN)
	{
		data->numbers.y2 -= data->numbers.scale;
		data->numbers.y1 += data->numbers.scale;
	}
}

static void			switch_fract(int keycode, t_data *data)
{
	if (keycode == F1)
		data->utilities->type = 0;
	if (keycode == F2)
		data->utilities->type = 1;
	if (keycode == F3)
		data->utilities->type = 2;
	if (keycode == F4)
		data->utilities->type = 3;
	if (keycode == F5)
		data->utilities->type = 4;
	if (keycode == F6)
		data->utilities->type = 5;
	if (keycode == F7)
		data->utilities->type = 6;
	if (keycode == F8)
		data->utilities->type = 7;
	init_numbers(&data->numbers, data->utilities->type);
}

int					manage_key_events(int keycode, t_data *data)
{
	if (keycode == UNO || keycode == DOS ||
		keycode == TRES || keycode == QUATRO || keycode == CINCO ||
		keycode == SIX)
		switch_color(keycode, data);
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT || keycode == KEY_UP ||
			keycode == KEY_DOWN)
		translate(keycode, data);
	if (keycode == KEY_ESC)
		quit_and_close_window(data);
	if (keycode == F1 || keycode == F2 || keycode == F3 || keycode == F4 ||
		keycode == F5 || keycode == F6 || keycode == F7 || keycode == F8)
		switch_fract(keycode, data);
	refresh_window(data);
	return (0);
}
