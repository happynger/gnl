/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 09:59:07 by otahirov          #+#    #+#             */
/*   Updated: 2018/09/20 21:44:44 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*p;
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	p = (char *)ptr;
	while (size-- > 0)
		*p++ = 0;
	return (ptr);
}
