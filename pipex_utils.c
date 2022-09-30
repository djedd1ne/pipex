/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 05:32:02 by djmekki           #+#    #+#             */
/*   Updated: 2022/09/30 21:54:16 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

char	**ft_split_path(char **envp)
{
	int		i;
	char	**path_names;
	char	*name;
	char	separator;

	i = 0;
	name = "PATH=";
	separator = ':';
	while (envp[i])
	{
		if (ft_strncmp(envp[i], name, 5) == 0)
		{
			path_names = ft_split(envp[i] + 5, separator);
			return (path_names);
		}
		i++;
	}
	return (NULL);
}

void	concise_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	free_2d_array(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

char	*add_slash(char *path_name)
{
	int		len;
	char	c;
	char	*str;

	len = ft_strlen(path_name);
	c = '/';
	str = (char *)malloc(sizeof(char *) * len + 2);
	if (!str)
		return (NULL);
	ft_memcpy(str, path_name, len);
	str[len] = c;
	str[++len] = '\0';
	return (str);
}
