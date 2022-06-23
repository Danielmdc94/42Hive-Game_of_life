/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:01:03 by dpalacio          #+#    #+#             */
/*   Updated: 2022/06/23 18:51:58 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/visualizer.h"

void	controls(t_core *core)
{
	if (core->sdl.event.type == SDL_KEYDOWN)
		on_keydown(core);
}

void	on_keydown(t_core *core)
{
	if (core->sdl.event.key.keysym.sym == SDLK_ESCAPE)
		core->is_runing = 0;
	if (core->sdl.event.key.keysym.sym == SDLK_RIGHT)
	{
		if (core->map.step < core->map.iterations)
			core->map.step++;
	}
	if (core->sdl.event.key.keysym.sym == SDLK_LEFT)
	{
		if (core->map.step > 0)
			core->map.step--;
	}
	if (core->sdl.event.key.keysym.sym == SDLK_SPACE)
	{
		if (core->map.automatic == 0)
			core->map.automatic++;
		else if (core->map.automatic == 1)
			core->map.automatic--;
//		if (core->map.automatic == 0)
//			core->map.automatic = 1;
//		if (core->map.automatic == 1)
//			core->map.automatic = 0;
	}
	printf("%d\n", core->map.automatic);
}
