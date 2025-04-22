/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohifdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:10:57 by mohifdi           #+#    #+#             */
/*   Updated: 2025/04/18 18:10:59 by mohifdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef get_next_line.h
# define get_next_line.h

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 1024

// **** files utils ****
typedef struct s_list
{
    char    *content;
        struct s_list *next;
}   t_list;



char    *get_next_line(int fd);

#endif
