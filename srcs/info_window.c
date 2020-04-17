/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   info_window.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/13 03:30:50 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/14 06:17:19 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void				fill_color_info_window(t_utilities *utilities)
{
	int				x;
	int				y;

	x = 0;
	y = 0;
	while (y < WINHE)
	{
		while (x < WINWI)
		{
			x++;
			if (y % 2 == 0)
				mlx_pixel_put(utilities->mlx_ptr, utilities->info_win_ptr,
				x, y, WHITE);
			else
				mlx_pixel_put(utilities->mlx_ptr, utilities->info_win_ptr,
				x, y, rand());
			x++;
		}
		mlx_pixel_put(utilities->mlx_ptr, utilities->info_win_ptr,
		x, y, WHITE);
		x = 0;
		y++;
	}
}

static void				display_title_and_break(t_utilities *util)
{
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 40, 20, WHITE, TITLE);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 0, 50, WHITE, BREAK);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 0, 275, WHITE, BREAK);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 0, 455, WHITE, BREAK);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 0, 655, WHITE, BREAK);
}

static void				display_info_text(t_utilities *util)
{
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 50, 75, WHITE, SWTCHFRCT);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 50, 105, WHITE, FF1);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 50, 125, WHITE, FF2);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 50, 145, WHITE, FF3);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 50, 165, WHITE, FF4);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 50, 185, WHITE, FF5);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 50, 205, WHITE, FF6);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 50, 225, WHITE, FF7);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 50, 245, WHITE, FF8);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 50, 305, WHITE, CHNG_CLR);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 50, 325, WHITE, UN);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 50, 345, WHITE, DEUX);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 50, 365, WHITE, TROIS);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 50, 385, WHITE, QUATRE);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 50, 405, WHITE, CINQ);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 50, 425, WHITE, SIXX);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 50, 485, WHITE, MOUSE);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 50, 505, WHITE, UPP);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 50, 525, WHITE, LEFTT);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 50, 545, WHITE, RIGHTT);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 50, 565, WHITE, DOWNN);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 50, 585, WHITE, SCROLUP);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 50, 605, WHITE, SCROLDWN);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 50, 625, WHITE, MOVE);
	mlx_string_put(util->mlx_ptr, util->info_win_ptr, 50, 685, WHITE, ESCAPE);
}

void					init_info_window(t_utilities *util)
{
	fill_color_info_window(util);
	display_title_and_break(util);
	display_info_text(util);
}
