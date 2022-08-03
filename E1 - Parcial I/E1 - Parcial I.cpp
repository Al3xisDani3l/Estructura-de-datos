// E1 - Parcial I.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Alexis Daniel Hernandez Gamez 180263
// Melissa Jazmin Carrera Ramos  180259



#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>

using namespace std;
//Se reutiliza el codigo de la pila para implementaciones en la cola
#pragma region Codigo de la Pila

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
	Node<T>* _pila;

private:
	
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
		*salida << " " << aux->Dato << " ";
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

//template<typename T>
//ostream& operator << (ostream& o, const Pila<T> &p) {
//
//	Node<T>* aux = p._pila;
//
//	while (aux != NULL)
//	{
//		*o << " " << aux->Dato << " ";
//		aux = aux->Next;
//	}
//
//	return o;
//}



#pragma endregion

#pragma region Codigo de la cola

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


#pragma region Implementacion interna
template<typename T>
void RellenarPila(Pila<T>* p) {

	srand(time(NULL));

	int datos = rand() % 20;

	for (size_t i = 0; i < datos; i++)
	{
		int edad = 18 + rand() % (61);
		p->Push(edad);
	}



}


void OrganizarFilas(Pila<int>* filaI, Pila<int>* filaE, Pila<int>* filaG) {

	while (filaI->Lenght()!=0)
	{
	
		int dato = filaI->Pop();

		if (dato >= 60)
		{
			filaE->Push(dato);
		}
		else
		{
			filaG->Push(dato);
		}

	}

}


#pragma endregion


int main()
{
	//Pila inicial
	Pila<int>* pInicial = new Pila<int>();
	//Crear una fila general
	Pila<int>* pGeneral = new Pila<int>();
	//Crear una fila Especial
	Pila<int>* pEspecial = new Pila<int>();

	char continuar;

	do
	{
		system("cls");

		RellenarPila(pInicial);

		cout <<endl<< "Fila inicial ->";
		pInicial->ShowAll(&cout);
		cout << endl<<endl;

		OrganizarFilas(pInicial, pEspecial, pGeneral);

		cout << endl << "Fila especial ->";
		pEspecial->ShowAll(&cout);
		cout  << endl << endl;

		cout << endl << "Fila General ->";
		pGeneral->ShowAll(&cout);
		cout << endl << endl << endl;


		while (pGeneral->Lenght() > 0 || pEspecial->Lenght() > 0)
		{
			int contE = 0;

			while (contE < 2)
			{
				if (pEspecial->Lenght() > 0)
				{
					cout << "  Se atendio -> " << pEspecial->Pop() << endl;
				}
				contE++;
			}

			if (pGeneral->Lenght() > 0)
			{
				cout << "Se atendio -> " << pGeneral->Pop() << endl;
			}



		}

		cout << endl << "Ya no hay mas personas en las filas" << endl;

		cout <<endl <<"Reiniciar el programa S/N: ";
		cin >> continuar;




	} while (!(continuar == 'n' || continuar =='N'));
	 
	

	cout << endl << "Hasta pronto" << endl;


   
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
