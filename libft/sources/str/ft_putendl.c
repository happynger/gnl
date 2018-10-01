/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 19:26:35 by otahirov          #+#    #+#             */
/*   Updated: 2018/09/16 22:29:09 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	char	*temp;

	if (s)
	{
		temp = ft_strdup(s);
		ft_strcat(temp, "\n");
		ft_putstr(temp);
		ft_strdel(&temp);
	}
}
