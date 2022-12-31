/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:21:18 by juhur             #+#    #+#             */
/*   Updated: 2022/03/03 20:45:14 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_push_swap *ps, bool prints_func)
{
	if (ps->a.top < 1)
		return ;
	swap(&ps->a.stack[ps->a.top], &ps->a.stack[ps->a.top - 1]);
	if (prints_func)
		println((char *)__func__);
}

void	sb(t_push_swap *ps, bool prints_func)
{
	if (ps->b.top < 1)
		return ;
	swap(&ps->b.stack[ps->b.top], &ps->b.stack[ps->b.top - 1]);
	if (prints_func)
		println((char *)__func__);
}

void	ss(t_push_swap *ps)
{
	if (ps->a.top < 1 || ps->b.top < 1)
		return ;
	sb(ps, false);
	sa(ps, false);
	println((char *)__func__);
}
