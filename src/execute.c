/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 21:59:02 by jmorneau          #+#    #+#             */
/*   Updated: 2022/08/13 20:25:15 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char **final_cmd(char **arg, char *read_file)
{
	char **cmd;
	int i;
	int j;

	i = 0;
	j = 0;
	while (arg[i] != NULL)
		i++;
	cmd = malloc(sizeof(char *) * (i + 2));
	if (!cmd)
		return (NULL);
	while (j < i)
	{
		cmd[j] = arg[j];
		j++;
	}
	cmd[j] = read_file;
	cmd[j + 1] = NULL;
	return (cmd);
}

int	execute(char *path_to_command, char **argv, char **envp, char *read_file)
{
	int id;
	// int fd;
	char **cmd;
	// (void)read_file;
	

	// fd = open("text.txt", O_RDONLY);
	id = fork();
	if (id == 0)
	{
		cmd = final_cmd(argv, read_file);
		if (execve(path_to_command, cmd, envp) == -1)
		{
			perror("Error");
			return (1);
		}
	}
	wait(NULL);
	// close(fd);
	return (0);
}
