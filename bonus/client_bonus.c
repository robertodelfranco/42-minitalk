/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:15:31 by marvin            #+#    #+#             */
/*   Updated: 2025/01/29 12:44:31 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static bool	g_message_received = false;

void	handle_sig(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("Message received\n");
	g_message_received = true;
}

void	send_message(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i > -1)
	{
		g_message_received = false;
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_message_received)
			;
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
		message = argv[2];
		signal(SIGUSR1, handle_sig);
		signal(SIGUSR2, handle_sig);
		while (*message)
		{
			send_message(pid, *message);
			message++;
		}
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
