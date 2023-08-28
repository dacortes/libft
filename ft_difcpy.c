/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_difcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:36:10 by dacortes          #+#    #+#             */
/*   Updated: 2023/08/28 13:00:35 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_difcpy(char *str, char c, int start)
{
	char	*new;
	int		len;

	if (!str)
		return (NULL);
	len = start;
	while (str[len] && str[len] != c)
		len++;
	new = ft_substr(str, start, len);
	if (!new)
		return (NULL);
	return (new);
}
