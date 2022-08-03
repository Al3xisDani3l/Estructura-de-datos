// Pila_Modificacion.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

/*Estructura nodo*/
struct nodo {//Se crea una estructura con el nombre nodo con dos componentes
	int numero;//Almacena un dato numérico en el nodo
	struct nodo* sig;//Almacena la dirección de memoria del nodo continuo
};

typedef nodo* P;//Define un tipo de dato estructura nodo

void mostrar_pila(P p)//Al no haber manipulación directa de la pila, no es necesario hacer referencia
{
	P aux;//Creo un auxiliar es de tipo nodo *P
	aux = p;//se iguala la ultima dirección que apunta la pila al auxiliar

	while (aux != NULL)//Mientras el puntero auxiliar no apunte a nulo
	{
		cout << endl << aux->numero << endl; //Se imprime el numero que hay en cada nodo
		aux = aux->sig;
	}
}

void push(P& p, int n)
{
	P aux;
	aux = new nodo;//Creamos y apuntamos a un nuevo nodo
	aux->numero = n;//Se asigna el número ingresado de teclado
	aux->sig = p; //el siguiente elemento se apunta al anterior creado
	p = aux;//Asignación del nodo creado a la pila original
}

int pop(P& p)//Habrá manipulación a la pila, por lo que tiene que mandar la referencia
{
	int num;
	P aux;

	aux = p;//Se le asigna dirección de la pila a un puntero auxiliar
	num = aux->numero; //El numero dentro del nodo se almacena a una variable entera

	p = aux->sig; //Se la dirección del ultimo nodo se cambia al nodo anterior
	//desvinculando el nodo a eliminar
	delete(aux); //Se elimina el ultimo nodo creado

	return num; //Se regresa el numero del nodo eliminado para su impresión
}

void destruir_pila(P& p)
{
	P aux;
	while (p != NULL)
	{
		aux = p;
		p = aux->sig;
		delete(aux);
	}

	cout << endl << "Pila borrada..." << endl;
}

int mostrar_cantidad(P p)
{
	P aux;
	int z = 0;
	

	aux = p;
	while (aux !=NULL)
	{
		z++; 
		
		aux = aux->sig;
	}
	return z;

}

int tope_pila(P p)
{
	int num;
	
	num = p->numero;
	return num;

}

int ultimo_pila(P p)
{

	P aux;
	int z = 0;
	P penultimo=p;


	aux = p;
	while (aux != NULL)
	{
		penultimo = aux;

		aux = aux->sig;
	}
	return penultimo->numero;

}
int main()
{
	P pila = NULL;//Iniciando la pila en Nulo
	int dato = 0, opc = 0, x;

	do {
		cout << "Menu PILAS" << endl << endl <<
			"1 Apilar (Push)" << endl <<
			"2 Desapilar (Pop)" << endl <<
			"3 Mostrar pila" << endl <<
			"4 Borrar pila" << endl <<
			"5 Mostrar la cantidad de nodos"<<endl<<
			"6 Tope de la pila"<<endl<<
			"7 Ultimo numero de la pila"<<endl<<
			"8 Salir" << endl;
		cout << endl << "Ingrese una opción: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			cout << endl << "Ingresa número: ";
			cin >> dato;
			push(pila, dato);
			system("pause");
			break;
		case 2:
			x = pop(pila);
			cout << endl << "Se eliminó el nodo con el número" << x;
			system("pause");
			break;
		case 3:
			if (pila != NULL)
				mostrar_pila(pila);
			else
				cout << endl << "Pila vacia..." << endl;
			system("pause");
			break;
		case 4:
			destruir_pila(pila);
			system("pause");
			break;
		case 5:
			
			cout << mostrar_cantidad(pila) << endl;
			system("pause");
			break;
		case 6:
			cout<<tope_pila(pila)<<endl;
			system("pause");
			break;
		case 7:
			cout<<ultimo_pila(pila)<<endl;
			system("pause");
			break;
		default:
			cout << endl << "Opción no existe...";
			break;
		}

	} while (opc != 7);

	return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
