/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_timer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:32:30 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/09/16 22:13:35 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void		timer_init(t_timer *time)
{
	(void)(time);
	time->start_ticks = 0;
	time->paused_ticks = 0;
	time->paused = false;
	time->started = false;
}

void		timer_start(t_timer *time)
{
	(void)(time);
	time->started = true;
	time->paused = false;
	time->start_ticks = SDL_GetTicks();
	time->paused_ticks = 0;
}

void		timer_stop(t_timer *time)
{
	(void)(time);
	time->started = false;
	time->paused = false;
	time->start_ticks = 0;
	time->paused_ticks = 0;
}

void		timer_pause(t_timer *time)
{
	if (time->started && !time->paused)
	{
		time->paused = true;
		time->paused_ticks = SDL_GetTicks() - time->start_ticks;
		time->start_ticks = 0;
	}
}

void		timer_unpause(t_timer *time)
{
	if (time->started && time->paused)
	{
		time->paused = false;
		time->start_ticks = SDL_GetTicks() - time->paused_ticks;
		time->paused_ticks = 0;
	}
}
