/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:15:31 by marvin            #+#    #+#             */
/*   Updated: 2025/01/28 12:15:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sig(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Message received\n");
}

void	send_message(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i > -1)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
		i--;
	}
}

int	main(int argc, char **argv)
{
	char	*message;
	pid_t	pid;

	if (argc == 3)
	{
		pid = atoi(argv[1]);
		if (!pid)
			return (ft_printf("Invalid PID\n"), 0);
		message = argv[2];
		if (message[0] == 0)
			return (ft_printf("Empty message\n"), 0);
		signal(SIGUSR1, handle_sig);
		while (*message)
			send_message(pid, *message++);
		send_message(pid, '\0');
	}
	else
	{
		if (argc < 3)
			ft_printf("Not enough arguments\n");
		else
			ft_printf("Too many arguments\n");
	}
	return (0);
}
