/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:23:22 by rnishimo          #+#    #+#             */
/*   Updated: 2022/02/05 09:17:09 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	_send_char(int pid, unsigned char c)
{
	int	i;
	int	signal;

	i = BYTE;
	while (i > 0)
	{
		usleep(200);
		signal = SIGUSR2;
		if ((c >> (i - 1)) & 1)
			signal = SIGUSR1;
		kill(pid, signal);
		i--;
	}
}

void	_usage(void)
{
	ft_putstr_fd("usage: ./client [pid] [message]\n", 2);
	exit(1);
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	char	*str;

	if (argc != 3)
		_usage();
	pid = ft_atoi(argv[1]);
	str = argv[2];
	i = 0;
	while (str[i])
	{
		_send_char(pid, str[i]);
		i++;
	}
	_send_char(pid, EOT);
}
