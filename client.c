#include <signal.h>

#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "libft.h"


void	signal_handler(int sig)
{
	ft_putstr_fd("Received ACK from server.\n", 1);
}


int encode_char(int pid, char c)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << (7 - i)))
			kill(pid, SIGUSR1); // bit 1
		else
			kill(pid, SIGUSR2); // bit 0
		i++;
		usleep(1000);
	}
}

void ft_perror(const char *msg)
{
	write(2, msg, ft_strlen(msg));
}

int main(int argc, char *argv[])
{
	int server_pid;
	int i = 0;

	if (argc != 3) {
		ft_putstr_fd("Usage: ./client <pid> <msg>\n", 2);
		return 1;
	}
	server_pid = atoi(argv[1]);
	signal(SIGUSR1, &signal_handler);
	signal(SIGUSR2, &signal_handler);
	if (server_pid <= 0) {
		ft_putstr_fd("Invalid PID\n", 2);
		return 1;
	}
	while (argv[2][i] != '\0')
	{
		encode_char(server_pid, argv[2][i++]);
	}

	return 0;
}
