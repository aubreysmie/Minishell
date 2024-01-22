/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 07:24:05 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/22 08:42:40 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "session.h"
#include "utils.h"
#include "errors.h"

static bool	is_sup_to(char *num1, char *num2)
{
	if (ft_strlen(num1) > ft_strlen(num2))
		return (true);
	if (ft_strlen(num1) < ft_strlen(num2))
		return (false);
	return (ft_strcmp(num1, num2) > 0);
}

static void	exit_without_arg(int len, char **argv)
{
	if (len == 1)
		exit(0);
	if (!ft_strisnum(argv[1]) || is_sup_to(argv[1], "9223372036854775807"))
		disp_cmd_error(SHOULD_PRINT_SHELL,
			argv[0], argv[1], "numeric argument required");
	else
		disp_cmd_error(SHOULD_PRINT_SHELL,
			argv[0], NULL, "too many arguments");
	exit(2);
}

void	ft_exit(char **argv, t_session *session)
{
	int	len;

	len = ft_stralen(argv);
	destroy_session(session);
	if (len != 2)
		exit_without_arg(len, argv);
	if (!ft_strisnum(argv[1]) || is_sup_to(argv[1], "9223372036854775807"))
	{
		disp_cmd_error(SHOULD_PRINT_SHELL,
			argv[0], argv[1], "numeric argument required");
		exit(2);
	}
	if (is_sup_to(argv[1], "255"))
		exit(255);
	exit(ft_atoui(argv[1]));
}
