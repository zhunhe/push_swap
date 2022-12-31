/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:19:03 by juhur             #+#    #+#             */
/*   Updated: 2023/01/01 12:55:20 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap_bonus.h"

int	ft_strlen(const char *s)
{
	const char	*e;

	e = s;
	while (*e != '\0')
		++e;
	return (e - s);
}

void	fill_n(int *array, int len, int val)
{
	int	i;

	i = -1;
	while (++i < len)
		array[i] = val;
}

void	*ft_calloc(struct s_push_swap_bonus *ps, int size, int len)
{
	void	*p;

	p = (void *)malloc(size * len);
	if (p == NULL)
		quit_push_swap(ps, ERROR);
	fill_n(p, len, 0);
	return (p);
}

void	reverse(int *arr, int len)
{
	int	i;

	i = -1;
	while (++i < len / 2)
		swap(&arr[i], &arr[len - 1 - i]);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
