/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:02:56 by juhur             #+#    #+#             */
/*   Updated: 2022/02/28 15:17:51 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *s)
{
	const char	*e;

	e = s;
	while (*e != '\0')
		++e;
	return (e - s);
}

void	swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void	deep_copy(int *dst, int *src, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		dst[i] = src[i];
}

void	reverse(int *arr, int len)
{
	int	i;

	i = -1;
	while (++i < len / 2)
		swap(&arr[i], &arr[len - 1 - i]);
}