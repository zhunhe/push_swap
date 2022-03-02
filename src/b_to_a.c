/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:41:09 by juhur             #+#    #+#             */
/*   Updated: 2022/03/03 03:21:42 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_max_or_min(t_push_swap *ps, int val, int *idx)
{
	int	i;
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
			*idx = i;
		}
	}
	if (val > _max || val < _min)
		return (true);
	return (false);
}

static int	get_index_a(t_push_swap *ps, int val)
{
	int	i;

	if (is_max_or_min(ps, val, &i))
		return (i);
	i = -1;
	while (++i < ps->a.top)
		if (val < ps->a.stack[i] && val > ps->a.stack[i + 1])
			return (i);
	return (ps->a.top);
}

static void	set_move_data(t_push_swap *ps)
{
	int	i;
	int	idx;

	i = -1;
	while (++i < ps->b.top + 1)
	{
		fill_n(ps->tmp[i], 4, 0);
		if (i >= ps->b.top / 2)
			ps->tmp[i][RB] = ps->b.top - i;
		else
			ps->tmp[i][RB] = -(i + 1);
		idx = get_index_a(ps, ps->b.stack[i]);
		if (idx >= ps->a.top / 2)
			ps->tmp[i][RA] = ps->a.top - idx;
		else
			ps->tmp[i][RA] = -(idx + 1);
		if (ps->tmp[i][RA] * ps->tmp[i][RB])
		{
			if (ps->tmp[i][RA] > 0 && ps->tmp[i][RB] > 0)
				ps->tmp[i][RR] = min(ps->tmp[i][RA], ps->tmp[i][RB]);
			else
				ps->tmp[i][RR] = max(ps->tmp[i][RA], ps->tmp[i][RB]);
			ps->tmp[i][RA] -= ps->tmp[i][RR];
			ps->tmp[i][RB] -= ps->tmp[i][RR];
		}
		ps->tmp[i][COUNT] += abs(ps->tmp[i][RR]);
		ps->tmp[i][COUNT] += abs(ps->tmp[i][RA]);
		ps->tmp[i][COUNT] += abs(ps->tmp[i][RB]);
	}
}

static void	move_to_a(t_push_swap *ps)
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
	while (ps->tmp[idx][RR] > 0)
	{
		rr(ps);
		ps->tmp[idx][RR]--;
	}
	while (ps->tmp[idx][RR] < 0)
	{
		rrr(ps);
		ps->tmp[idx][RR]++;
	}
	while (ps->tmp[idx][RA] > 0)
	{
		ra(ps, true);
		ps->tmp[idx][RA]--;
	}
	while (ps->tmp[idx][RA] < 0)
	{
		rra(ps, true);
		ps->tmp[idx][RA]++;
	}
	while (ps->tmp[idx][RB] > 0)
	{
		rb(ps, true);
		ps->tmp[idx][RB]--;
	}
	while (ps->tmp[idx][RB] < 0)
	{
		rrb(ps, true);
		ps->tmp[idx][RB]++;
	}
	pa(ps);
}

void	b_to_a(t_push_swap *ps)
{
	while (ps->b.top >= 0)
	{
		set_move_data(ps);
		move_to_a(ps);
	}
}
