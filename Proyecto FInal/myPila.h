#pragma once
#include <iostream>

using namespace std;



#pragma region Definicion del tipo pila, -mi implementacion-

template<typename T> struct NodoP
{
	T Dato;
	struct NodoP<T>* Next;

};



//definimos una plantilla generica
template<typename T>
class Pila
{
public:

	Pila();

	~Pila();
	void Push(T in);
	T Pop();
	int Lenght();
	void ShowAll(ostream* salida);
	void Clear();
	T First();
	T Last();

private:
	NodoP<T>* _pila;
	int contador;
};

template<typename T> Pila<T>::Pila()
{
	_pila = NULL;
	contador = 0;
}



template<typename T> Pila<T>::~Pila()
{
	Clear();
}

template<typename T> void Pila<T>::Push(T in) {
	NodoP<T>* aux = new NodoP<T>();
	aux->Dato = in;
	aux->Next = _pila;
	_pila = aux;
	contador++;

}

template<typename T>
T Pila<T>::Pop() {

	NodoP<T>* aux = _pila;

	T dato = aux->Dato;
	_pila = aux->Next;

	delete(aux);

	contador--;
	return dato;


}


template<typename T>
int Pila<T>::Lenght() {
	return contador;
}

template<typename T>
void Pila<T>::ShowAll(ostream* salida) {


	NodoP<T>* aux = _pila;

	while (aux != NULL)
	{
		*salida << "\n" << aux->Dato << "\n";
		aux = aux->Next;
	}

}


template<typename T>
void Pila<T>::Clear() {
	NodoP<T>* aux;
	while (_pila != NULL)
	{
		aux = _pila;
		_pila = aux->Next;
		delete(aux);
		contador--;
	}
}

template<typename T>
T Pila<T>::Last() {
	return _pila->Dato;
}

template<typename T>
T Pila<T>::First() {

	NodoP<T>* ultimo = _pila;

	NodoP<T>* aux = _pila;

	if (contador == 0)
	{
		return NULL;
	}
	while (aux != NULL)
	{
		ultimo = aux;
		aux = aux->Next;
	}

	return ultimo->Dato;



}





#pragma endregion


void PilaInit(int* nums, int size) {
	//Instanciamos la clase que contiene toda la logica de una pila.
	Pila<int>* _Pila = new Pila<int>();

	//P pila = NULL;//Iniciando la pila en Nulo
	int dato = 0, opc = 0, x;

	for (size_t i = 0; i < size; i++)
	{
		_Pila->Push(nums[i]);
	}

	do {
		system("cls");
		cout << "Menu PILAS" << endl << endl <<
			"1 Apilar (Push)" << endl <<
			"2 Desapilar (Pop)" << endl <<
			"3 Mostrar pila" << endl <<
			"4 Borrar pila" << endl <<
			"5 Cantidad de elementos" << endl <<
			"6 Mostrar ultimo elemento" << endl <<
			"7 Mostrar Primer elemento" << endl <<
			"8 Salir" << endl;
		cout << endl << "Ingrese una opcion: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			cout << endl << "Ingresa numero: ";
			cin >> dato;
			_Pila->Push(dato);
			break;
		case 2:
			if (_Pila->Lenght() > 0)
			{
				x = _Pila->Pop();
				cout << endl << "Se elimino el nodo con el numero " << x << endl;
			}
			else
			{
				cout << endl << "Pila vacia..." << endl << endl;
			}
			system("pause");
			break;
		case 3:
			if (_Pila->Lenght() > 0)
				_Pila->ShowAll(&cout);
			else
				cout << endl << "Pila vacia..." << endl << endl;
			system("pause");

			break;
		case 4:
			_Pila->Clear();
			break;
		case 5:
			cout << endl << _Pila->Lenght() << " elementos en la pila" << endl;
			system("pause");
			break;
		case 6:
			if (_Pila->Lenght() > 0)
			{
				cout << endl << "Ultimo elemento agregado a la pila: " << _Pila->Last() << endl;
			}
			else
			{
				cout << endl << "Pila vacia..." << endl << endl;
			}

			system("pause");
			break;
		case 7:
			if (_Pila->Lenght() > 0)
			{
				cout << endl << "Primer elemento agregado a la pila: " << _Pila->First() << endl;
			}
			else
			{
				cout << endl << "Pila vacia..." << endl << endl;
			}

			system("pause");
			break;
		default:
			cout << endl << "Opcion no existe...";
			break;
		}

	} while (opc != 8);

	delete(_Pila);

}