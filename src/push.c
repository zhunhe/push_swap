/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:47:23 by juhur             #+#    #+#             */
/*   Updated: 2022/02/25 15:50:40 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	pa(t_push_swap *ps)
{
	if (ps->top_b < 0)
		return (false);
	ps->stack_a[++ps->top_a] = ps->stack_b[ps->top_b];
	ps->stack_b[ps->top_b--] = 0;
	return (true);
}

bool	pb(t_push_swap *ps)
{
	if (ps->top_a < 0)
		return (false);
	ps->stack_b[++ps->top_b] = ps->stack_a[ps->top_a];
	ps->stack_a[ps->top_a--] = 0;
	return (true);
}
