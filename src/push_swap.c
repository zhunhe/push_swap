/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:53:45 by juhur             #+#    #+#             */
/*   Updated: 2022/02/28 12:17:56 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

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
		free_1d_array((void *)ps->a.stack);
		free_1d_array((void *)ps->b.stack);
	}
	if (str != NULL)
		write(1, str, ft_strlen(str));
	exit(0);
}
