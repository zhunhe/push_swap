/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:11:17 by juhur             #+#    #+#             */
/*   Updated: 2022/03/03 16:39:00 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

bool	rra(t_push_swap *ps, int count, bool prints_func)
{
	int	*tmp;

	if (ps->a.top < 0)
		return (false);
	tmp = (int *)malloc(sizeof(int) * count);
	if (tmp == NULL)
		quit_push_swap(ps, ERROR);
	deep_copy(tmp, ps->a.stack, count);
	deep_copy(ps->a.stack, ps->a.stack + count, ps->a.top + 1 - count);
	deep_copy(ps->a.stack + ps->a.top - count + 1, tmp, count);
	free(tmp);
	tmp = NULL;
	if (prints_func)
		while (count--)
			println((char *)__func__);
	return (true);
}

bool	rrb(t_push_swap *ps, int count, bool prints_func)
{
	int	*tmp;

	if (ps->b.top < 0)
		return (false);
	tmp = (int *)malloc(sizeof(int) * count);
	if (tmp == NULL)
		quit_push_swap(ps, ERROR);
	deep_copy(tmp, ps->b.stack, count);
	deep_copy(ps->b.stack, ps->b.stack + count, ps->b.top + 1 - count);
	deep_copy(ps->b.stack + ps->b.top - count + 1, tmp, count);
	free(tmp);
	tmp = NULL;
	if (prints_func)
		while (count--)
			println((char *)__func__);
	return (true);
}

bool	rrr(t_push_swap *ps, int count)
{
	if (ps->a.top < 0 || ps->b.top < 0)
		return (false);
	rra(ps, count, false);
	rrb(ps, count, false);
	while (count--)
		println((char *)__func__);
	return (true);
}
