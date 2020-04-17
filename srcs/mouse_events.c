/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_events.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/13 03:10:56 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/14 07:53:00 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int			zoom_in(t_data *data)
{
	float		k;

	k = 1.5;
	if (data->numbers.zoom * 1.5 < 7500)
		k = 1.1;
	data->numbers.zoom *= k;
	if (data->tmp == 0)
		data->numbers.x1 /= k;
	if (data->utilities->type != 1 || data->utilities->type != 7)
		data->numbers.x2 *= k;
	data->numbers.y2 /= k;
	data->numbers.y1 /= k;
	data->numbers.it_max += 25;
	return (0);
}

static int			zoom_out(t_data *data)
{
	if (data->numbers.zoom / 1.2 < 100)
		return (-1);
	data->numbers.zoom /= 1.5;
	data->numbers.x1 *= 1.2;
	data->numbers.y1 *= 1.2;
	data->numbers.y2 *= 1.2;
	data->numbers.it_max -= 25;
	return (0);
}

int					mouse_move(int x, int y, t_data *data)
{
	if (data->bol == 0)
		return (-1);
	if (data->bol == 1)
	{
		if (x < 0 || y < 0 || y > data->numbers.zoom_y ||
				x > data->numbers.zoom_x)
			return (-1);
		data->numbers.mouse_y = (float)y / data->numbers.zoom +
			data->numbers.y1;
		data->numbers.mouse_x = (float)x / data->numbers.zoom +
			data->numbers.x1;
		if (data->numbers.zoom > 500)
		{
			data->numbers.mouse_y = fabs(data->numbers.mouse_y / 2);
			data->numbers.mouse_x = fabs(data->numbers.mouse_x / 2);
			if (data->numbers.mouse_y < 0.1)
				data->numbers.mouse_y *= 10;
			if (data->numbers.mouse_x < 0.1)
				data->numbers.mouse_x *= 10;
		}
	}
	refresh_window(data);
	return (0);
}

int					manage_mouse_events(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == MIDDLE_MOUSE && data->bol == 1)
		data->bol = 0;
	else if (button == MIDDLE_MOUSE && data->bol == 0)
	{
		data->bol = 1;
		printf("r = %f i = %f\n", data->numbers.c_r, data->numbers.c_i);
	}
	if (button == SCROLL_UP)
		zoom_in(data);
	if (button == SCROLL_DOWN)
		zoom_out(data);
	refresh_window(data);
	return (0);
}
