/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:03:21 by lsomrat           #+#    #+#             */
/*   Updated: 2023/03/23 17:03:23 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	init()
{
	t_list				*cmd_ll;
	t_system			my_env;
	struct sigaction	act;
	struct sigaction	quit;

	*cmd_str = NULL;
	*cmd_ll = NULL;
	my_env.env_path = ft_split(getenv("PATH"), ':');
	my_env.dis_str = ft_strjoin(getenv("USER"), ": ");
	act.sa_handler = sighandler;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	sigaction (SIGINT, &act, NULL);
	quit.sa_handler = SIG_IGN;
	quit.sa_flags = 0;
	sigemptyset(&quit.sa_mask);
	sigaction (SIGQUIT, &quit, NULL);
}
