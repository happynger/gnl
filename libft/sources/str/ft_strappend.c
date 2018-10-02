/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 20:05:23 by otahirov          #+#    #+#             */
/*   Updated: 2018/10/01 20:56:28 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend(char *dst, const char *src,
			size_t dst_len, size_t src_len)
{
	if (!(dst = (char *)ft_realloc((void *)dst,
	dst_len, dst_len + src_len + 2)))
		return (NULL);
	dst = ft_strncat(dst, src, src_len + dst_len);
	dst[src_len + dst_len] = '\0';
	return (dst);
}
