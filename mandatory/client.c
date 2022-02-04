/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:23:22 by rnishimo          #+#    #+#             */
/*   Updated: 2022/02/04 17:15:25 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	_send_char(int pid, unsigned char c)
{
	int i = 7;
	if (DEBUG) {
		ft_putchar_fd(c, 2);
		ft_putstr_fd(": ", 2);
	}
	while (i >= 0)
	{
		usleep(200);
		if (DEBUG)
			ft_putnbr_fd(c >> i & 1, 2);
		int signal = SIGUSR2;
		if (c >> i & 1)
			signal = SIGUSR1;
		kill(pid, signal);
		i--;
	}
	if (DEBUG)
		ft_putstr_fd("\n", 2);
}

void	_usage()
{
	ft_putstr_fd("usage: ./client [pid] [message]\n", 2);
	exit(1);
}

void debug(int pid, char *str)
{
	ft_putstr_fd("pid: ", 2);
	ft_putnbr_fd(pid, 2);
	ft_putstr_fd("\n", 2);
	
	ft_putstr_fd("str: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		_usage();
	
	int pid = ft_atoi(argv[1]);
	char *str = argv[2];
	int i = 0;
	debug(pid, str);
	while (str[i])
	{
		_send_char(pid, str[i]);
		i++;
	}
}
