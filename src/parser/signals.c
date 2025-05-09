/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 10:36:34 by rhernand          #+#    #+#             */
/*   Updated: 2025/05/09 16:59:06 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"
#include "../../inc/parser.h"
#include <signal.h>

volatile sig_atomic_t	g_exit_status = 0;

void	ft_signal_flags(void)
{
	pid_t	pid;

	printf("process id %d\n groupid %d\n", getpid(), tcgetpgrp(STDIN_FILENO));
	pid = getpid();
	tcsetpgrp(STDIN_FILENO, pid);
	printf("process id %d\n groupid %d\n", getpid(), tcgetpgrp(STDIN_FILENO));
}

void	sigint_handler(int signo)
{
	g_exit_status = 128 + signo;
	write(STDOUT_FILENO, "\n", 1);
	printf("process id %d\n groupid %d\n", getpid(), tcgetpgrp(STDIN_FILENO));
	if (isatty(STDIN_FILENO) && getpid() == tcgetpgrp(STDIN_FILENO)
		&& g_exit_status != -1)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	ft_signal(void)
{
	struct sigaction	sa_int;
	struct sigaction	sa_quit;

	sa_int.sa_handler = sigint_handler;
	sigemptyset(&sa_int.sa_mask);
	sa_int.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &sa_int, NULL) == -1)
		return (perror("Sigaction ERROR"));
	sigemptyset(&sa_quit.sa_mask);
	sa_quit.sa_flags = SA_RESTART;
	sa_quit.sa_handler = SIG_IGN;
	if (sigaction(SIGQUIT, &sa_quit, NULL) == -1)
		return (perror("Sigaction ERROR"));
}
