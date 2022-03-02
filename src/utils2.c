/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:42:09 by juhur             #+#    #+#             */
/*   Updated: 2022/03/03 02:55:05 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	abs(int val)
{
	if (val < 0)
		return (-val);
	return (val);
}

void	fill_n(int *array, int len, int val)
{
	int	i;

	i = -1;
	while (++i < len)
		array[i] = val;
}
