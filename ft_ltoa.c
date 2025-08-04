/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:40:32 by dacortes          #+#    #+#             */
/*   Updated: 2025/08/04 10:25:47 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ispn(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

static size_t	num_len(long long num)
{
	size_t	len;

	len = (num <= 0);
	while (num)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_ltoa(long long num)
{
	char	*str;
	size_t	len;

	len = num_len(num);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -((unsigned long long)num);
	}
	else if (num == 0)
		str[0] = '0';
	while (num != 0)
	{
		len--;
		str[len] = ft_ispn(num % 10) + '0';
		num = num / 10;
	}
	return (str);
}
