// Colas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Alexis Daniel Hernandez Gamez
#include <iostream>
#include <stdio.h>

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

template<typename T>
void Pila<T>::Push(T in) {
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

	void MostrarTodo(ostream * salida) {
		
		Nodo<T>* _aux = _primero;

		while (_aux != NULL)
		{
			*salida << "\n" << _aux->Dato << "\n";
			_aux = _aux->Siguiente;
		}
	

	}

	 Cola<T>* Invertir(){

		 Nodo<T>* _aux = _primero;
		 Cola<T>* _CAux = new Cola<T>();
		 Pila<T>* _PAux = new Pila<T>();

		 //Rellenamos la pila
		 while (_aux !=NULL)
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


int main()
{
	int opciones = 0;
	int _in;
	int _out;
	//instanciamos la cola;
	Cola<int>* _cola = new Cola<int>();


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
			cout << "Ultimo: " << _cola->Ultimo()<<endl;
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
