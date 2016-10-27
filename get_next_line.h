/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 18:27:19 by vtenigin          #+#    #+#             */
/*   Updated: 2016/10/26 18:41:18 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

# include <unistd.h>
# include <stdlib.h>

int get_next_line(const int fd, char **line);

#endif
