/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:46:44 by juhur             #+#    #+#             */
/*   Updated: 2022/02/28 17:52:22 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ra(t_push_swap *ps, bool prints_func)
{
	int	i;
	int	tmp;

	if (ps->a.top < 0)
		return (false);
	tmp = ps->a.stack[ps->a.top];
	i = ps->a.top;
	while (--i >= 0)
		ps->a.stack[i + 1] = ps->a.stack[i];
	ps->a.stack[0] = tmp;
	if (prints_func)
		println((char *)__func__);
	return (true);
}

bool	rb(t_push_swap *ps, bool prints_func)
{
	int	i;
	int	tmp;

	if (ps->b.top < 0)
		return (false);
	tmp = ps->b.stack[ps->b.top];
	i = ps->b.top;
	while (--i >= 0)
		ps->b.stack[i + 1] = ps->b.stack[i];
	ps->b.stack[0] = tmp;
	if (prints_func)
		println((char *)__func__);
	return (true);
}

bool	rr(t_push_swap *ps)
{
	if (ps->a.top < 0 || ps->b.top < 0)
		return (false);
	ra(ps, false);
	rb(ps, false);
	println((char *)__func__);
	return (true);
}
