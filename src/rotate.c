/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:46:44 by juhur             #+#    #+#             */
/*   Updated: 2022/03/03 15:28:40 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

bool	ra(t_push_swap *ps, int count, bool prints_func)
{
	int	i;
	int	*tmp;

	if (ps->a.top < 0)
		return (false);
	tmp = (int *)malloc(sizeof(int) * count);
	if (tmp == NULL)
		quit_push_swap(ps, ERROR);
	i = -1;
	while (++i < count)
		tmp[i] = ps->a.stack[ps->a.top - count + 1 + i];
	i = ps->a.top - count + 1;
	while (--i >= 0)
		ps->a.stack[i + count] = ps->a.stack[i];
	i = -1;
	while (++i < count)
		ps->a.stack[i] = tmp[i];
	free(tmp);
	tmp = NULL;
	if (prints_func)
		while (count--)
			println((char *)__func__);
	return (true);
}

bool	rb(t_push_swap *ps, int count, bool prints_func)
{
	int	i;
	int	*tmp;

	if (ps->b.top < 0)
		return (false);
	tmp = (int *)malloc(sizeof(int) * count);
	if (tmp == NULL)
		quit_push_swap(ps, ERROR);
	i = -1;
	while (++i < count)
		tmp[i] = ps->b.stack[ps->b.top - count + 1 + i];
	i = ps->b.top - count + 1;
	while (--i >= 0)
		ps->b.stack[i + count] = ps->b.stack[i];
	i = -1;
	while (++i < count)
		ps->b.stack[i] = tmp[i];
	free(tmp);
	tmp = NULL;
	if (prints_func)
		while (count--)
			println((char *)__func__);
	return (true);
}

bool	rr(t_push_swap *ps, int count)
{
	if (ps->a.top < 0 || ps->b.top < 0)
		return (false);
	ra(ps, count, false);
	rb(ps, count, false);
	while (count--)
		println((char *)__func__);
	return (true);
}
