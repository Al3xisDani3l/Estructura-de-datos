// Grafo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Alexis Daniel Hernandez Gamez - 180263
// Genesis Erisel Arteaga Rangel - 182129

#include <iostream>
#include "Graph.h"
using namespace std;
int main()
{

	Graph<int>* grafo = new Graph<int>();
	int opc = 0, numero, numero1;

	do {
		system("cls");
		cout << "\n G R A F O S " << endl
			<< "1 Insertar nodo" << endl
			<< "2 Insertar arista" << endl
			<< "3 Mostrar grafo" << endl
			<< "4 Eliminar un nodo" << endl
			<< "5 Eliminar una arista" << endl
			<< "6 Mostrar Matriz" << endl
			<< "7 Mostrar arbol" << endl
			<< "0 Salir" << endl
			<< "Ingresa una opcion: ";
		cin >> opc;
		cout << endl << endl;
		switch (opc)
		{
		case 1:
			cout << "\nIngresar el numero: ";
			cin >> numero;
			cout << endl;
			grafo->Add(numero);//insertarNodo(grafo);
			getchar();
			getchar();
			break;
		case 2:
			cout << "\nIngresar el nodo 1: ";
			cin >> numero;
			cout << endl;
			cout << "\nIngresar el nodo 2: ";
			cin >> numero1;
			cout << endl;
			grafo->CreateConexion(numero,numero1);//insertarArista(grafo);
			getchar();
			getchar();
			break;
		case 3:
			cout<<*grafo;//mostrarGrafo(grafo);
			getchar();
			getchar();
			break;

		case 4:
			cout << "\nIngresar el numero: ";
			cin >> numero;
			cout << endl;
			grafo->Delete(numero);//insertarNodo(grafo);
			getchar();
			getchar();
			break;
		case 5:
			cout << "\nIngresar el nodo 1: ";
			cin >> numero;
			cout << endl;
			cout << "\nIngresar el nodo 2: ";
			cin >> numero1;
			cout << endl;
			grafo->DeleteConexion(numero, numero1);//insertarArista(grafo);
			getchar();
			getchar();
			break;
		case 6:
			grafo->matrix();//mostrarGrafo(grafo);
			getchar();
			getchar();
			break;
		case 7:
			grafo->unprint();
			grafo->tree();//mostrarGrafo(grafo);
			getchar();
			getchar();
			break;
		case 0:
			cout << endl << "Saliendo del programa" << endl;
			getchar();
			getchar();
			break;
		default:
			cout << endl << "No existe esa opcion..." << endl;
			break;
		}

	} while (opc != 0);

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
