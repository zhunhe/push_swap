/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:46:44 by juhur             #+#    #+#             */
/*   Updated: 2022/02/28 12:19:41 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ra(t_push_swap *ps)
{
	int	i;
	int	tmp;

	if (ps->a.top < 0)
		return (false);
	tmp = ps->a.stack[ps->a.top];
	i = -1;
	while (++i < ps->a.top)
		ps->a.stack[i + 1] = ps->a.stack[i];
	ps->a.stack[0] = tmp;
	return (true);
}

bool	rb(t_push_swap *ps)
{
	int	i;
	int	tmp;

	if (ps->b.top < 0)
		return (false);
	tmp = ps->b.stack[ps->b.top];
	i = -1;
	while (++i < ps->b.top)
		ps->b.stack[i + 1] = ps->b.stack[i];
	ps->b.stack[0] = tmp;
	return (true);
}

bool	rr(t_push_swap *ps)
{
	if (ps->a.top < 0 || ps->b.top < 0)
		return (false);
	ra(ps);
	rb(ps);
	return (true);
}