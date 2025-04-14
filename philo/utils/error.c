/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselbayraktaroglu <tanselbayraktarogl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:55:50 by tanselbayra       #+#    #+#             */
/*   Updated: 2025/04/08 20:55:56 by tanselbayra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int error_msg(const char *msg)
{
    while (*msg)
    {
        write(2, msg, 1); // Write to stderr (file descriptor 2)
        msg++;
    }
    write(2, "\n", 1); // Add a newline
    return (1);
}