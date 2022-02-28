/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:47:23 by juhur             #+#    #+#             */
/*   Updated: 2022/02/28 17:10:35 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	pa(t_push_swap *ps)
{
	if (ps->b.top < 0)
		return (false);
	ps->a.stack[++ps->a.top] = ps->b.stack[ps->b.top];
	ps->b.stack[ps->b.top--] = 0;
	println((char *)__func__);
	return (true);
}

bool	pb(t_push_swap *ps)
{
	if (ps->a.top < 0)
		return (false);
	ps->b.stack[++ps->b.top] = ps->a.stack[ps->a.top];
	ps->a.stack[ps->a.top--] = 0;
	println((char *)__func__);
	return (true);
}
