/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:23:56 by juhur             #+#    #+#             */
/*   Updated: 2022/02/24 18:47:32 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

static int	ft_atoi(t_push_swap *ps, const char *s)
{
	long long	ret;
	int			sign;

	if (*s == '-')
	{
		sign = -1;
		++s;
	}
	else
		sign = 1;
	ret = 0;
	while (*s != '\0')
	{
		if (*s < '0' || *s > '9')
			quit_push_swap(ps, INVALID_CHAR);
		ret = ret * 10 + *s - '0';
		if (sign * ret > INT_MAX)
			quit_push_swap(ps, ERROR_OVERFLOW);
		else if (sign * ret < INT_MIN)
			quit_push_swap(ps, ERROR_UNDERFLOW);
		++s;
	}
	return (ret);
}

static void	check_duplicate(t_push_swap *ps)
{
	int	i;

	i = -1;
	while (++i < ps->count - 1)
		if (ps->sorted[i] == ps->sorted[i + 1])
			quit_push_swap(ps, ERROR_DUPLICATE);
}

static void	merge(t_push_swap *ps, int st, int en)
{
	int mid = (st + en) / 2;
	int l = st;
	int r = mid;
	for (int i = st; i < en; i++) {
		if (r == en)
			ps->tmp[i] = ps->sorted[l++];
		else if (l == mid)
			ps->tmp[i] = ps->sorted[r++];
		else if (ps->sorted[l] <= ps->sorted[r])
			ps->tmp[i] = ps->sorted[l++];
		else
			ps->tmp[i] = ps->sorted[r++];
	}
	for (int i = st; i < en; i++)
		ps->sorted[i] = ps->tmp[i];
}

static void	merge_sort(t_push_swap *ps, int st, int en)
{
	if (en - st == 1)
		return;
	int mid = (st + en) / 2;
	merge_sort(ps, st, mid);
	merge_sort(ps, mid, en);
	merge(ps, st, en);
}

void	to_integer(t_push_swap *ps, char **nums)
{
	int	i;

	i = -1;
	while (++i < ps->count)
	{
		ps->nums[i] = ft_atoi(ps, nums[i]);
		ps->sorted[i] = ps->nums[i];
	}	
	merge_sort(ps, 0, ps->count);
	check_duplicate(ps);
}
