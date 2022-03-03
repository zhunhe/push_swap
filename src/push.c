/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:47:23 by juhur             #+#    #+#             */
/*   Updated: 2022/03/03 20:47:15 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_push_swap *ps)
{
	if (ps->b.top < 0)
		return ;
	ps->a.stack[++ps->a.top] = ps->b.stack[ps->b.top];
	ps->b.stack[ps->b.top--] = 0;
	println((char *)__func__);
}

void	pb(t_push_swap *ps)
{
	if (ps->a.top < 0)
		return ;
	ps->b.stack[++ps->b.top] = ps->a.stack[ps->a.top];
	ps->a.stack[ps->a.top--] = 0;
	println((char *)__func__);
}
