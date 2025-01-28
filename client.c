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
	int		i;
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
		i = 0;
		while (message[i])
			send_message(pid, message[i++]);
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
