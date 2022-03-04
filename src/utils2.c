/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:42:09 by juhur             #+#    #+#             */
/*   Updated: 2022/03/04 09:46:03 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	fill_n(int *array, int len, int val)
{
	int	i;

	i = -1;
	while (++i < len)
		array[i] = val;
}

void	*ft_calloc(t_push_swap *ps, int size, int len)
{
	void	*p;

	p = (void *)malloc(size * len);
	if (p == NULL)
		quit_push_swap(ps, ERROR);
	fill_n(p, len, 0);
	return (p);
}
