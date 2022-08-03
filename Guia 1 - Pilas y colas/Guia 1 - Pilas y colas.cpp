// Guia 1 - Pilas y colas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
//Se reutiliza el codigo de la pila para implementaciones en la cola
#pragma region Definicion del tipo pila, -mi implementacion-

template<typename T> struct Node
{
	T Dato;
	struct Node<T>* Next;

};



//definimos una plantilla generica
template<typename T> class Pila
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
	Node<T>* _pila;
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
	Node<T>* aux = new Node<T>();
	aux->Dato = in;
	aux->Next = _pila;
	_pila = aux;
	contador++;

}

template<typename T>
T Pila<T>::Pop() {

	Node<T>* aux = _pila;

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

	Node<T>* aux = _pila;

	while (aux != NULL)
	{
		*salida << "\n" << aux->Dato << "\n";
		aux = aux->Next;
	}

}


template<typename T>
void Pila<T>::Clear() {
	Node<T>* aux;
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

	Node<T>* ultimo = _pila;

	Node<T>* aux = _pila;

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

#pragma region Mi Implementacion de la cola

template<typename T> struct Nodo
{
	T Dato;
	struct Nodo<T>* Siguiente = NULL;
};

template<typename T> class Cola
{

public:


	void Encolar(T in) {

		Nodo<T>* _aux = new Nodo<T>;
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

		Nodo<T>* _Aux;

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

		Nodo<T>* _aux = _primero;

		while (_aux != NULL)
		{
			*salida << "\n" << _aux->Dato << "\n";
			_aux = _aux->Siguiente;
		}


	}

	Cola<T>* Invertir() {

		Nodo<T>* _aux = _primero;
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

	Nodo<T>* _filaEntera;
	Nodo<T>* _primero;
	Nodo<T>* _Ultimo;
	unsigned int CantidadEle;

};




#pragma endregion

#pragma region Logica interna

template<typename T>
void RellenarCola(Pila<T>* _pila, Cola<T>* _cola) {
	while (_pila->Lenght() != 0)
	{
		_cola->Encolar(_pila->Pop());
	}
}

template<typename T>
void RellenarPila(Pila<T>* _pila, Cola<T>* _cola) {

	while (!_cola->IsEmpty())
	{
		_pila->Push(_cola->Desencolar());
	}
}

#pragma endregion



int main()
{
	int salida = 0;
	string _in;
	int _out;

	Pila<string>* pila = new Pila<string>();

	Cola<string>* cola = new Cola<string>();

	
		char continuar;
		do
		{
			system("cls");

			cout << "Introduce una palabra: ";
			
			getline(cin, _in);
			pila->Push(_in);
			
		
			
			cout << endl << "Desea continuar rellenando la pila S/N: ";
			cin >> continuar;
			cin.ignore();
		
		} while (continuar == 's' || continuar == 'S');

		cout << endl << "<<Pila>>" << endl;

		cout << endl << "La pila contiene " << pila->Lenght() << " elementos" << endl;
		//mostramos el contenido de la pila
		pila->ShowAll(&cout);

		cout << endl;
		system("Pause");
		cout << endl;

		//Vaciamos la pila en la cola
		cout << endl << "<<Vaciando en cola>>" << endl;

		RellenarCola(pila, cola);

		cout <<endl<< "La cola contiene " << cola->Length() << " elementos" << endl;

		cola->MostrarTodo(&cout);
		cout << endl;
		system("pause");
		cout << endl;
		//Vaciamos la cola en la pila nuevamente
		cout << endl << "<<Vaciando en pila>>" << endl;

		RellenarPila(pila, cola);

		cout << endl << "La pila contiene " << pila->Lenght() << " elementos" << endl;

		pila->ShowAll(&cout);
		cout << endl << "----------------------------------------"<< endl;
		cout << endl << "La cola contiene " << cola->Length() << " elementos" << endl;
		cola->MostrarTodo(&cout);
		cout << endl;
	
		system("pause");









	
   
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
