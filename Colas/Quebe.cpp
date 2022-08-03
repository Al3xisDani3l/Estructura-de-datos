#include "Quebe.h"

void Quebe::push(Q& fila) {
	int dato = 0;
	fila = new nodo;//Se estructura el nodo (dato y direccion)

	cout << "Ingresa el dato:";
	cin >> dato;

	fila->numero = dato;
	fila->siguiente = NULL;

	if (primero == NULL)
		ultimo = primero = fila;
	else
	{
		ultimo->siguiente = fila;
		ultimo = fila;
	}
}
