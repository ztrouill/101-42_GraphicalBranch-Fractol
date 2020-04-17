/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol_struct.h                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/29 12:43:57 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/14 06:08:13 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_STRUCT_H
# define FRACTOL_STRUCT_H

typedef struct		s_utilities
{
	void					*window_ptr;
	void					*mlx_ptr;
	void					*info_win_ptr;
	int						type;
	int						width;
	int						height;
}					t_utilities;

typedef struct		s_image
{
	void					*image_ptr;
	int						*image_str;
	int						bits_per_pixel;
	int						size_line;
	int						endian;
	int						i;
	int						x;
	int						y;
	int						color;
	void					*info_image_ptr;
	int						*info_image_str;
}					t_image;

typedef struct		s_numbers
{
	float					x1;
	float					x2;
	float					y1;
	float					y2;
	float					zoom_x;
	float					zoom_y;
	float					c_r;
	float					c_i;
	float					z_r;
	float					z_i;
	float					tmp;
	int						zoom;
	float					scale;
	int						it_max;
	float					mouse_x;
	float					mouse_y;
	int						i;
}					t_numbers;

typedef struct		s_color
{
	int						r;
	int						g;
	int						b;
	float					frequency;
	int						amplitude;
	int						center;
	int						color;
	int						key_color;
	int						var_1;
	int						var_2;
}					t_color;

typedef struct		s_data
{
	t_utilities				*utilities;
	t_color					color;
	t_image					image;
	t_image					bg_image;
	t_numbers				numbers;
	int						bol;
	int						tmp;
	float					*param[2];
	int						stop;
}					t_data;

#endif
