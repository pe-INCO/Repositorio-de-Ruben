#include <stdio.h>
#include <stdlib.h>

int main() {

	float saldo = 5000, deposito, retiro;
	int opcion;

	do {
		system ("clear");
		printf ("======== BANCO ========\n"); //Opciones del banco
		printf ("1.- Consultar saldo\n");
		printf ("2.- Depositar\n");
		printf ("3.- Retirar\n");
		printf ("4.- Salir\n->");
		scanf ("%d", &opcion);

		while (opcion < 1 || opcion > 4) {
			printf("El valor no es valido\n->"); //consulta que la opcion sea valida
			scanf ("%d", &opcion);
		}

		switch (opcion) {
		case 1: //consulta el saldo
			system ("clear");// limpia la pantalla
			printf ("Su saldo es de %.2f", saldo);
			getchar();
			getchar(); // un getchar limpia buffe y el otro espera a presionar alguna tecla
			break;

		case 2://Pide ingresar un deposito
			system ("clear");
			printf ("Ingrese el saldo que desea depositar\nEl saldo minimo es de 100 y el maximo de 20000\n->");
			scanf("%f", &deposito);

			while (deposito < 100 || deposito > 20000) {
				printf ("El valor es mayor o menor al estimado\nIngrese otro valor que este dentro del rango\n->");
				scanf("%f", &deposito);
			}

			saldo += deposito;

			printf ("Su saldo se a actualizado\n%.2f", saldo);
			getchar();
			getchar();
			break;

		case 3://SIrve para retirar saldo
			system ("clear");
			printf ("ingrese la cantidad que desa retirar\nSu saldo actual es de %.2f\n->", saldo);
			scanf ("%f", &retiro);

			while (retiro > saldo) {
				printf ("No se pudo realizar el retiro debido a que usted esta retirando una cantidad mayor a la establecida\n->"); // comprueba que el retiro no sea mayor al saldo
				scanf ("%f", &retiro);
			}
			while (retiro < 1) {
				printf ("Ingrese un valor que sea mayor a 0\n->"); // comprueba que el saldo no sea inferrior o igual a 0
				scanf ("%f", &retiro);
			}

			saldo = saldo - retiro; // Actualiza el saldo al valor retirado

			printf ("Se han retirado %.2f de su cuenta\nSu saldo ahora es de %.2f", retiro, saldo);
			getchar();
			getchar();
			break;

		case 4: // Cierra el programa
			system ("clear");
			printf ("Que tenga buen dia");
			getchar();
			getchar();
			break;
		}
	} while (opcion != 4); // vuelve a pedir una opcion siempre y cuando la opcion no sea 4 (la de salir)

	return 0;
}