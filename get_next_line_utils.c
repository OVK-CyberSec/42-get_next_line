/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohifdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:10:41 by mohifdi           #+#    #+#             */
/*   Updated: 2025/04/18 18:10:45 by mohifdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	found_newline(t_list *list)
{
    int i;

    if (!list)
        return NULL;
    i = 0;
        while(list->content[i] != '\n'
            && list->content[i] != '\0')
            i++;
        if (list->content == '\n')
        {
            list = list->content;
            return 1;
        }
        else
        {
            list = list->content;
            return 0;
        }
    return 0;
}

void  create_list(t_list *list, int fd)
{
    int readed_char;
    char *buf;

    while(!found_newline(*list))
    {
        buf = malloc(BUFFER_SIZE + 1);
        if (!buf)
            return ;
        readed_char = read(fd, buf, BUFFER_SIZE);
        if (!readed_char)
        {
            free(buf);
            return ;
        }
        buf[readed_char] = '\0';
        append(list, buf);
    }
}

char	get_line(t_list *list)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void    copy_str(t_list *list, char *str)
{
    int i;
    int j;

    if (!list)
        return ;
    k = 0;
    while (list)
    {
        i = 0;
        while(list->content[i])
        {
            if (list->content[i] == '\n')
            {
                str[k++] = '\n';
                str[k] = '\0'; 
                list = list->next;
                return ;
            }
            str[k++] = list->content[i++];
        }
        list = list->next;
    }
    
}

int	len_to_newline(t_list *list)
{
    int i;
    int len;
    
    if (list == NULL)
        return (0);
    len = 0;
    while (list)
    {
        i = 0;
        while (list->content[i])
        {
            if (list->content[i] == '\n')
            {
                len++;
                return (len);
            }
            i++;
            len++;
        }
        list = list->next;
    }
    return (len);
}

char	*find_last_node(t_list *lst)
{
    t_list	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}