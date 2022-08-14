/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:40:03 by jmorneau          #+#    #+#             */
/*   Updated: 2022/08/13 20:10:56 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
# define FDF

# include "./libft.h"
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>

char	*find(char **envp, char *cmd);
int	execute(char *path_to_command, char **argv, char **envp, char *read_file);
void 	*print_error();
char **final_cmd(char **arg, char *read_file);


#endif