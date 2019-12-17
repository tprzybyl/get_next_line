/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 16:47:27 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 18:08:10 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static int		ft_strgetfrom(const int fd, char **str)
{
	char				tmp[BUFF_SIZE + 1];
	int					ret;

	while ((ret = read(fd, tmp, BUFF_SIZE)))
	{
		if (ret < 0)
			return (1);
		tmp[ret] = '\0';
		if (!(*str))
			*str = ft_memalloc(1);
		*str = ft_strfjoin(*str, tmp);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char			*str[256];

	if (ft_strgetfrom(fd, &str[fd]))
		return (-1);
	if (!(*str[fd]))
	{
		*line = NULL;
		return (0);
	}
	if (!str[fd][0])
	{
		ft_strdel(&str[fd]);
		return (0);
	}
	*line = ft_strsub(str[fd], 0, ft_strclen(str[fd], '\n'));
	if (((ft_strclen(str[fd], '\n') + 1) == ft_strlen(str[fd])) ||
			(ft_strclen(str[fd], '\n') == ft_strlen(str[fd])))
		str[fd][0] = '\0';
	else
		str[fd] = ft_strfsub(str[fd], (1 + ft_strclen(str[fd], '\n')),
				ft_strlen(str[fd]));
	return (1);
}
