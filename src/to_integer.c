/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:23:56 by juhur             #+#    #+#             */
/*   Updated: 2022/02/28 14:47:47 by juhur            ###   ########.fr       */
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
		if (ps->nums[i][NUMBER] == ps->nums[i + 1][NUMBER])
			quit_push_swap(ps, ERROR_DUPLICATE);
}

static void	merge(t_push_swap *ps, int st, int en)
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
		{
			ps->tmp[i][NUMBER] = ps->nums[l][NUMBER];
			ps->tmp[i][ORDER] = ps->nums[l++][ORDER];
		}
		else if (l == mid)
		{
			ps->tmp[i][NUMBER] = ps->nums[r][NUMBER];
			ps->tmp[i][ORDER] = ps->nums[r++][ORDER];
		}
		else if (ps->nums[l][NUMBER] <= ps->nums[r][NUMBER])
		{
			ps->tmp[i][NUMBER] = ps->nums[l][NUMBER];
			ps->tmp[i][ORDER] = ps->nums[l++][ORDER];
		}
		else
		{
			ps->tmp[i][NUMBER] = ps->nums[r][NUMBER];
			ps->tmp[i][ORDER] = ps->nums[r++][ORDER];
		}
	}
	i = st - 1;
	while (++i < en)
	{
		ps->nums[i][NUMBER] = ps->tmp[i][NUMBER];
		ps->nums[i][ORDER] = ps->tmp[i][ORDER];
	}
}

static void	merge_sort(t_push_swap *ps, int st, int en)
{
	int	mid;

	if (en - st == 1)
		return ;
	mid = (st + en) / 2;
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
		ps->nums[i][0] = ft_atoi(ps, nums[i]);
		ps->nums[i][1] = i;
	}
	merge_sort(ps, 0, ps->count);
	check_duplicate(ps);
	i = -1;
	while (++i < ps->count)
		ps->a.stack[ps->nums[i][ORDER]] = i + 1;
	i = -1;
	while (++i < ps->count / 2)
		swap(ps->a.stack[i], ps->a.stack[ps->count - 1 - i]);
}