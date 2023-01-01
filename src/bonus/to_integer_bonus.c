/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_integer_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:42:34 by juhur             #+#    #+#             */
/*   Updated: 2023/01/01 15:15:36 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>
#include "push_swap_bonus.h"

static int	ft_atoi(struct s_push_swap_bonus *ps, const char *s)
{
	long long	ret;
	int			sign;

	if (!*s)
		quit_push_swap(ps, ERROR);
	sign = 1;
	if (*s == '-')
	{
		sign = -1;
		++s;
	}
	else if (*s == '+')
		++s;
	ret = 0;
	while (*s != '\0')
	{
		if (*s < '0' || *s > '9')
			quit_push_swap(ps, ERROR);
		ret = ret * 10 + (*s - '0');
		if (sign * ret > INT_MAX || sign * ret < INT_MIN)
			quit_push_swap(ps, ERROR);
		++s;
	}
	return (sign * ret);
}

static void	check_duplicate(struct s_push_swap_bonus *ps)
{
	int	i;

	i = -1;
	while (++i < ps->count - 1)
		if (ps->nums[i][NUMBER] == ps->nums[i + 1][NUMBER])
			quit_push_swap(ps, ERROR);
}

static void	merge(struct s_push_swap_bonus *ps, int st, int en)
{
	int	mid;
	int	l;
	int	r;
	int	i;

	mid = (st + en) / 2;
	l = st;
	r = mid;
	i = st - 1;
	while (++i < en)
	{
		if (r == en)
			deep_copy(ps->tmp[i], ps->nums[l++], 2);
		else if (l == mid)
			deep_copy(ps->tmp[i], ps->nums[r++], 2);
		else if (ps->nums[l][NUMBER] <= ps->nums[r][NUMBER])
			deep_copy(ps->tmp[i], ps->nums[l++], 2);
		else
			deep_copy(ps->tmp[i], ps->nums[r++], 2);
	}
	i = st - 1;
	while (++i < en)
		deep_copy(ps->nums[i], ps->tmp[i], 2);
}

static void	merge_sort(struct s_push_swap_bonus *ps, int st, int en)
{
	int	mid;

	if (en - st == 1)
		return ;
	mid = (st + en) / 2;
	merge_sort(ps, st, mid);
	merge_sort(ps, mid, en);
	merge(ps, st, en);
}

void	to_integer(struct s_push_swap_bonus *ps, char **nums)
{
	int	i;

	i = -1;
	while (++i < ps->count)
	{
		ps->nums[i][NUMBER] = ft_atoi(ps, nums[i]);
		ps->nums[i][ORDER] = i;
	}
	if (ps->count == 1)
		return ;
	merge_sort(ps, 0, ps->count);
	check_duplicate(ps);
	i = -1;
	while (++i < ps->count)
		ps->a.stack[ps->nums[i][ORDER]] = i + 1;
	reverse(ps->a.stack, ps->count);
}
