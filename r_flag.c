/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:24:35 by hvasylie          #+#    #+#             */
/*   Updated: 2019/10/20 16:55:53 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		insert(t_finfo *head, char *new_str, char *name)
{
	t_listt			*end;
	t_listt			*beginning;
	struct stat		t_stat;

	beginning = malloc(sizeof(t_listt));
	lstat(new_str, &t_stat);
	add_info(beginning, name, t_stat);
	end = head->flag_list;
	if (f_list(beginning, head) == 1)
		return ;
	while (end->next != NULL)
		end = end->next;
	end->next = beginning;
}

void			add_info(t_listt *new, char *new_name, struct stat t_stat)
{
	new->flag_name = new_name;
	new->block = t_stat.st_blocks;
	new->gid = t_stat.st_gid;
	new->mode = t_stat.st_mode;
	new->nsecond = t_stat.st_mtimespec.tv_nsec;
	new->second = t_stat.st_mtimespec.tv_sec;
	new->nlink = t_stat.st_nlink;
	new->size = t_stat.st_size;
	new->uid = t_stat.st_uid;
	new->rdev = t_stat.st_rdev;
	new->next = NULL;
}

void			no_rflag(t_finfo *head)
{
	t_finfo		*new;
	struct stat	t_stat;

	new = malloc(sizeof(t_finfo));
	new->flag_list = NULL;
	head->flag_list == NULL ? single_fold(head, new) : mult_fold(head, new);
}

static void		single_fold(t_finfo *head, t_finfo *new)
{
	DIR				*dir;
	struct dirent	*readir;

	if ((dir = opendir(".")) != NULL)
	{
		while ((readir = readdir(dir)) != NULL)
			insert(new, readir->d_name, readir->d_name);
		closedir(dir);
	}
	disp_hidden(head, new);
	free(new);
	list_free(new);
}

static void		mult_fold(t_finfo *head, t_finfo *new)
{
	DIR				*dir;
	struct dirent	*readir;
	char			*full_name;
	t_listt			*folders;

	folders = head->flag_list;
	while (folders)
	{
		if ((dir = opendir(folders->flag_name)) != NULL)
		{
			ft_putstr(folders->flag_name);
			while ((readir = readdir(dir)) != NULL)
			{
				full_name = ctn(folders, readir);
				insert(new, full_name, readir->d_name);
			}
			closedir(dir);
		}
		disp_hidden(head, new);
		new->flag_list = NULL;
		list_free(new);
		folders = folders->next;
	}
	free(new);
}
