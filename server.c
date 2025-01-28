/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:15:37 by marvin            #+#    #+#             */
/*   Updated: 2025/01/28 12:15:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_confirm(pid_t *client_pid)
{
	kill(*client_pid, SIGUSR1);
	*client_pid = 0;
}

char	*ft_strjoin_letter(char *str, char c)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = (char *)malloc(ft_strlen(str) + 2);
	if (!new_str)
		return (NULL);
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j++] = c;
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

void	ft_receive(int signal, siginfo_t *info, void *not)
{
	static char		c = 0;
	static char		*str;
	static int		bit_count = 0;
	static pid_t	client_pid = 0;

	if (!client_pid && (void *)not)
		client_pid = info->si_pid;
	if (!str)
		str = ft_strdup("");
	if (signal == SIGUSR2)
		c |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		str = ft_strjoin_letter(str, c);
		if (c == '\0')
		{
			ft_printf("%s\n", str);
			free(str);
			str = NULL;
			ft_confirm(&client_pid);
		}
		bit_count = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	signal;

	printf("Server PID: %d\n", getpid());
	signal.sa_sigaction = ft_receive;
	signal.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
		usleep(1000);
	return (0);
}
