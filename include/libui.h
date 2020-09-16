/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 20:29:09 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/09/16 22:35:51 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_H
# define LIBUI_H

# include <math.h>
# include <stdbool.h>
# include "SDL.h"
# include "SDL_image.h"
# include "SDL_mixer.h"
# include "SDL_ttf.h"
# include "SDL_net.h"

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_pointf
{
	double			x;
	double			y;
}					t_pointf;

typedef struct		s_rect
{
	int				x;
	int				y;
	int				w;
	int				h;
	bool			free;
}					t_rect;

typedef struct		s_rectf
{
	double			x;
	double			y;
	double			w;
	double			h;
	bool			free;
}					t_rectf;

typedef struct			s_limit
{
	int					cur;
	int					max;
	int					min;
}						t_limit;

typedef struct			s_limit_f
{
	float				cur;
	float				max;
	float				min;
}						t_limit_f;

typedef struct			s_timer
{
	Uint32				start_ticks;
	Uint32				paused_ticks;
	bool				paused;
	bool				started;
	int					counted_frames;
}						t_timer;

typedef struct			s_mouse
{
	bool				is_presed;
	int					prew_x;
	int					prew_y;
	int					x;
	int					y;
}						t_mouse;

typedef struct			s_color
{
	Uint8				red;
	Uint8				green;
	Uint8				blue;
}						t_color;

void					ft_bzero(void *s, size_t n);
void					*ft_memalloc(size_t size);
void					ft_putstr(char *s);
size_t					ft_strlen(const char *s);
void					ft_putnbr(int n);
void					ft_putchar(char c);

/*
** struct_timer.c
*/
void					timer_init(t_timer *time);
void					timer_start(t_timer *time);
void					timer_stop(t_timer *time);
void					timer_pause(t_timer *time);
void					timer_unpause(t_timer *time);
/*
** timer.c
*/
Uint32					get_ticks(t_timer *time);
bool					time_is_started(t_timer *time);
bool					time_is_paused(t_timer *time);
void					fps_counter(t_timer *time);
/*
** tools_for_editor/tools.c
*/
void					drag_and_drop(SDL_Surface *src, SDL_Surface *dst);
void					scale_frame(SDL_Surface *dst, t_mouse mouse,
							Uint32 color, void draw(SDL_Surface *,
							t_rect *, Uint32, int));
void					draw_rect(SDL_Surface *dst,
							t_rect *rect, Uint32 color, int step);
void					draw_feel_rect(SDL_Surface *dst,
							t_rect *rect, Uint32 color, int step);
/*
** accses_pixel.c
*/
Uint32					get_pixel(SDL_Surface *surface, int x, int y);
void					putpixel(SDL_Surface *surface,
							int x, int y, Uint32 pixel);
void					clear_surface(SDL_Surface *surface, Uint32 color);
Uint32					color8_to_32(t_color color);
t_color					color32_to_8(Uint32 color);
/*
** frame.c
*/
void					scale_rect_texture(SDL_Surface *dst, t_mouse mouse, SDL_Surface *src);

void					if_rect(SDL_Surface *src, t_rect *rsrc,
							SDL_Surface *dst, t_rect *rdst);

void					blit_surf_scaled(SDL_Surface *src, t_rect *rsrc,
							SDL_Surface *dst, t_rect *rdst);
void					blit_surface(SDL_Surface *src, t_rect *rsrc,
							SDL_Surface *dst, t_rect *rdst);

t_rect					*rect_fill(int x, int y, int w, int h);
t_rect					rect_fill_no_malloc(int x, int y, int w, int h);
void					draw_line(SDL_Surface *dst, t_point start, t_point end, Uint32 color);
void					draw_circl(SDL_Surface *dst, int radius,
							t_point center, Uint32 color);
void					draw_fill_circl(SDL_Surface *dst, int radius,
							t_point center, Uint32 color);
void					draw_smooth_rect(SDL_Surface *dst, t_rect *rect,
							Uint32 color, int thickness);
void					draw_smooth_fill_rect(SDL_Surface *dst, t_rect *rect,
							Uint32 color);
void					put_button(SDL_Surface *dst, t_rect *rect,
							Uint32 color_fill, Uint32 color_frame);

void					put_slide_bar(SDL_Surface *dst, t_rect *rect, t_limit *data, Uint32 color);
float					interpolate(t_limit_f x, t_limit_f c);
void					fill_limit(t_limit *data, int min, int cur, int max);
void					fill_limit_f(t_limit_f *data, float min, float cur, float max);

bool					is_button_area(t_rect *area, t_mouse mouse);
void					is_mouse_presed(t_mouse *mouse);
bool					is_slidebar_area(t_rect *area, t_mouse mouse);
int						which_button(bool *mouse);

t_point					fill_point(int x, int y);

#endif
