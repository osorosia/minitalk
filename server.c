/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:25:00 by rnishimo          #+#    #+#             */
/*   Updated: 2022/02/05 09:46:09 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	_print_char(char c)
{
	if (c == EOT)
		return ;
	ft_putchar_fd(c, 1);
}

static void	_after_receive_signal(t_server *server)
{
	if (g_signal != SIGUSR1 && g_signal != SIGUSR2)
		return ;
	if (g_signal == SIGUSR1)
		server->c = 2 * server->c + 1;
	if (g_signal == SIGUSR2)
		server->c = 2 * server->c;
	server->size++;
	if (server->size == 8)
	{
		_print_char(server->c);
		ft_memset(server, 0, sizeof(t_server));
	}
}

static void	_receive_signal(int signal)
{
	g_signal = signal;
}

static void	_print_pid(void)
{
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
}

int	main(void)
{
	t_server	server;

	_print_pid();
	ft_memset(&server, 0, sizeof(t_server));
	signal(SIGUSR1, _receive_signal);
	signal(SIGUSR2, _receive_signal);
	while (true)
	{
		pause();
		_after_receive_signal(&server);
	}
}
