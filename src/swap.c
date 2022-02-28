/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:21:18 by juhur             #+#    #+#             */
/*   Updated: 2022/02/28 17:14:24 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sa(t_push_swap *ps, bool prints_func)
{
	if (ps->a.top < 1)
		return (false);
	swap(&ps->a.stack[ps->a.top], &ps->a.stack[ps->a.top - 1]);
	if (prints_func)
		println((char *)__func__);
	return (true);
}

bool	sb(t_push_swap *ps, bool prints_func)
{
	if (ps->b.top < 1)
		return (false);
	swap(&ps->b.stack[ps->b.top], &ps->b.stack[ps->b.top - 1]);
	if (prints_func)
		println((char *)__func__);
	return (true);
}

bool	ss(t_push_swap *ps)
{
	if (ps->a.top < 1 || ps->b.top < 1)
		return (false);
	sb(ps, false);
	sa(ps, false);
	println((char *)__func__);
	return (true);
}
