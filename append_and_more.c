/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_and_more.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:27:24 by hvasylie          #+#    #+#             */
/*   Updated: 2019/10/20 16:56:00 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		list_nameset(t_finfo *head, char *new_str)
{
	t_listt	*beginning;
	t_listt	*end;

	beginning = malloc(sizeof(t_listt));
	end = head->flag_list;
	beginning->flag_name = new_str;
	end->next = NULL;
	if (!(head->flag_list))
	{
		head->flag_list = beginning;
		return ;
	}
	while (end->next != NULL)
		end = end->next;
	end->next = beginning;
}

char		*ctn(t_listt *fold, struct dirent *readir)
{
	char *result;

	result = malloc(ft_strlen(fold->flag_name) + ft_strlen(readir->d_name) + 3);
	ft_strcpy(result, fold->flag_name);
	result = ft_strcat(result, "/");
	ft_strcat(result, readir->d_name);
	return (result);
}

void		fold_free(t_finfo *new)
{
	free(new);
	list_free(new);
}

int			f_list(t_listt *beginning, t_finfo *head)
{
	if (head->flag_list == NULL)
	{
		head->flag_list = beginning;
		return (1);
	}
	return (0);
}
