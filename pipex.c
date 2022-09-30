/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:27:37 by djmekki           #+#    #+#             */
/*   Updated: 2022/09/30 22:10:41 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

void	execute(char *cmd, char **envp)
{
	int		i;
	char	**argv;
	char	**path_names;
	char	*file;

	argv = ft_split(cmd, ' ');
	path_names = ft_split_path(envp);
	if (path_names == NULL)
		ft_error("Error:\nNo PATH found");
	i = 0;
	while (path_names[i])
	{
		file = ft_strjoin(add_slash(path_names[i]), argv[0]);
		if (access(file, F_OK) == 0)
		{
			if (execve(file, argv, NULL) == -1)
				concise_perror("Error\n");
		}
		free(file);
		i++;
	}
	free_2d_array(argv);
	free_2d_array(path_names);
	concise_perror("Error:\n");
}

void	execute_cmd1(char **argv, char **envp, int *fd)
{
	int		fd_infile;

	fd_infile = open(argv[1], O_RDONLY);
	if (fd_infile < 0)
		concise_perror("Error\n");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		concise_perror("Error\n");
	if (dup2(fd_infile, STDIN_FILENO) == -1)
		concise_perror("Error\n");
	close(fd[0]);
	close(fd_infile);
	close(fd[1]);
	execute(argv[2], envp);
}

void	execute_cmd2(char **argv, char **envp, int *fd)
{
	int		fd_outfile;

	fd_outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd_outfile < 0)
		concise_perror("Error: output file\n");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		concise_perror("Error\n");
	if (dup2(fd_outfile, STDOUT_FILENO) == -1)
		concise_perror("Error\n");
	close(fd[1]);
	close(fd_outfile);
	close(fd[0]);
	execute(argv[3], envp);
}

void	pipex(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid_1;
	int	pid_2;

	if (argc != 5)
	{
		ft_putendl_fd("Error:\nUse only 4 arguments", 2);
		exit(EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
		concise_perror("Error\n");
	pid_1 = fork();
	if (pid_1 == -1)
		concise_perror("Error\n");
	if (pid_1 == 0)
		execute_cmd1(argv, envp, fd);
	pid_2 = fork();
	if (pid_2 == -1)
		concise_perror("Error\n");
	if (pid_2 == 0)
		execute_cmd2(argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid_1, NULL, 0);
	waitpid(pid_2, NULL, 0);
}

int	main(int ac, char **av, char **ep)
{
	pipex(ac, av, ep);
	return (0);
}
