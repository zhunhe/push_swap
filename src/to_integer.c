/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:23:56 by juhur             #+#    #+#             */
/*   Updated: 2022/02/23 14:06:28 by juhur            ###   ########.fr       */
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

/*
** TODO: n^2 -> nlogn
** merge sort OR quick sort OR red-black tree
*/
static void	check_duplicate(t_push_swap *ps)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ps->count)
	{
		j = i;
		while (++j < ps->count)
		{
			if (ps->nums[i] == ps->nums[j])
				quit_push_swap(ps, ERROR_DUPLICATE);
		}
	}
}

void	to_integer(t_push_swap *ps, char **nums)
{
	int	i;

	i = -1;
	while (++i < ps->count)
		ps->nums[i] = ft_atoi(ps, nums[i]);
	check_duplicate(ps);
}
