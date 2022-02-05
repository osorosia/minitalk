/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:56:47 by rnishimo          #+#    #+#             */
/*   Updated: 2022/02/05 09:27:24 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include "../libft/libft.h"

# ifndef DEBUG
#  define DEBUG 0
# endif

# define EOT 4
# define BYTE 8
# define USLEEP_TIME 300

typedef struct s_server
{
	int		size;
	char	c;
}	t_server;

// gloval variable
int	g_signal;

#endif
