/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:46:44 by juhur             #+#    #+#             */
/*   Updated: 2022/02/25 17:55:14 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ra(t_push_swap *ps)
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

bool	rb(t_push_swap *ps)
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

bool	rr(t_push_swap *ps)
{
	if (ps->top_a < 0 || ps->top_b < 0)
		return (false);
	ra(ps);
	rb(ps);
	return (true);
}
