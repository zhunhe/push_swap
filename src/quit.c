/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:23:15 by juhur             #+#    #+#             */
/*   Updated: 2022/03/03 02:42:22 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

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

void	quit_push_swap(t_push_swap *ps, char *str)
{
	if (ps != NULL)
	{
		free_2d_array((void **)ps->nums, ps->count);
		free_2d_array((void **)ps->tmp, ps->count);
		free_1d_array((void *)ps->a.stack);
		free_1d_array((void *)ps->b.stack);
		free_1d_array((void *)ps->lis.to_b);
	}
	if (str != NULL)
		write(1, str, ft_strlen(str));
	exit(0);
}
