#include <stdio.h>

#define MAX
int main()
{
	int i, j;
	int cal[MAX][50];
	char a[MAX];
	int opcion;

	do {
		printf("Que quiere realizar\n");
		printf("1.- Insertar\n2.- Matriz\n3.- promedio de estudiante\n4.- promedio de materias\n5.- Materia mas alta\n6.- Salir\n\n->");
		scanf ("%d", &opcion);

		switch(opcion) {

		case 1:
			printf("Ingrese el nombre de los alumnos\n->");
            for (i=0; i<MAX; i++) {
                scanf("%s", a[i]);
            }
			
            for (i=0; i<3; i++){
			printf("\nEl alumno %s se guardo con exito\n", a[i]);
            }
            
			printf("\nIngrese las calificaciones del alumno\n");
			for (i=0; i<3; i++){
			    printf("\n%s: ", a[i]);
			    for (j=0;j<4;j++){
			        scanf ("%d", &cal[i][j]);
			    }
			}
			
			break;

		}
	} while (opcion != 6);

	return 0;
}