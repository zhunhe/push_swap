/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:11:17 by juhur             #+#    #+#             */
/*   Updated: 2022/02/28 12:20:17 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	rra(t_push_swap *ps)
{
	int	i;
	int	tmp;

	if (ps->a.top < 0)
		return (false);
	tmp = ps->a.stack[0];
	i = -1;
	while (++i < ps->a.top)
		ps->a.stack[i] = ps->a.stack[i + 1];
	ps->a.stack[ps->a.top] = tmp;
	return (true);
}

bool	rrb(t_push_swap *ps)
{
	int	i;
	int	tmp;

	if (ps->b.top < 0)
		return (false);
	tmp = ps->b.stack[0];
	i = -1;
	while (++i < ps->b.top)
		ps->b.stack[i] = ps->b.stack[i + 1];
	ps->b.stack[ps->b.top] = tmp;
	return (true);
}

bool	rrr(t_push_swap *ps)
{
	if (ps->a.top < 0 || ps->b.top < 0)
		return (false);
	rra(ps);
	rrb(ps);
	return (true);
}
