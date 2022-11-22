/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:44:42 by jmorneau          #+#    #+#             */
/*   Updated: 2022/11/17 18:49:33 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	check_file(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0 || 1 <= 0 || read(fd, 0, 0) < 0)
	{
		perror("Error ");
		close(fd);
		return (0);
	}
	return (fd);
}

static int	ft_norminette(char **argv)
{
	ft_free_chartable(argv);
	return (0);
}

static void	ft_norminette_v2(t_pipe *pipex)
{
	ft_free_chartable(pipex->argv);
	free(pipex->path_to_command);
}

int	main(int argc, char **argv, char **envp)
{
	int		nb_cmd;
	t_pipe	pipex;

	if (print_arg(argc))
		return (0);
	pipex.env = envp;
	nb_cmd = 2;
	pipex.file_open = check_file(argv[1]);
	if (!pipex.file_open)
		return (0);
	pipex.file_close = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	pipe(pipex.fd);
	while (nb_cmd < argc - 1)
	{
		pipex.argv = ft_split(argv[nb_cmd], ' ');
		if (*envp && access(pipex.argv[0], F_OK))
		{
			pipex.path_to_command = find(envp, pipex.argv[0]);
			if (!pipex.path_to_command)
				return (ft_norminette(pipex.argv));
		}
		exec_cmd(&pipex, nb_cmd++, argc);
		ft_norminette_v2(&pipex);
	}
}
