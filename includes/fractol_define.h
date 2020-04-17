/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol_define.h                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/07 11:06:08 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/14 06:43:59 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_DEFINE_H
# define FRACTOL_DEFINE_H

# define WIDTH 1280
# define HEIGHT 720
# define WINWI 400
# define WINHE 750
# define MAX_ITERATION 101

# define PI 3.14159265359

# define WHITE 0xffffff
# define BLACK 0x0

# define MIDDLE_MOUSE 3
# define SCROLL_DOWN 4
# define SCROLL_UP 5
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define UNO 0//83
# define DOS 1//84
# define TRES 2//85
# define QUATRO 3//86
# define CINCO 4//87
# define SIX 5//88

# define KEY_ESC 53

# define F1 122
# define F2 120
# define F3 99
# define F4 118
# define F5 96
# define F6 97
# define F7 98
# define F8 100
/*
 *** DEFINE INFO STRING
*/

# define USAGE "./Fractol fractal_type"
# define FRACTYPE "Mandelbrot || Julia || Mandelbrot^5 || Julia^5 || Joulala ||"
# define FRACTYPE_2 " Burning Ship || Alien || Weird"

# define TITLE " //  F  R  A  C  T  '  O  L  //"

# define SWTCHFRCT "S W I T C H  F R A C T A L"
# define FF1 "F1 : classical Mandelbrot set"
# define FF2 "F2 : classical Julia set"
# define FF3 "F3 : quintuple Julia set"
# define FF4 "F4 : quintuple Mandelbrot set"
# define FF5 "F5 : Joulala set"
# define FF6 "F6 : burning ship"
# define FF7 "F7 : alien"
# define FF8 "F8 : weird"

# define CHNG_CLR "C H A N G E  C O L O R S"
# define UN "1 : black & white"
# define DEUX "2 : green & purple"
# define TROIS "3 : red & blue"
# define QUATRE "4 : psychedelic colors >> 4++"
# define CINQ "5 : fireflies noise"
# define SIXX "6 : classical noise"
# define MOUSE "T R A V E L"
# define SCROLUP "SCROLL_UP : zoom in"
# define SCROLDWN "SCROLL_DOWN : zoom out"
# define MOVE "MOVE THE MOUSE : and enjoy..."

# define ESCAPE "ESC : quit"

# define UPP "^ : translate up"
# define LEFTT "< : translate left"
# define RIGHTT "> : translate right"
# define DOWNN "v : translate down"

# define BREAK "-----------------------------------------"
#endif
