#include <stdio.h>
#include <stdlib.h>

struct a {
	char nom[50];
	int cal[4];
};

int main() {
	struct a alumnos[3];
	int opcion, i, j, maxv=0;
	float suma, suma2, resultado;
	do {
		system ("clear");
		printf("Ingrese el dato que desea realizar\n\n");
		printf("1.- Ingresar\n2.- Mostrar datos\n3.- Calcular promedio\n4.- Calcular materia\n5.- Nota mas alta\n6.- Salir\n->");

		scanf("%d", &opcion);

		switch(opcion) {

		case 1:
			system ("clear");
			printf("\nIngrese el nombre de los alumnos\n");

			for (i=0; i<3; i++) {
				printf("\n->");
				scanf(" %s", alumnos[i].nom);

				printf("Ingrese las calificaciones de %s\n", alumnos[i].nom);

				for(j=0; j<4; j++) {
					printf("Materia %d\n->", j+1);
					scanf("%d", &alumnos[i].cal[j]);
				}
			}
			getchar();
			getchar();

			break;

		case 2:
			system ("clear");
			printf("\nAlumnos registrados\n");

			for (i=0; i<3; i++) {
				printf("%s | ", alumnos[i].nom);

				for (j=0; j<4; j++) {
					printf("%d |", alumnos[i].cal[j]);
				}
				printf("\n");
			}
			getchar();
			getchar();

			break;

		case 3:
			system ("clear");
			for (i=0; i<3; i++) {
				printf("\nEl promedio de %s es: ", alumnos[i].nom);
				suma=alumnos[i].cal[0]+alumnos[i].cal[1]+alumnos[i].cal[2]+alumnos[i].cal[3];
				resultado=suma/4;

				printf("%.2f\n", resultado);
			}
			getchar();
			getchar();
			break;

		case 4:
			system ("clear");
			for(j=0; j<4; j++) {
				for(i=0; i<3; i++) {
					suma2=alumnos[0].cal[j]+alumnos[1].cal[j]+alumnos[2].cal[j];
				}
				printf("El promedio de la materia %d es: %.2f\n", j+1, suma2/3);
			}
			getchar();
			getchar();
			break;

		case 5:
			system ("clear");
			for(j=0; j<4; j++) {
				for(i=0; i<3; i++) {
					if (alumnos[i].cal[j]>maxv) {
						maxv+=alumnos[i].cal[j];
					}
				}
			}

			printf("\nLa calificacion mas alta es de %d", maxv);
			getchar();
			getchar();
			break;

		case 6:
			system ("clear");
			printf("Que tenga buen dia");
			break;
		}

	}
	while (opcion != 6);

	return 0;
}