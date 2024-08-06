/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inventoryutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi_streber <luigi_streber@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:14:59 by luigi_streb       #+#    #+#             */
/*   Updated: 2024/08/06 18:37:03 by luigi_streb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inventory.h"

void	add_product(const char *filename)
{
	FILE		*file;
	t_product	p;

	file = fopen(filename, "a");
	if (!file)
	{
		perror("Error al abrir el archivo");
		return ;
	}
	printf("Ingrese el ID del producto: ");
	scanf("%d", &p.id);
	printf("Ingrese el nombre del producto: ");
	scanf("%s", p.name);
	printf("Ingrese la cantidad: ");
	scanf("%d", &p.quantity);
	printf("Ingrese el precio: ");
	scanf("%f", &p.price);

	fwrite(&p, sizeof(t_product), 1, file);
	fclose(file);

	printf("Producto añadido exitosamente.\n");
}

void	update_product(const char *filename)
{
	FILE		*file;
	int			id;
	t_product	p;

	file = fopen(filename, "r+b");
	if (!file)
	{
		perror("Error al abrir el archivo");
		return ;
	}
	printf("Ingrese el ID del producto a actualizar: ");
	scanf("%d", &id);
	while (fread(&p, sizeof(t_product), 1, file))
	{
		if (p.id == id)
		{
			printf("Ingrese el nuevo nombre del producto: ");
			scanf("%s", p.name);
			printf("Ingrese la nueva cantidad: ");
			scanf("%d", &p.quantity);
			printf("Ingrese el nuevo precio: ");
			scanf("%f", &p.price);
			fseek(file, sizeof(t_product), SEEK_CUR);
			fwrite(&p, sizeof(t_product), 1, file);
			fclose(file);
			printf("Producto actualizado exitosamente.\n");
			return ;
		}
	}
	fclose(file);
	printf("Producto con ID %d no encontrado.\n", id);
}

void	delete_product(const char *filename)
{
	FILE		*file;
	FILE		*temp_file;
	int			id;
	t_product	p;
	int			found;

	found = 0;
	temp_file = fopen("temp.dat", "w+b");
	file = fopen(filename, "r+b");
	if (!file)
	{
		perror("Error al abrir el archivo");
		return ;
	}
	if (!temp_file)
	{
		perror("Error al abrir el archivo temporal");
		fclose(file);
		return ;
	}
	printf("Ingrese el ID del producto a eliminar: ");
	scanf("%d", &id);
	while (fread(&p, sizeof(t_product), 1, file))
	{
		if (p.id == id)
		{
			found = 1;
		}
		else
		{
			fwrite(&p, sizeof(t_product), 1, temp_file);
		}
	}
	fclose(file);
	fclose(temp_file);
	remove(filename);
	rename("temp.dat", filename);
	if (found)
	{
		printf("Producto eliminado exitosamente.\n");
	}
	else
	{
		printf("Producto con ID %d no encontrado.\n", id);
	}
}

void	list_products(const char *filename)
{
	FILE		*file;
	t_product	p;

	file = fopen(filename, "rb");
	if (!file)
	{
		perror("Error al abrir el archivo");
		return ;
	}
	printf("Lista de productos:\n");
	while (fread(&p, sizeof(t_product), 1, file))
	{
		printf("ID: %d\n", p.id);
		printf("Nombre: %s\n", p.name);
		printf("Cantidad: %d\n", p.quantity);
		printf("Precio: %.2f\n", p.price);
		printf("------------------------\n");
	}
	fclose(file);
}
