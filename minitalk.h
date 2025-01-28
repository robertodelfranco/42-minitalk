/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:15:35 by marvin            #+#    #+#             */
/*   Updated: 2025/01/28 12:15:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./current_lib/Includes/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <signal.h>

// Server
void	ft_confirm(pid_t *client_pid);
char	*ft_strjoin_letter(char *str, char c);
void	ft_receive(int signal, siginfo_t *info, void *not);

// Client
void	send_message(pid_t pid, char c);
void	handle_sig(int signal);

#endif /* MINITALK_H */