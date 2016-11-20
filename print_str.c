/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 10:43:04 by fanno             #+#    #+#             */
/*   Updated: 2016/05/23 10:43:13 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	do_norm(t_form *info, t_data *d, int *newret)
{
	if (info->left == 0)
	{
		while (info->width - info->prec > 0)
		{
			if (info->zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
			*newret += 1;
			info->width--;
		}
		ft_putstr(d->string);
	}
}

static void	do_left(t_form *info, t_data *d, int *newret, int ret)
{
	if (info->left == 1)
	{
		ft_putstr(d->string);
		while (info->width - ret > 0)
		{
			ft_putchar(' ');
			info->width--;
			*newret += 1;
		}
	}
}

int			print_str(t_form *info, t_data *d, int ret)
{
	int newret;

	newret = 0;
	if (info->prec > ret || info->prec == -1)
		info->prec = ret;
	do_norm(info, d, &newret);
	do_left(info, d, &newret, ret);
	return (ret + newret);
}
