/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:23:22 by rnishimo          #+#    #+#             */
/*   Updated: 2022/02/05 09:27:19 by rnishimo         ###   ########.fr       */
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
		usleep(USLEEP_TIME);
		signal = SIGUSR2;
		if ((c >> (i - 1)) & 1)
			signal = SIGUSR1;
		kill(pid, signal);
		i--;
	}
}

void	_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

int	_atoi(char *str)
{
	long	i;
	long	num;

	if (str[0] == '\0')
		return (-1);
	num = 0;
	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		num = num * 10 + str[i] - '0';
		if (num > INT_MAX)
			return (-1);
	}
	return (num);
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	char	*str;

	if (argc != 3)
		_error("usage: ./client [pid] [message]\n");
	pid = _atoi(argv[1]);
	if (pid <= 0)
		_error("error: invalid argument\n");
	str = argv[2];
	i = 0;
	while (str[i])
	{
		_send_char(pid, str[i]);
		i++;
	}
	_send_char(pid, EOT);
}
