/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:23:00 by hvasylie          #+#    #+#             */
/*   Updated: 2019/10/20 16:55:51 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		flag_identifier(t_finfo *flags, char *av)
{
	int i;

	i = 1;
	while (av[i] != '\0')
	{
		if (av[i] == 'a')
			flags->flag->a = 1;
		if (av[i] == 'l')
			flags->flag->l = 1;
		if (av[i] == 't')
			flags->flag->t = 1;
		if (av[i] == 'r')
			flags->flag->r = 1;
		if (av[i] == 'R')
			flags->flag->rr = 1;
		if (av[i] != 'a' && av[i] != 'l' && av[i] != 't'
						&& av[i] != 'r' && av[i] != 'R')
		{
			ft_putstr("Incorrect pattern");
			ft_putstr(", ");
			ft_putstr("Make sure usage is correct(ls -alRrt file_name)\n");
			exit(0);
		}
		i++;
	}
}

static int		check_fold(char *str)
{
	struct stat statbuf;
	int			bool;

	bool = S_ISDIR(statbuf.st_mode);
	if (stat(str, &statbuf))
		return (0);
	return (bool);
}

void			read_flags(t_finfo *head, char **av, int ac)
{
	int i;
	int final_f;

	head->flag_list = NULL;
	head->echo_rr = "R flag :)";
	i = 1;
	final_f = 0;
	while (i < ac)
	{
		if (final_f == 0)
			flag_identifier(head, av[i]);
		else if (av[i][0] != '-' || final_f == 1)
		{
			check_fold(av[i]) ? list_nameset(head, av[i]) : ft_error(2, av[i]);
			final_f = 1;
		}
		i++;
	}
}

void			initialize(t_finfo *flags)
{
	flags->flag = (t_flag *)malloc(sizeof(t_flag));
	flags->flag->a = 0;
	flags->flag->l = 0;
	flags->flag->t = 0;
	flags->flag->r = 0;
	flags->flag->rr = 0;
	flags->tot = 0;
}

void			ft_error(int code, char *str)
{
	if (code == 1)
	{
		ft_putstr("Make sure usage is correct (ls -alRrt file_name)\n");
		exit(0);
	}
	if (code == 2)
	{
		ft_putstr("not the folder\n");
		ft_putstr(str);
		exit(0);
	}
}
