/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:41:09 by juhur             #+#    #+#             */
/*   Updated: 2022/03/03 16:42:37 by juhur            ###   ########.fr       */
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

static void	set_move_data(t_push_swap *ps)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ps->b.top + 1)
	{
		fill_n(ps->tmp[i], 7, 0);
		if (i >= ps->b.top / 2)
			ps->tmp[i][RB] = ps->b.top - i;
		else
			ps->tmp[i][RRB] = i + 1;
		j = get_index_a(ps, ps->b.stack[i]);
		if (j >= ps->a.top / 2)
			ps->tmp[i][RA] = ps->a.top - j;
		else
			ps->tmp[i][RRA] = j + 1;
		ps->tmp[i][RR] = min(ps->tmp[i][RA], ps->tmp[i][RB]);
		ps->tmp[i][RA] -= ps->tmp[i][RR];
		ps->tmp[i][RB] -= ps->tmp[i][RR];
		ps->tmp[i][RRR] = min(ps->tmp[i][RRA], ps->tmp[i][RRB]);
		ps->tmp[i][RRA] -= ps->tmp[i][RRR];
		ps->tmp[i][RRB] -= ps->tmp[i][RRR];
		j = RR - 1;
		while (++j < RRB + 1)
			ps->tmp[i][COUNT] += ps->tmp[i][j];
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
	if (ps->tmp[i][RR] > 0)
		rr(ps, ps->tmp[i][RR]);
	if (ps->tmp[i][RA] > 0)
		ra(ps, ps->tmp[i][RA], true);
	if (ps->tmp[i][RB] > 0)
		rb(ps, ps->tmp[i][RB], true);
	if (ps->tmp[i][RRR] > 0)
		rrr(ps, ps->tmp[i][RRR]);
	if (ps->tmp[i][RRA] > 0)
		rra(ps, ps->tmp[i][RRA], true);
	if (ps->tmp[i][RRB] > 0)
		rrb(ps, ps->tmp[i][RRB], true);
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
