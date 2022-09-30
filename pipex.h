/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 04:42:48 by djmekki           #+#    #+#             */
/*   Updated: 2022/09/30 21:34:36 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <fcntl.h>
# include "./Libft/libft.h"
# include <sys/wait.h>
# include <string.h>
# include <sys/types.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>

char	**ft_split_path(char **envp);
void	concise_perror(char *str);
void	ft_error(char *str);
void	free_2d_array(char **matrix);
char	*add_slash(char *path_name);
void	execute(char *cmd, char **envp);
void	execute_cmd1(char **argv, char **envp, int *fd);
void	execute_cmd2(char **argv, char **envp, int *fd);
void	pipex(int argc, char **argv, char **envp);

#endif