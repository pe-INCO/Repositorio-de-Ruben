#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
	int opcion, n=0, valor=1;
	int i=0, final;
	char linea[100];
	char buffer[20];
	int bus, enc = 0;
	int ch;

	FILE *archivo;

	// Abrir archivo en modo escritura ("w" crea o sobrescribe)

	printf ("Que desea realizar?\n");

	printf("1.- Editar archivo\n");
	printf("2.- Leer archivo\n");
	printf("3.- Nueva linea de texto\n");
	printf("4.- Leer ID\n");
	scanf ("%d", &opcion);

	switch (opcion) {

	case 1:
		archivo = fopen("calificaciones.txt", "w");

		if (archivo == NULL) {
			printf("Error al abrir el archivo\n");
			return 1;
		}

		// Escribir en el archivo
		fprintf(archivo, "Lista de calificaciones\n");
		fprintf(archivo, "1.- Juan: %d\n", 90);
		fprintf(archivo, "2.- Adrian: %d\n", 80);
		fprintf(archivo, "3.- Monica: %d\n", 67);
		fprintf(archivo, "4.- Luis: %d\n", 87);
		fprintf(archivo, "5.- Cinthia: %d\n", 72);

		// Cerrar el archivo
		fclose(archivo);

		printf("Archivo escrito exitosamente\n");
		break;

	case 2:

		// Abrir archivo en modo lectura ("r")
		archivo = fopen("calificaciones.txt", "r");

		if (archivo == NULL) {
			printf("ERROR: No se pudo abrir el archivo\n");
			return 1;
		}

		// Leer y mostrar línea por línea
		printf("Contenido del archivo:\n");
		while (fgets(linea, sizeof(linea), archivo) != NULL) {
			printf("%s", linea);
		}

		// Cerrar el archivo
		fclose(archivo);
		break;


	case 3:

		//Abre el documento desde la ultima linea de texto
		archivo = fopen("calificaciones.txt", "a");

		if (archivo == NULL) {
			printf("ERROR: el archivo no existe");

			return 1;
		}

		fprintf(archivo, "Nuevo log de alumnos, esta opcion se a usado %d vez(veces)\n", n);
		n++;

		fclose(archivo);
		break;

	//leer ID
	case 4:
		int idBusca;
		int encontrado = 0;
		printf("Ingrese el id que quere buscar\n->");
		scanf("%d", &idBusca);

		archivo = fopen("calificaciones.txt", "r");

		if (archivo == NULL) {
			printf("ERROR: el archivo no existe\n");
			return 1;
		}

		while ((ch = fgetc(archivo)) != EOF) {

			if (isdigit(ch)) {
				i = 0;
				buffer[i++] = (char)ch;

				while ((ch = fgetc(archivo)) != EOF && isdigit(ch)) {
					if (i < sizeof(buffer) - 1) {
						buffer[i++] = (char)ch;
					}
				}

				buffer[i] = '\0';
				final = atoi(buffer);

				if (final == idBusca) {
					printf("se encontro el id y su usario\n", final);
					encontrado = 1;

					while ((ch = fgetc(archivo)) != EOF && ch != '\n') {
						putchar(ch);
					}
					printf("\n");
					break;
				}
			}
		}

		if (!encontrado) {
			printf("ERROR: el id %d no fue encontrado\n", idBusca);
		}

		fclose(archivo);
		break;
		
	case 5;

	}

	return 0;
}