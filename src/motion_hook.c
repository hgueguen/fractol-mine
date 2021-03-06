/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgueguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 11:06:02 by hgueguen          #+#    #+#             */
/*   Updated: 2016/05/23 11:06:06 by hgueguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			motion_hook(int x, int y, t_env *e)
{
	int		ref_x;
	int		ref_y;

	e->mouse_pos[0] = x;
	e->mouse_pos[1] = y;
	if (e->motion_enabled == 0)
		return (0);
	ref_y = e->win_y / 2;
	ref_x = e->win_x / 2;
	if ((x >= 0 && x <= e->win_x) && (y >= 0 && y <= e->win_y))
	{
		e->modifier_z[0] = 0 + 0.01 * (ref_x - x);
		e->modifier_z[1] = 0 + 0.01 * (ref_y - y);
	}
	expose_event(e);
	return (0);
}
