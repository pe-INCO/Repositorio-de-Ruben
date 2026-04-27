#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {

	int i, j;
	char nombre[50];
	printf ("Ingrese una frase de maximo 50 caracteres\n->");

	if (fgets(nombre, sizeof(nombre), stdin) != NULL) {
		printf("la longitud es %zu\n", strlen(nombre)-1);
		
	for (i=0; nombre[i];i++){
	nombre[i]=tolower(nombre[i]);
	}
	printf("%s", nombre);
	
	for (i=0; nombre[i];i++){
	nombre[i]=toupper(nombre[i]);
	}
	printf("%s", nombre);
	}

return 0;
}