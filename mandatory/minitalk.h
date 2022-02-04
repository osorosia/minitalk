/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:56:47 by rnishimo          #+#    #+#             */
/*   Updated: 2022/02/04 17:08:39 by rnishimo         ###   ########.fr       */
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

typedef struct s_server
{
	int		size;
	char	c;
} t_server;

// gloval variable
int g_signal;

// utils.c


#endif