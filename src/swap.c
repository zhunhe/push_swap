/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:21:18 by juhur             #+#    #+#             */
/*   Updated: 2022/02/25 15:41:37 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sa(t_push_swap *ps)
{
	if (ps->top_a < 1)
		return (false);
	ps->stack_a[ps->top_a] ^= ps->stack_a[ps->top_a - 1];
	ps->stack_a[ps->top_a - 1] ^= ps->stack_a[ps->top_a];
	ps->stack_a[ps->top_a] ^= ps->stack_a[ps->top_a - 1];
	return (true);
}

bool	sb(t_push_swap *ps)
{
	if (ps->top_b < 1)
		return (false);
	ps->stack_b[ps->top_b] ^= ps->stack_b[ps->top_b - 1];
	ps->stack_b[ps->top_b - 1] ^= ps->stack_b[ps->top_b];
	ps->stack_b[ps->top_b] ^= ps->stack_b[ps->top_b - 1];
	return (true);
}

bool	ss(t_push_swap *ps)
{
	if (ps->top_a < 1 || ps->top_b < 1)
		return (false);
	sa(ps);
	sb(ps);
	return (true);
}
