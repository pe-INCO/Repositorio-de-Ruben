#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {

	int i, j;
	char nombre[50];
	char a[4], b[4]; //define como tal la longitud de los 3 primeros caracteres mas el espacio nulo
	int longi; //la longitud para poder detectar los ultimos 3 caracteres
	printf ("Ingrese una frase de maximo 50 caracteres\n->");

	if (fgets(nombre, sizeof(nombre), stdin) != NULL) {
		printf("la longitud es %zu\n", strlen(nombre)-1);

        longi = strlen(nombre); //longitud toma el tamaño del nombre puesto en forma de cadena (letra por letra)
        		
        strncpy(a, nombre, 3); //toma y lee los primeros 3 digitos
        a[3] = '\0';

        printf("los primeros 3 caracteres son %s\n", a);
        
		strcpy(b, &nombre [longi - 4]); //toma y lee los ultimos 3 digitos, por eso la longitud

		printf("los ultimos 3 son %s", b);
		
		
		for (i=0; nombre[i]; i++) {
			nombre[i]=tolower(nombre[i]); //hace que todas las letras cambien a minusculas, nombre [i] indica que la cadena sera del tamaño del nombre
		}

		printf("%s", nombre);

		for (i=0; nombre[i]; i++) {
			nombre[i]=toupper(nombre[i]); //lo mismo que tolower pero ahora las convierte en mayusculas
		}
		printf("%s", nombre);

	}

	for (i=0; nombre[i] != '\0'; i++) {
		if (nombre[i] == 'a' || nombre[i] == 'A') { //detecta si hay a o A en el arreglo y si las hay las cambia a mayusculas
			nombre[i] = '@';
			
		}
	}
	
	printf ("%s", nombre);

	return 0;
}