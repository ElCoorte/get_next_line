/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:53:23 by yzakharc          #+#    #+#             */
/*   Updated: 2017/03/16 08:49:31 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check(char *str, int *i)
{
	int j;

	j = 0;
	while (*str)
	{
		if (j != 1)
			(*str != '\n') ? (*i)++ : (j = 1);
		str++;
	}
	j = (*str == '\0') ? 1 : 0;
	return (j);
}

int	ft_write(char **str, char **line)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	if (ft_check(*str, &i))
	{
		*line = ft_strsub(*str, 0, (size_t)i);
		if (i == (int)ft_strlen(*str))
			*str = ft_strnew(0);
	}
	if ((**str && **line) || (!**line && **str == '\n') || (**line && !**str))
		j = 1;
	!**str && !**line ? j = 0 : 0;
	**str != '\0' ? (*str) += i + 1 : 0;
	return (j);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str;
	char		*buf;
	ssize_t		r_res;

	buf = ft_strnew(BUFF_SIZE);
	while ((r_res = read(fd, buf, BUFF_SIZE)) > 0)
	{
		str = (str == NULL) ? ft_strdup(buf) : ft_strjoin(str, buf);
		ft_strclr(buf);
		if (ft_strchr(str, '\n'))
			break ;
	}
	if (r_res == 0 && !ft_strlen(str))
	{
		**line ? **line = '\0' : 0;
		return (0);
	}
	if (r_res == -1 || fd == -1)
		return (-1);
	return (ft_write(&str, line));
}