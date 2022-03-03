/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:41:09 by juhur             #+#    #+#             */
/*   Updated: 2022/03/03 16:56:32 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_index_a(t_push_swap *ps, int val)
{
	int	i;
	int	idx;
	int	_max;
	int	_min;

	_max = 0;
	_min = ps->count + 1;
	i = -1;
	while (++i < ps->a.top + 1)
	{
		_max = max(_max, ps->a.stack[i]);
		if (ps->a.stack[i] < _min)
		{
			_min = ps->a.stack[i];
			idx = i;
		}
	}
	if (val > _max || val < _min)
		return (idx);
	i = -1;
	while (++i < ps->a.top)
		if (val < ps->a.stack[i] && val > ps->a.stack[i + 1])
			return (i);
	return (ps->a.top);
}

static void	set_data(int *array, int index, int value)
{
	int	i;

	if (index == RB || index == RRB || index == RA || index == RRA)
		array[index] = value;
	else if (index == RR || index == RRR)
	{
		array[index] = value;
		array[index + 1] -= array[index];
		array[index + 2] -= array[index];
	}
	else if (index == COUNT)
	{
		i = RR - 1;
		while (++i < RRB + 1)
			array[COUNT] += array[i];
	}
}

static void	set_move_data(t_push_swap *ps)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ps->b.top + 1)
	{
		fill_n(ps->tmp[i], 7, 0);
		if (i >= ps->b.top / 2)
			set_data(ps->tmp[i], RB, ps->b.top - i);
		else
			set_data(ps->tmp[i], RRB, i + 1);
		j = get_index_a(ps, ps->b.stack[i]);
		if (j >= ps->a.top / 2)
			set_data(ps->tmp[i], RA, ps->a.top - j);
		else
			set_data(ps->tmp[i], RRA, j + 1);
		set_data(ps->tmp[i], RR, min(ps->tmp[i][RA], ps->tmp[i][RB]));
		set_data(ps->tmp[i], RRR, min(ps->tmp[i][RRA], ps->tmp[i][RRB]));
		set_data(ps->tmp[i], COUNT, 0);
	}
}

static int	*get_array(t_push_swap *ps)
{
	int	i;
	int	idx;
	int	min_val;

	min_val = ps->count + 1;
	i = ps->b.top + 1;
	while (--i >= 0)
	{
		if (ps->tmp[i][COUNT] < min_val)
		{
			min_val = ps->tmp[i][COUNT];
			idx = i;
		}
	}
	return (ps->tmp[idx]);
}

void	b_to_a(t_push_swap *ps)
{
	int	*array;

	while (ps->b.top >= 0)
	{
		set_move_data(ps);
		array = get_array(ps);
		if (array[RR] > 0)
			rr(ps, array[RR]);
		if (array[RA] > 0)
			ra(ps, array[RA], true);
		if (array[RB] > 0)
			rb(ps, array[RB], true);
		if (array[RRR] > 0)
			rrr(ps, array[RRR]);
		if (array[RRA] > 0)
			rra(ps, array[RRA], true);
		if (array[RRB] > 0)
			rrb(ps, array[RRB], true);
		pa(ps);
	}
}
