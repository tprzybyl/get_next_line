/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 16:52:52 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 18:06:26 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 25

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"

int					get_next_line(const int fd, char **line);

#endif
