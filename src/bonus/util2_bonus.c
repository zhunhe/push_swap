/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 12:55:22 by juhur             #+#    #+#             */
/*   Updated: 2023/01/01 13:46:28 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	deep_copy(int *dst, int *src, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		dst[i] = src[i];
}

void	swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	if (*(unsigned char *)s1 < *(unsigned char *)s2)
		return (-1);
	return (1);
}
