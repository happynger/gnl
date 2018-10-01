/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:31:03 by otahirov          #+#    #+#             */
/*   Updated: 2018/10/01 16:13:41 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	initiate_list(const int fd, t_list **lst)
{
	t_list	*list;
	t_list	*head;

	list = *lst;
	head = *lst;
	if (list == NULL)
	{
		list = ft_lstnew(NULL, 0);
		list->fd = fd;
		*lst = list;
	}
	while (list->next && list->fd != fd)
		list = list->next;
	if (list->fd == fd)
		return ;
	ft_lstaddend(&list, ft_lstnew(NULL, 0));
	*lst = head;
	while (list->next)
		list = list->next;
	list->fd = fd;
}

int		ft_free(char **arr, int ret, char *str_read)
{
	int		i;

	i = 0;
	while (i < 3 && ret != -1)
		ft_strdel(&arr[i++]);
	ft_strdel(&str_read);
	if (ret != -1)
		free(arr);
	arr = NULL;
	return (ret);
}

char	**ft_strsplit_nl(char *str, int bytes_read, t_list *list, const int fd)
{
	char	**arr;
	char	*s;
	int		i[2];

	arr = (char **)malloc(3 * sizeof(*arr));
	while (list->fd != fd && list->next)
		list = list->next;
	if (list->content)
		list->content = ft_strappend(list->content, str,
			ft_strlen(list->content), bytes_read);
	else
		list->content = ft_strdup(str);
	s = list->content;
	while (*s != '\n' && *s)
		s++;
	if ((!*s && bytes_read == BUFF_SIZE) || bytes_read == -1)
		return (NULL);
	i[0] = s - list->content;
	i[1] = ft_strlen(s + 1);
	arr[0] = ft_strnew(i[0]);
	arr[1] = ft_strnew(i[1]);
	ft_strncpy(arr[1], ++s, i[1]);
	s = list->content;
	ft_strncpy(arr[0], s, i[0] + 1);
	return (arr);
}

int		ft_copy(char ***line, char **arr, t_list *list)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_strnew(ft_strlen(arr[2]));
	while (arr[2][i] && arr[2][i] != '\n')
	{
		s[i] = arr[2][i];
		i++;
	}
	**line = s;
	if (arr[2][i] == '\0' && list->br == 0)
		return (0);
	else
	{
		ft_strdel(&list->content);
		list->content = ft_strdup(arr[1]);
		return (1);
	}
}

int		get_next_line(const int fd, char **line)
{
	char			*str_read;
	int				bytes_read;
	char			**str_array;
	static t_list	*list[2];

	if (ERR)
		return (-1);
	initiate_list(fd, &list[0]);
	str_read = ft_strnew(BUFF_SIZE);
	while ((str_array = ft_strsplit_nl(str_read,
		bytes_read = read(fd, str_read, BUFF_SIZE), list[0], fd)) == NULL)
		{
			free(str_array);
			if (bytes_read == -1) 
				return (ft_free(str_array, -1, str_read));
		}
	list[1] = list[0];
	while (list[1]->fd != fd && list[1]->next)
		list[1] = list[1]->next;
	list[1]->br = bytes_read;
	str_array[2] = ft_strnew(BUFF_SIZE);
	if (ft_strcmp(str_array[2], str_array[0]) != 0)
		str_array[2] = ft_strappend(str_array[2], str_array[0], AA1, AA2);
	return (ft_free(str_array, ft_copy(&line, str_array, list[1]), str_read));
}

int main()
{
	char *line;
	int fd;
	int fd2;
	int fd3;
	int	diff_file_size;
    
	for (int i = 0; i < 100; i++)
    {
		system("mkdir -p sandbox");
		system("openssl rand -out sandbox/large_file.txt -base64 $((50 * 1000 * 3/4)) 2> /dev/null");

		fd = open("sandbox/large_file.txt", O_RDONLY);
		fd2 = open("sandbox/large_file.txt.mine", O_CREAT | O_RDWR | O_TRUNC, 0755);

		while (get_next_line(fd, &line) == 1)
		{
			write(fd2, line, strlen(line));
			write(fd2, "\n", 1);
			free (line);
		}
		close(fd);
		close(fd2);

		system("diff sandbox/large_file.txt sandbox/large_file.txt.mine > sandbox/large_file.diff");
		fd3 = open("sandbox/large_file.diff", O_RDONLY);
		diff_file_size = read(fd3, NULL, 10);
		close(fd3);
		
		if (diff_file_size == 0)
			printf("OK.");
	}
}
