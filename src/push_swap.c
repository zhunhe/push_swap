/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:53:45 by juhur             #+#    #+#             */
/*   Updated: 2022/03/01 00:26:40 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "push_swap.h"

static bool	is_sorted(t_push_swap *ps)
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
		ra(ps, true);
	else if (ps->a.stack[1] == ps->count)
		rra(ps, true);
	if (ps->a.stack[ps->a.top] == ps->a.stack[ps->a.top - 1] + 1)
		sa(ps, true);
}

static void	a_to_b(t_push_swap *ps)
{
	int	i;

	i = 0;
	while (ps->lis.to_b_count)
	{
		if (i < ps->lis.len && ps->a.stack[ps->a.top] == ps->lis.nums[i])
		{
			ra(ps, true);
			if (i < ps->lis.len)
				i++;
		}
		else
		{
			pb(ps);
			--ps->lis.to_b_count;
		}
		if (is_sorted(ps))
			break ;
	}
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

void	push_swap(int count, char **nums, bool one_string)
{
	t_push_swap	ps;

	if (one_string)
		count = count_word(*nums);
	if (count < 2)
		return ;
	nums = ft_split(*nums, ' ', count);
	if (nums == NULL)
		quit_push_swap(&ps, ERROR);
	init_push_swap(&ps, count);
	to_integer(&ps, nums);
	if (one_string)
		free_2d_array((void **)nums, ps.count);
	align(&ps);
	if (!is_sorted(&ps))
	{
		lis(&ps);
		a_to_b(&ps);
	}
}
