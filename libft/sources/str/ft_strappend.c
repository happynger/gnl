/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 20:05:23 by otahirov          #+#    #+#             */
/*   Updated: 2018/10/01 14:17:11 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend(char *dst, const char *src,
			size_t dst_len, size_t src_len)
{
	void	*ptr_dst;

	ptr_dst = (void *)dst;
	dst = ft_realloc(&ptr_dst, dst_len, dst_len + src_len + 1);
	ft_strlcat(dst, src, src_len + dst_len + 1);
	dst[src_len + dst_len + 1] = '\0';
	return (dst);
}
