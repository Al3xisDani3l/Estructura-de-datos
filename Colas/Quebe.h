#pragma once

#include <stdio.h>

struct nodo
{
	int numero;
	nodo* siguiente;
};

typedef struct nodo* Q;//Tipo de dato Q = struct nodo *

class Quebe
{
	Q primero, ultimo = NULL;//punteros

public:
	void push(Q& fila);

	void mostrar(Q fila);

	void pop(Q& fila);

	void modificar(Q fila);

	void PyU(Q fila);

};

