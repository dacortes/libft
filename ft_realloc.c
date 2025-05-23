/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 08:54:08 by dacortes          #+#    #+#             */
/*   Updated: 2025/05/23 09:05:36 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new;

	if (!new_size)
	{
		if (ptr)
			free(ptr);
		return (NULL);
	}
	if (!ptr)
	{
		ptr = malloc(new_size);
		if (!ptr)
			return (NULL);
	}
	new = malloc(new_size);
	if (!new)
		return (NULL);
	if (old_size > 0 && old_size < new_size)
		ft_memcpy(new, ptr, old_size);
	else if (old_size > 0)
		ft_memcpy(new, ptr, new_size);
	free(ptr);
	return (new);
}
