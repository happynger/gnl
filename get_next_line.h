/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:31:15 by otahirov          #+#    #+#             */
/*   Updated: 2018/10/10 13:55:02 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 64
# define ERR (fd <= -1 || line == NULL)
# define R1 (str_read)
# define R3 (list[0])
# define AA1 ft_strlen(str_array[2])
# define AA2 ft_strlen(str_array[0])
# define AA3 ft_strlen(list->content)
# define READ_M(arr) { free(arr); arr = NULL; return (NULL); }
# define MV_FD(x) while (x->fd != fd && x->next) x = x->next
# define MV_NL(s) while (*s != '\n' && *s) s++
# define CHECK_EX(s) if (*s) ft_strncpy(arr[1], ++s, i[1])

# include "libft/includes/libft.h"
# include <libc.h>

int		get_next_line(const int fd, char **line);

#endif
