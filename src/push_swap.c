/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:53:45 by juhur             #+#    #+#             */
/*   Updated: 2022/02/25 15:11:38 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

static void	init_push_swap(t_push_swap *ps, int count)
{
	int	i;

	ps->count = count;
	ps->nums = (int **)malloc(sizeof(int *) * ps->count);
	ps->tmp = (int **)malloc(sizeof(int *) * ps->count);
	ps->stack_a = (int *)malloc(sizeof(int) * ps->count);
	ps->stack_b = (int *)malloc(sizeof(int) * ps->count);
	if (ps->nums == NULL || ps->tmp == NULL \
		|| ps->stack_a == NULL || ps->stack_b == NULL)
		quit_push_swap(ps, MALLOC_ERROR);
	i = -1;
	while (++i < ps->count)
	{
		ps->nums[i] = (int *)malloc(sizeof(int) * 2);
		ps->tmp[i] = (int *)malloc(sizeof(int) * 2);
		if (ps->nums[i] == NULL || ps->tmp[i] == NULL)
			quit_push_swap(ps, MALLOC_ERROR);
	}
	ps->top_a = ps->count;
	ps->top_b = 0;
}

void	push_swap(int count, char **nums)
{
	t_push_swap	ps;

	init_push_swap(&ps, count);
	to_integer(&ps, nums);
}

static void	free_2d_array(t_push_swap *ps, void **ptr)
{
	int	i;

	if (ptr != NULL)
	{
		i = -1;
		while (++i < ps->count)
		{
			if (ptr[i])
				free(ptr[i]);
			ptr[i] = NULL;
		}
		free(ptr);
		ptr = NULL;
	}
}

static void	free_1d_array(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
	ptr = NULL;
}

void	quit_push_swap(t_push_swap *ps, char *str)
{
	if (ps != NULL)
	{
		free_2d_array(ps, (void **)ps->nums);
		free_2d_array(ps, (void **)ps->tmp);
		free_1d_array((void *)ps->stack_a);
		free_1d_array((void *)ps->stack_b);
	}
	if (str != NULL)
		write(1, str, ft_strlen(str));
	exit(0);
}
