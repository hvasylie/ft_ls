/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:11:18 by hvasylie          #+#    #+#             */
/*   Updated: 2019/10/19 23:13:40 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <fcntl.h>
# include <grp.h>
# include <pwd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <sys/stat.h>
# include <uuid/uuid.h>
# include <sys/xattr.h>
# include <sys/types.h>
# include "libft/libft.h"

typedef struct				s_flag
{
	int						a;
	int						l;
	int						t;
	int						r;
	int						rr;
}							t_flag;

typedef struct				s_listt
{
	char					directory : 1;
	char					existence : 1;
	char					hidden : 1;
	char					*flag_name;
	char					*path;
	blkcnt_t				block;
	gid_t					gid;
	mode_t					mode;
	nlink_t					nlink;
	long					nsecond;
	uid_t					uid;
	time_t					second;
	off_t					size;
	dev_t					rdev;
	struct s_listt			*next;
}							t_listt;

typedef struct				s_finfo
{
	char					*echo_rr;
	t_flag					*flag;
	t_listt					*flag_list;
	int						tot;
}							t_finfo;

void						list_nameset(t_finfo *head, char *new_str);
char						*ctn(t_listt *fold, struct dirent *readir);
int							f_list(t_listt *beginning, t_finfo *head);
void						display_ext(t_finfo *head, t_listt *listok);
char						*id_user(uid_t id);
t_listt						*list_sort(t_listt *lst);
t_listt						*ft_list_swap(t_listt *src, t_listt *dst);
static char					get_file_type(int mode);
static void					show_access(int mode);
static void					show_time(t_listt *list);
void						disp_hidden(t_finfo *head, t_finfo *new_head);
void						display_info(t_listt *l_list);
static void					insert(t_finfo *head, char *new_data, char *name);
void						add_info(t_listt *new,
					char *name, struct stat t_stat);
void						no_rflag(t_finfo *head);
static void					single_fold(t_finfo *head, t_finfo *new);
static void					mult_fold(t_finfo *head, t_finfo *new);
static void					flag_identifier(t_finfo *flags, char *av);
static int					check_fold(char *str);
void						read_flags(t_finfo *data, char **av, int ac);
void						initialize(t_finfo *flag);
void						ft_error(int code, char *str);
void						listok_free(t_listt *list);
void						list_free(t_finfo *head);
void						free_everything(t_finfo *head);
void						rflag(t_finfo *head);

#endif
