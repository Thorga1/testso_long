/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:50:08 by tordner           #+#    #+#             */
/*   Updated: 2024/12/13 17:02:44 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void    free_data(t_data *data)
{
    free(data);
}

int main(int ac, char **av)
{
    t_data  *data;

    if (errors(ac, av))
        return (1);
    if (data_setup(data, av[1]))
    {
        free_data(data);
        return (1);
    }
    free_data(data);
    return (0);
}