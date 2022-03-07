/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:53:45 by juhur             #+#    #+#             */
/*   Updated: 2022/03/07 20:36:36 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "push_swap.h"

bool	is_sorted(t_push_swap *ps)
{
	int	i;

	i = -1;
	while (++i < ps->count)
		if (ps->a.stack[i] != ps->count - i)
			return (false);
	return (true);
}

static void	align(t_push_swap *ps)
{
	if (ps->a.stack[ps->a.top] == ps->count)
		ra(ps, 1, true);
	else if (ps->a.stack[1] == ps->count)
		rra(ps, 1, true);
	if (ps->a.stack[ps->a.top] == ps->a.stack[ps->a.top - 1] + 1)
		sa(ps, true);
}

void	send_1_to_top(t_push_swap *ps)
{
	int	i;
	int	idx;
	int	cnt;

	i = -1;
	while (++i < ps->a.top + 1)
	{
		if (ps->a.stack[i] == 1)
			idx = i;
	}
	if (idx >= ps->a.top / 2)
		cnt = ps->a.top - idx;
	else
		cnt = -(idx + 1);
	if (cnt > 0)
		ra(ps, cnt, true);
	if (cnt < 0)
		rra(ps, -cnt, true);
}

static int	count_all_word(int len, char **input)
{
	int	ret;
	int	i;

	ret = 0;
	i = -1;
	while (++i < len)
		ret += count_word(input[i]);
	return (ret);
}

void	push_swap(int argc, char **argv)
{
	t_push_swap	ps;
	int			count;

	count = count_all_word(argc - 1, argv + 1);
	init_push_swap(&ps, count);
	split(&ps, argc, argv);
	to_integer(&ps, ps.s);
	align(&ps);
	if (!is_sorted(&ps) && ps.count > 1)
	{
		lis(&ps);
		a_to_b(&ps);
		b_to_a(&ps);
		send_1_to_top(&ps);
	}
	quit_push_swap(&ps, NULL);
}
