/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:25:00 by rnishimo          #+#    #+#             */
/*   Updated: 2022/02/04 16:55:50 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	after_receive_signal(t_server *server)
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
		ft_putchar_fd(server->c, 1);
		ft_memset(server, 0, sizeof(t_server));
	}
}

void	_receive_signal(int signal)
{
	// ft_putnbr_fd(signal, 1);
	// ft_putstr_fd("\n", 1);
	g_signal = signal;
}

int	main(void)
{
	t_server	server;

	ft_memset(&server, 0, sizeof(t_server));
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, _receive_signal);
	signal(SIGUSR2, _receive_signal);
	while (true)
	{
		pause();
		after_receive_signal(&server);
	}
}
