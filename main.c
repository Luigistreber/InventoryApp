/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi_streber <luigi_streber@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:38:09 by luigi_streb       #+#    #+#             */
/*   Updated: 2024/08/06 18:51:31 by luigi_streb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inventory.h"

int	main()
{
	const char	*filename;
	int			choice;
	char		buffer[256];
	int			result;

	filename = "inventory.dat";
	while (1)
	{
		printf("Sistema de Gestión de Inventario\n");
		printf("1. Añadir producto\n");
		printf("2. Actualizar producto\n");
		printf("3. Eliminar producto\n");
		printf("4. Listar productos\n");
		printf("5. Salir\n");
		printf("Ingrese su opción: ");
		if (fgets(buffer, sizeof(buffer), stdin) != NULL)
		{
			result = sscanf(buffer, "%d", &choice);
			if (result != 1)
			{
				printf("Entrada inválida. Intente de nuevo.\n");
				continue ;
			}
		}
		else
		{
			printf("Error al leer la opción.\n");
			continue ;
		}

		switch (choice)
		{
			case 1:
				add_product(filename);
				break ;
			case 2:
				update_product(filename);
                break ;
			case 3:
				delete_product(filename);
				break ;
			case 4:
				list_products(filename);
				break ;
			case 5:
				return (0);
			default:
				printf("Opción inválida. Intente de nuevo.\n");
		}
	}
	return (0);
}
