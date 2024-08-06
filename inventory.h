/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inventory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi_streber <luigi_streber@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:09:33 by luigi_streb       #+#    #+#             */
/*   Updated: 2024/08/06 18:20:09 by luigi_streb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INVENTORY_H
# define INVENTORY_H
# define MAX_NAME_LENGTH 50
# define MAX_FILE_NAME_LENGTH 100
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <unistd.h>

typedef struct s_product
{
	int		id;
	char	name[MAX_NAME_LENGTH];
	int		quantity;
	float	price;
}	t_product;

void	add_product(const char *filename);
void	update_product(const char *filename);
void	delete_product(const char *filename);
void	list_products(const char *filename);

#endif
