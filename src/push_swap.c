/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:53:45 by juhur             #+#    #+#             */
/*   Updated: 2022/03/03 16:27:22 by juhur            ###   ########.fr       */
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

int	count_word(char *s)
{
	int	word_cnt;
	int	i;

	word_cnt = 0;
	i = -1;
	while (s[++i] != '\0')
		if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ')
			++word_cnt;
	return (word_cnt);
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

void	push_swap(int count, char **nums, bool one_string)
{
	t_push_swap	ps;

	if (one_string)
		count = count_word(*nums);
	if (count < 2)
		return ;
	nums = ft_split(*nums, count);
	init_push_swap(&ps, count);
	to_integer(&ps, nums);
	if (one_string)
		free_2d_array((void **)nums, ps.count);
	align(&ps);
	if (!is_sorted(&ps))
	{
		lis(&ps);
		a_to_b(&ps);
		b_to_a(&ps);
		send_1_to_top(&ps);
	}
	quit_push_swap(&ps, NULL);
}
