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
        return (0);
    while(list)
    {
        i = 0;
        while(list->content[i] && i < BUFFER_SIZE)
        {
            if (list->content[i] == '\n')
                return (1);
            i++;
        }
        list = list->next;
    }
    return (0);
}

void    copy_str(t_list *list, char *str)
{
    int i;
    int j;

    if (!list)
        return ;
    j = 0;
    while (list)
    {
        i = 0;
        while(list->content[i])
        {
            if (list->content[i] == '\n')
            {
                str[j++] = '\n';
                str[j] = '\0'; 
                list = list->next;
                return ;
            }
            str[j++] = list->content[i++];
        }
        list = list->next;
    }
    str[j] = '\0';
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

void    dealloc(t_list **list, t_list *clean_node, char *buf)
{
    t_list *temp;

    if (!(*list))
        return ;
    while (*list)
    {
        temp = ((*list)->next);
        free((*list)->content);
        free(*list);
        *list = temp;
    }
    *list = NULL;
    if (clean_node->content[0])
        *list = clean_node;
    else
    {
        free(buf);
        free(clean_node);
    }
}

t_list	*find_last_node(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}