/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 01:27:12 by rnishimo          #+#    #+#             */
/*   Updated: 2021/11/27 07:20:16 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	handle_signal(int signal)
{
	printf("signal:%d\n", signal);
}

int	main()
{
	printf("PID:%d\n", getpid());
	while(1)
	{
		signal(SIGUSR1, &handle_signal);
		pause();
	}
}
