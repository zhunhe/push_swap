/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:46:44 by juhur             #+#    #+#             */
/*   Updated: 2022/03/06 19:44:08 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	ra(t_push_swap *ps, int count, bool prints_func)
{
	int	i;
	int	*tmp;

	if (ps->a.top < 0 || count == 0)
		return ;
	tmp = ft_calloc(ps, sizeof(int), count);
	deep_copy(tmp, ps->a.stack + ps->a.top - count + 1, count);
	i = ps->a.top - count + 1;
	while (--i >= 0)
		ps->a.stack[i + count] = ps->a.stack[i];
	deep_copy(ps->a.stack, tmp, count);
	free(tmp);
	tmp = NULL;
	if (prints_func)
		while (count--)
			println((char *)__func__);
}

void	rb(t_push_swap *ps, int count, bool prints_func)
{
	int	i;
	int	*tmp;

	if (ps->b.top < 0 || count == 0)
		return ;
	tmp = ft_calloc(ps, sizeof(int), count);
	deep_copy(tmp, ps->b.stack + ps->b.top - count + 1, count);
	i = ps->b.top - count + 1;
	while (--i >= 0)
		ps->b.stack[i + count] = ps->b.stack[i];
	deep_copy(ps->b.stack, tmp, count);
	free(tmp);
	tmp = NULL;
	if (prints_func)
		while (count--)
			println((char *)__func__);
}

void	rr(t_push_swap *ps, int count)
{
	if (ps->a.top < 0 || ps->b.top < 0 || count == 0)
		return ;
	ra(ps, count, false);
	rb(ps, count, false);
	while (count--)
		println((char *)__func__);
}
