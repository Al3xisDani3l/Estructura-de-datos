// Pilas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;






#pragma region Implementacion en clases
/*Estructura nodo*/
//struct nodo {//Se crea una estructura con el nombre nodo con dos componentes
//	int numero;//Almacena un dato numérico en el nodo
//	struct nodo* sig;//Almacena la dirección de memoria del nodo continuo
//};
//
//typedef nodo* P;//Define un tipo de dato estructura nodo
//
//int contador = 0;
//
//void mostrar_pila(P p)//Al no haber manipulación directa de la pila, no es necesario hacer referencia
//{
//	P aux;//Creo un auxiliar es de tipo nodo *P
//	aux = p;//se iguala la ultima dirección que apunta la pila al auxiliar
//
//	while (aux != NULL)//Mientras el puntero auxiliar no apunte a nulo
//	{
//		cout << endl << aux->numero << endl; //Se imprime el numero que hay en cada nodo
//		aux = aux->sig;
//	}
//}
//
//void push(P& p, int n)
//{
//	P aux;
//	aux = new nodo;//Creamos y apuntamos a un nuevo nodo
//	aux->numero = n;//Se asigna el número ingresado de teclado
//	aux->sig = p; //el siguiente elemento se apunta al anterior creado
//	p = aux;//Asignación del nodo creado a la pila original
//	contador++;
//}
//
//int pop(P& p)//Habrá manipulación a la pila, por lo que tiene que mandar la referencia
//{
//	int num;
//	P aux;
//
//	aux = p;//Se le asigna dirección de la pila a un puntero auxiliar
//	num = aux->numero; //El numero dentro del nodo se almacena a una variable entera
//
//	p = aux->sig; //Se la dirección del ultimo nodo se cambia al nodo anterior
//	//desvinculando el nodo a eliminar
//	delete(aux); //Se elimina el ultimo nodo creado
//	contador--;
//	return num; //Se regresa el numero del nodo eliminado para su impresión
//}
//
//void destruir_pila(P& p)
//{
//	P aux;
//	while (p != NULL)
//	{
//		aux = p;
//		p = aux->sig;
//		delete(aux);
//	}
//
//	cout << endl << "Pila borrada..." << endl;
//}
//
////No requerimos Manipular la pila
////int MostrarPrimerElemento(P p) {
////
////	P aux;//Creo un auxiliar es de tipo nodo *P
////	aux = p;//se iguala la ultima dirección que apunta la pila al auxiliar
////
////	P anterior;
////
////	do
////	{
////
////
////	} while (aux != NULL);
////
////	while (aux != NULL)//Mientras el puntero auxiliar no apunte a nulo
////	{
////		cout << endl << aux->numero << endl; //Se imprime el numero que hay en cada nodo
////		aux = aux->sig;
////	} 
////}
//
//int MostrarUltimoElemento(P p) {
//
//	return p->numero;
//
//}
//
//int Contador() {
//	return contador;
//}
#pragma endregion

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
	Node<T> *_pila;
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





int main()
{
	//Instanciamos la clase que contiene toda la logica de una pila.
	Pila<int>* _Pila = new Pila<int>();

	//P pila = NULL;//Iniciando la pila en Nulo
	int dato = 0, opc = 0, x;

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
				cout << endl << "Se elimino el nodo con el numero " << x<<endl;
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
				cout << endl << "Pila vacia..." << endl<<endl;
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
	return 0;
}