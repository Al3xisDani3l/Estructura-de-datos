// Guia pila y cola.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
using namespace std;
#pragma region pila
//*Estructura nodo* /
struct Nodo {//Se crea una estructura con el nombre nodo con dos componentes
	int numero;//Almacena un dato numérico en el nodo
	struct Nodo *siguiente = NULL;//Almacena la dirección de memoria del nodo continuo
};




typedef Nodo*  nodo;//Define un tipo de dato estructura nodo

void mostrar_pila(nodo p)//Al no haber manipulación directa de la pila, no es necesario hacer referencia
{
	nodo aux;//Creo un auxiliar es de tipo nodo *P
	aux = p;//se iguala la ultima dirección que apunta la pila al auxiliar

	while (aux != NULL)//Mientras el puntero auxiliar no apunte a nulo
	{
		cout << endl << aux->numero << endl; //Se imprime el numero que hay en cada nodo
		aux = aux->siguiente;
	}
}

void Ppush(nodo& p, int n)
{
	nodo aux;
	aux = new Nodo;//Creamos y apuntamos a un nuevo nodo
	aux->numero = n;//Se asigna el número ingresado de teclado
	aux->siguiente = p; //el siguiente elemento se apunta al anterior creado
	p = aux;//Asignación del nodo creado a la pila original
	
}


int Ppop(nodo &p)//Habrá manipulación a la pila, por lo que tiene que mandar la referencia
{
	int num;
	nodo aux;

	aux = p;//Se le asigna dirección de la pila a un puntero auxiliar
	num = aux->numero; //El numero dentro del nodo se almacena a una variable entera

	p = aux->siguiente; //Se la dirección del ultimo nodo se cambia al nodo anterior
	//desvinculando el nodo a eliminar
	delete(aux); //Se elimina el ultimo nodo creado
	
	return num; //Se regresa el numero del nodo eliminado para su impresión
	
}



void mostrar_contenido_Pila(nodo p)
{
	nodo aux = p;
	int z = 0;
	int n;
	if (aux == NULL)
	{
		cout << "cola vacia";
	}
	else
	{
		aux = p;
		while (aux != NULL)
		{
			z++;
			cout << " " << aux->numero<< " ";
			aux = aux->siguiente;
			
		}
	}




}
int PLength(nodo p) {
	nodo aux = p;
	int con = 0;

	while (aux != NULL)
	{
		con++;
		aux = aux->siguiente;
	}

	return con;

}
void destruir_pila(nodo& p)
{
	nodo aux;
	while (p != NULL)
	{
		aux = p;
		p = aux->siguiente;
		delete(aux);
	}


	cout << endl << "Pila borrada..." << endl;
}
int tope(nodo p)
{
	if (p == NULL) return-1;
	{
		p->numero;
	}

}



#pragma endregion

#pragma region cola



nodo primero, ultimo;//punteros
int _total = 0;

void Cpush(int in)
{
	nodo _aux = new Nodo;
	_aux->numero = in;
	if (primero == NULL)
	{
		primero = _aux;
		ultimo = primero;
		
	}
	else
	{


		ultimo->siguiente = _aux;
		ultimo = ultimo->siguiente;

		
	}
	
	_total++;
}

void Cmostrar()
{
	nodo fila = primero;
	
	if (fila == NULL)
	{
		cout << "La cola esta vacia...";
		return;
	}
	else
	{
	
		while (fila != NULL)
		{
			cout << " " << fila->numero <<" ";
			fila = fila->siguiente;
		}
		cout << endl << endl;
	}
}

int Cpop()
{

	nodo _Aux;

	int _Dato;

	if (primero != NULL)
	{
		_Dato = primero->numero;
		_Aux = primero;
		primero = primero->siguiente;
		delete _Aux;
		_total--;
		return _Dato;

	}

	
}

void CPyU(nodo fila)
{
	if (fila == NULL)
	{
		cout << endl << "El Queue esta vacio..." << endl;
		return;
	}
	else
	{
		fila = primero;
		cout << endl << "El primero nodo es: " << fila->numero << endl;
		cout << endl << "La direccion es: " << fila << endl;
		cout << endl << "El nodo siguiente es: " << fila->siguiente << endl;
		cout << endl << "El numero del nodo siguiente es: " << fila->siguiente->numero;
		fila = ultimo;
		cout << endl << "El ultimo nodo es: " << fila->numero << endl;
	}
}

void Cmodificar()
{
	int p, u;
	cout << endl << "Ingresa el primer dato: ";
	cin >> p;
	cout << endl << "Ingresa el ultimo dato: ";
	cin >> u;

	primero->numero = p;
	ultimo->numero = u;
}

void Cmodificar_tope(nodo* fila)
{
	int n = 0;
	cout << "Ingrese numero a cambiar" << endl;
	cin >> n;
	ultimo->numero = n;
	cout << n << endl;



}

void Cmodificar_primer_elemento(nodo* fila)
{
	int n = 0;
	cout << "Ingrese numero a cambiar" << endl;
	cin >> n;
	primero->numero = n;
	cout << n << endl;

}

void espejo(nodo* fila)
{

}

void Ctotal()
{

	cout << endl << "La cantidad de elementos es: " << _total << endl;

}
#pragma endregion

void VaciarEnCola(nodo& pila) {

	while (pila != NULL)
	{
	 
		Cpush(Ppop(pila));

	}
	

}
void VaciarEnPila(nodo& pila) {

	while (primero != NULL)
	{
		Ppush(pila, Cpop());
	}
}

int main()
{
	nodo pila = NULL;
	
	char continuar;
	int num;

	do
	{
		system("cls");

		cout << "Introduce un numero: " << endl;
		cin >> num;

		Ppush(pila, num);

		cout << endl << "Continuar rellenando la pila: s/n:"<<endl;

		cin >> continuar;


	} while (!(continuar == 'n' || continuar == 'N'));

	
	
	cout << endl << "-- Pila --" << endl;

	cout << endl << "La pila contiene " << PLength(pila)  << " elementos" << endl;

	cout << endl << "Pila -> ";
	mostrar_contenido_Pila(pila);

	cout << endl;
	system("Pause");
	cout << endl;


	//Vaciamos la pila en la cola
	cout << endl << "-- Vaciando en cola --" << endl;

	VaciarEnCola(pila);

	Ctotal();
	cout << endl << "Cola -> ";
	Cmostrar();

	cout << endl;
	system("pause");
	cout << endl;

	cout << endl << "-- Vaciando en pila --" << endl;

	VaciarEnPila(pila);

	cout << endl << "La pila contiene " << PLength(pila) << " elementos" << endl;

	cout << endl << "Pila -> ";
	mostrar_contenido_Pila(pila);

	cout << endl << "----------------------------------------" << endl;
	
	Cmostrar();

	cout << endl;

	system("pause");


}

    


