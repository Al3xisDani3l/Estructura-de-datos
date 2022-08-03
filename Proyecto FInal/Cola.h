#pragma once
#include <iostream>
#include <stdio.h>
#include "myPila.h"

using namespace std;
//Se reutiliza el codigo de la pila para implementaciones en la cola


#pragma region Mi Implementacion de la cola

template<typename T> struct NodoC
{
	T Dato;
	struct NodoC<T>* Siguiente = NULL;
};

template<typename T> class Cola
{

public:


	void Encolar(T in) {

		NodoC<T>* _aux = new NodoC<T>;
		_aux->Dato = in;
		if (IsEmpty())
		{
			_primero = _aux;
			_Ultimo = _primero;
			CantidadEle++;
		}
		else
		{


			_Ultimo->Siguiente = _aux;
			_Ultimo = _Ultimo->Siguiente;

			CantidadEle++;
		}

	}

	T Desencolar() {

		NodoC<T>* _Aux;

		T _Dato;

		if (!IsEmpty())
		{
			_Dato = _primero->Dato;
			_Aux = _primero;
			_primero = _primero->Siguiente;
			delete _Aux;
			CantidadEle--;
			return _Dato;

		}




	}

	T Primero() {
		return _primero->Dato;

	}
	T Ultimo() {
		return _Ultimo->Dato;
	}

	void Primero(T in) {
		_primero->Dato = in;
	}

	void Ultimo(T in) {
		_Ultimo->Dato = in;
	}

	void Clear() {
		while (!IsEmpty())
		{
			Desencolar();
		}
	}

	bool IsEmpty() const {
		return _primero == NULL;
	}

	int Length() {
		return CantidadEle;
	}

	void MostrarTodo(ostream* salida) {

		NodoC<T>* _aux = _primero;

		while (_aux != NULL)
		{
			*salida << "\n" << _aux->Dato << "\n";
			_aux = _aux->Siguiente;
		}


	}

	Cola<T>* Invertir() {

		NodoC<T>* _aux = _primero;
		Cola<T>* _CAux = new Cola<T>();
		Pila<T>* _PAux = new Pila<T>();

		//Rellenamos la pila
		while (_aux != NULL)
		{
			_PAux->Push(_aux->Dato);
			_aux = _aux->Siguiente;
		}

		//rellenamos la cola invertida
		while (_PAux->Lenght() != 0)
		{
			_CAux->Encolar(_PAux->Pop());
		}

		return _CAux;

	}

	/*Cola();*/
	~Cola() {

		Clear();
	}

private:

	NodoC<T>* _filaEntera;
	NodoC<T>* _primero;
	NodoC<T>* _Ultimo;
	unsigned int CantidadEle;

};




#pragma endregion


void ColaInit(int* nums, int size) {
	int opciones = 0;
	int _in;
	int _out;
	//instanciamos la cola;
	Cola<int>* _cola = new Cola<int>();

	for (size_t i = 0; i < size; i++)
	{
		_cola->Encolar(nums[i]);
	}

	do {

		system("cls");

		cout << endl << "<<< Q U E U E >>>" << endl;
		cout << "1 Encolar" << endl << "2 Desencolar" << endl << "3 Mostrar cola" << endl <<
			"4 Mostrar primero y ultimo" << endl <<
			"5 Modificar primero" << endl <<
			"6 Modificar ultimo" << endl <<
			"7 Total de elementos" << endl <<
			"8 Cola espejo" << endl <<
			"0 Salir" << endl;
		cout << "Ingresa opcion: ";
		cin >> opciones;

		switch (opciones)
		{
		case 1://Push

			cout << "Introduce un numero: " << endl;
			cin >> _in;
			_cola->Encolar(_in);

			break;
		case 2:

			_out = _cola->Desencolar();

			cout << "Desencole: " << _out << endl;

			system("pause");

			break;
		case 3:
			_cola->MostrarTodo(&cout);
			system("pause");
			break;
		case 4:
			cout << endl << "Primero: " << _cola->Primero() << endl;
			cout << "Ultimo: " << _cola->Ultimo() << endl;
			system("pause");
			break;
		case 5:
			int prim;

			cout << endl << "Primero actual: " << _cola->Primero() << " cambiar por: ";
			cin >> prim;
			_cola->Primero(prim);

			system("pause");
			break;
		case 6:

			int ult;
			cout << endl << "Ultimo actual: " << _cola->Ultimo() << " cambiar por: ";
			cin >> ult;
			_cola->Ultimo(ult);

			system("pause");
			break;
		case 7:
			cout << endl << "Cantidad de elementos en la cola: " << _cola->Length() << endl;
			system("pause");
			break;
		case 8:
			_cola->Invertir()->MostrarTodo(&cout);

			system("pause");
			break;
		default:
			cout << "Opcion invalida..." << endl << endl;
			break;
		}
	} while (opciones != 0);

	delete _cola;
	
}