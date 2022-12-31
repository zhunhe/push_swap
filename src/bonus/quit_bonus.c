/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:06:39 by juhur             #+#    #+#             */
/*   Updated: 2023/01/01 13:04:59 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap_bonus.h"

void	free_2d_array(void **ptr, int len)
{
	int	i;

	if (ptr != NULL)
	{
		i = -1;
		while (++i < len)
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

void	quit_push_swap(struct s_push_swap_bonus *ps, char *str)
{
	if (ps != NULL)
	{
		free_2d_array((void **)ps->nums, ps->count);
		free_2d_array((void **)ps->tmp, ps->count);
		free_2d_array((void **)ps->s, ps->count);
		free_1d_array((void *)ps->a.stack);
		free_1d_array((void *)ps->b.stack);
	}
	if (str != NULL)
		write(1, str, ft_strlen(str));
	exit(0);
}
