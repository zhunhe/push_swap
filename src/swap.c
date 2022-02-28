/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:21:18 by juhur             #+#    #+#             */
/*   Updated: 2022/02/28 14:49:54 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sa(t_push_swap *ps)
{
	if (ps->a.top < 1)
		return (false);
	swap(&ps->a.stack[ps->a.top], &ps->a.stack[ps->a.top - 1]);
	return (true);
}

bool	sb(t_push_swap *ps)
{
	if (ps->b.top < 1)
		return (false);
	swap(ps->b.stack[ps->b.top], ps->b.stack[ps->b.top - 1]);
	return (true);
}

bool	ss(t_push_swap *ps)
{
	if (ps->a.top < 1 || ps->b.top < 1)
		return (false);
	sa(ps);
	sb(ps);
	return (true);
}
