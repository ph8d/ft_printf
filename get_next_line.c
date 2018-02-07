/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:09:28 by rtarasen          #+#    #+#             */
/*   Updated: 2018/01/21 16:31:19 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

static	int		put_line(t_node *node, char ***line, char **buf_tmp, int n)
{
	size_t	new_buf_size;
	char	*tmp_buf;

	if (*line == NULL)
		return (-1);
	if (*buf_tmp == NULL)
		return (0);
	**line = ft_strsub(node->buf, 0, (size_t)n);
	if ((node->buf_len - n) == 0)
	{
		node->buf_len = 0;
		ft_strdel(buf_tmp);
		ft_strdel(&node->buf);
		return (1);
	}
	new_buf_size = (size_t)(node->buf_len - n) - 1;
	tmp_buf = ft_strsub(node->buf + (n + 1), 0, new_buf_size);
	free(node->buf);
	node->buf = ft_strdup(tmp_buf);
	free(tmp_buf);
	node->buf_len = (int)new_buf_size;
	free(*buf_tmp);
	return (1);
}

static	t_node	*get_new_node(t_node *lst_ptr, int fd)
{
	t_node *result;

	if ((result = (t_node *)malloc(sizeof(t_node))) == NULL)
		return (NULL);
	result->buf = ft_strdup("");
	result->fd = fd;
	result->buf_len = 0;
	result->prev = NULL;
	if (lst_ptr == NULL)
		result->next = NULL;
	else
	{
		while (lst_ptr->prev != NULL)
			lst_ptr = lst_ptr->prev;
		lst_ptr->prev = result;
		result->next = lst_ptr;
	}
	return (result);
}

static	void	search_for_this_fd(t_node **lst_ptr, int fd, char **buf_tmp)
{
	*buf_tmp = ft_strnew(BUFF_SIZE);
	if ((*lst_ptr) == NULL)
		*lst_ptr = get_new_node(*lst_ptr, fd);
	else
	{
		while ((*lst_ptr)->next != NULL || (*lst_ptr)->fd == fd)
		{
			if ((*lst_ptr)->fd == fd)
				return ;
			*lst_ptr = (*lst_ptr)->next;
		}
		while ((*lst_ptr)->prev != NULL || (*lst_ptr)->fd == fd)
		{
			if ((*lst_ptr)->fd == fd)
				return ;
			*lst_ptr = (*lst_ptr)->prev;
		}
		*lst_ptr = get_new_node(*lst_ptr, fd);
	}
}

static	int		get_line_break_pos(char const *node_buf, ssize_t buf_len)
{
	int pos;

	pos = 0;
	if (buf_len == 0)
		return (-1);
	while (pos != buf_len && node_buf[pos] != '\n')
		pos++;
	if (node_buf[pos] == '\n')
		return (pos);
	return (-1);
}

int				get_next_line(const int fd, char **line)
{
	int				line_break_pos;
	char			*buf_tmp;
	char			*str_tmp;
	static	t_node	*node;
	ssize_t			read_ret;

	search_for_this_fd(&node, fd, &buf_tmp);
	while ((line_break_pos = get_line_break_pos(node->buf, node->buf_len)) < 0)
	{
		if ((read_ret = read(fd, buf_tmp, BUFF_SIZE)) < 1)
		{
			if (node->buf_len == 0)
				ft_strdel(&buf_tmp);
			if (read_ret == -1)
				return (-1);
			return (put_line(node, &line, &buf_tmp, (int)node->buf_len));
		}
		str_tmp = ft_strjoin(node->buf, buf_tmp);
		free(node->buf);
		node->buf = ft_strdup(str_tmp);
		free(str_tmp);
		node->buf_len += read_ret;
	}
	return (put_line(node, &line, &buf_tmp, line_break_pos));
}
