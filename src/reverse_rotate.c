/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:11:17 by juhur             #+#    #+#             */
/*   Updated: 2022/02/27 20:25:53 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	rra(t_push_swap *ps)
{
	int	i;
	int	tmp;

	if (ps->top_a < 0)
		return (false);
	tmp = ps->stack_a[0];
	i = -1;
	while (++i < ps->top_a)
		ps->stack_a[i] = ps->stack_a[i + 1];
	ps->stack_a[ps->top_a] = tmp;
	return (true);
}

bool	rrb(t_push_swap *ps)
{
	int	i;
	int	tmp;

	if (ps->top_b < 0)
		return (false);
	tmp = ps->stack_b[0];
	i = -1;
	while (++i < ps->top_b)
		ps->stack_b[i] = ps->stack_b[i + 1];
	ps->stack_b[ps->top_b] = tmp;
	return (true);
}

bool	rrr(t_push_swap *ps)
{
	if (ps->top_a < 0 || ps->top_b < 0)
		return (false);
	rra(ps);
	rrb(ps);
	return (true);
}