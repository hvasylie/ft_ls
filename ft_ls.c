/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:17:15 by hvasylie          #+#    #+#             */
/*   Updated: 2019/10/20 16:55:57 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int ac, char **av)
{
	t_finfo	*head;

	head = malloc(sizeof(t_finfo));
	initialize(head);
	read_flags(head, av, ac);
	head->flag->rr == 0 ? no_rflag(head) : rflag(head);
	free_everything(head);
	return (0);
}
