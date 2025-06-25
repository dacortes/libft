/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:40:32 by dacortes          #+#    #+#             */
/*   Updated: 2025/06/25 15:41:03 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ispn(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

static int	num_len(long long num)
{
	int	len;

	len = (num <= 0);
	while (num)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_ltoa(long long num, int *len)
{
	char	*str;

	(*len) = num_len(num);
	str = malloc(sizeof(char) * ((*len) + 1));
	if (!str)
		return (NULL);
	str[*len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -((unsigned long long)num);
	}
	while (num != 0)
	{
		(*len)--;
		str[*len] = ft_ispn(num % 10) + '0';
		num = num / 10;
	}
	return (str);
}
