/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:41:09 by juhur             #+#    #+#             */
/*   Updated: 2022/03/03 13:04:00 by juhur            ###   ########.fr       */
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
	while (ps->tmp[idx][RR]-- > 0)
		rr(ps, 1);
	while (ps->tmp[idx][RRR]-- > 0)
		rrr(ps);
	if (ps->tmp[idx][RA] > 0)
		ra(ps, ps->tmp[idx][RA], true);
	while (ps->tmp[idx][RRA]-- > 0)
		rra(ps, true);
	if (ps->tmp[idx][RB] > 0)
		rb(ps, ps->tmp[idx][RB], true);
	while (ps->tmp[idx][RRB]-- > 0)
		rrb(ps, true);
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
