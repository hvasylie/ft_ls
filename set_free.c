/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:42:24 by hvasylie          #+#    #+#             */
/*   Updated: 2019/10/20 16:55:50 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	listok_free(t_listt *list)
{
	t_listt *new_list;
	t_listt *dif_list;

	new_list = list;
	while (list != NULL)
	{
		dif_list = list->next;
		free(list);
		list = dif_list;
	}
}

void	list_free(t_finfo *head)
{
	t_listt *list;
	t_listt *new_list;

	list = head->flag_list;
	while (list != NULL)
	{
		new_list = list->next;
		free(list);
		list = new_list;
	}
}

void	free_everything(t_finfo *head)
{
	list_free(head);
	free(head->flag);
	free(head);
}

void	rflag(t_finfo *head)
{
	ft_putstr(head->echo_rr);
	ft_putchar('\n');
}
