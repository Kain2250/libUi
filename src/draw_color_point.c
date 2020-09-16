/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_color_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:46:47 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/09/16 22:13:23 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void			drow_color_point(SDL_Surface *dst, Uint32 color)
{
	SDL_Point	mouse;

	SDL_GetMouseState(&mouse.x, &mouse.y);
	putpixel(dst, mouse.x, mouse.y, color);
}
