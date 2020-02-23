/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:26:41 by hvasylie          #+#    #+#             */
/*   Updated: 2019/10/20 16:55:55 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char			get_file_type(int mode)
{
	mode = (mode & S_IFMT);
	if (S_ISREG(mode))
		return ('-');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISSOCK(mode))
		return ('s');
	else if (S_ISFIFO(mode))
		return ('p');
	else
		return ('-');
}

static void			show_access(int mode)
{
	char	access[12];

	access[0] = get_file_type(mode);
	access[1] = (S_IRUSR & mode) ? 'r' : '-';
	access[2] = (S_IWUSR & mode) ? 'w' : '-';
	access[3] = (S_IXUSR & mode) ? 'x' : '-';
	access[4] = (S_IRGRP & mode) ? 'r' : '-';
	access[5] = (S_IWGRP & mode) ? 'w' : '-';
	access[6] = (S_IXGRP & mode) ? 'x' : '-';
	access[7] = (S_IROTH & mode) ? 'r' : '-';
	access[8] = (S_IWOTH & mode) ? 'w' : '-';
	access[9] = (S_IXOTH & mode) ? 'x' : '-';
	access[11] = '\0';
	if (S_ISUID & mode)
		access[3] = access[3] == '-' ? 'S' : 's';
	if (S_ISGID & mode)
		access[6] = access[6] == '-' ? 'S' : 's';
	if (S_ISVTX & mode)
		access[9] = access[9] == '-' ? 'T' : 't';
	ft_putstr(access);
}

static void			show_time(t_listt *list)
{
	time_t	today;
	char	*str;
	int		i;

	i = 0;
	time(&today);
	str = ctime(&(list->second)) + 4;
	while (str[i] != '\n')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void				disp_hidden(t_finfo *head, t_finfo *new_head)
{
	t_listt	*l_list;
	t_listt	*start;

	l_list = list_sort(new_head->flag_list);
	start = l_list;
	if (head->flag->l == 1)
		display_ext(head, l_list);
	else
	{
		while (l_list)
		{
			while (head->flag->a == 0 && l_list->flag_name[0] == '.')
				l_list = l_list->next;
			ft_putstr(l_list->flag_name);
			ft_putstr("   ");
			l_list = l_list->next;
		}
		ft_putchar('\n');
	}
	new_head->flag_list = start;
}

void				display_info(t_listt *l)
{
	struct group		*gr;

	gr = getgrgid(l->gid);
	show_access(l->mode);
	ft_putstr("   ");
	ft_putnbr(l->nlink);
	ft_putstr("   ");
	ft_putstr(id_user(l->uid));
	ft_putstr("   ");
	ft_putstr(gr->gr_name);
	ft_putstr("   ");
	ft_putnbr(l->size);
	ft_putstr("   ");
	show_time(l);
	ft_putstr("   ");
	ft_putstr(l->flag_name);
	ft_putchar('\n');
}
