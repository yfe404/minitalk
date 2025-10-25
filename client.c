/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfeunteu <yfeunteu@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:05:32 by yfeunteu          #+#    #+#             */
/*   Updated: 2025/10/25 19:26:08 by yfeunteu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft.h"

void	signal_handler(int sig)
{
	(void)sig;
	ft_putstr_fd("Received ACK from server.\n", 1);
}

void	encode_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << (7 - i)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(1000);
	}
}

int	main(int argc, char *argv[])
{
	int	server_pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client <pid> <msg>\n", 2);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	signal(SIGUSR1, &signal_handler);
	signal(SIGUSR2, &signal_handler);
	if (server_pid <= 0)
	{
		ft_putstr_fd("Invalid PID\n", 2);
		return (1);
	}
	while (argv[2][i] != '\0')
		encode_char(server_pid, argv[2][i++]);
	return (0);
}
