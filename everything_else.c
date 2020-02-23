/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   everything_else.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:28:29 by hvasylie          #+#    #+#             */
/*   Updated: 2019/10/20 16:55:58 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		display_ext(t_finfo *head, t_listt *listok)
{
	ft_putstr("Total: ");
	ft_putnbr(head->tot);
	ft_putstr("\n");
	while (listok)
	{
		while (head->flag->a == 0 && listok->flag_name[0] == '.')
			listok = listok->next;
		display_info(listok);
		listok = listok->next;
	}
}

char		*id_user(uid_t id)
{
	struct passwd	*uid;

	if (!(uid = getpwuid(id)))
		return (NULL);
	return (uid->pw_name);
}

t_listt		*list_sort(t_listt *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next && ft_strcmp(lst->flag_name, lst->next->flag_name) > 0)
		lst = ft_list_swap(lst, lst->next);
	lst->next = list_sort(lst->next);
	if (lst->next && ft_strcmp(lst->flag_name, lst->next->flag_name) > 0)
	{
		lst = ft_list_swap(lst, lst->next);
		lst->next = list_sort(lst->next);
	}
	return (lst);
}

t_listt		*ft_list_swap(t_listt *src, t_listt *dst)
{
	src->next = dst->next;
	dst->next = src;
	return (dst);
}
