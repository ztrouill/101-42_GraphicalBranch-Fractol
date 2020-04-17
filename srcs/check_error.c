/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_error.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/29 11:27:55 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/14 06:36:09 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void			check_argv(char *argv, t_utilities *utilities)
{
	utilities->type = -1;
	if (ft_strcmp("Mandelbrot", argv) == 0 ||
		ft_strcmp("mandelbrot", argv) == 0)
		utilities->type = 0;
	if (ft_strcmp("Julia", argv) == 0 || ft_strcmp("julia", argv) == 0)
		utilities->type = 1;
	if (ft_strcmp("Julia^5", argv) == 0 || ft_strcmp("julia^5", argv) == 0)
		utilities->type = 2;
	if (ft_strcmp("Mandelbrot^5", argv) == 0 ||
		ft_strcmp("mandelbrot^5", argv) == 0)
		utilities->type = 3;
	if (ft_strcmp("Joulala", argv) == 0 || ft_strcmp("joulala", argv) == 0)
		utilities->type = 4;
	if (ft_strcmp("Burning_Ship", argv) == 0 || ft_strcmp("burning_ship", argv)
		== 0)
		utilities->type = 5;
	if (ft_strcmp("Alien", argv) == 0 || ft_strcmp("alien", argv)
		== 0)
		utilities->type = 6;
	if (ft_strcmp("Weird", argv) == 0 || ft_strcmp("weird",
		argv) == 0)
		utilities->type = 7;
}

int					check_error(int argc, char *argv, t_utilities *utilities)
{
	if (argc != 2)
	{
		ft_putendl(USAGE);
		return (0);
	}
	else
	{
		check_argv(argv, utilities);
		if (utilities->type == -1)
		{
			ft_putendl(ft_strjoin(FRACTYPE, FRACTYPE_2));
			return (0);
		}
	}
	return (1);
}
