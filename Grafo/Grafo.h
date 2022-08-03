#pragma once

#include <iostream>

using namespace std;


template<class T> struct Arista;


template<class T>
struct NodoG
{
	T dato;
	 NodoG<T>* sig;
     Arista<T>* arista;




};

template<class T>
struct Arista
{
	 NodoG<T>* destino;
	 Arista<T>* sig;
};







template<class T>
class Grafo
{
public:
	Grafo() {
		_countNodos = 0;
		_countAristas = 0;

	}
	~Grafo() {
		delete _grafo;
		
	}

	int IndexOf(T dato) {

		int index = -1;

		size_t cont = _countNodos;

		NodoG<T>* aux = _grafo;

		while (aux != NULL && cont > 0)
		{
			cont--;
			if (aux->dato == dato)
			{
				index = _countNodos - (cont + 1) ;
			}
			aux = aux->sig;

		}


		return index;

	}

	bool Delete(size_t pos, bool isInt = false) {


		NodoG<T>* aux2 = _grafo;
		NodoG<T>* aux1 = _grafo;


		size_t con = _countNodos;

		if (pos < _countNodos)
		{

			for (size_t i = 1; aux2 != NULL; i++)
			{
				if (i == pos)
				{
					aux1->sig = aux2->sig;
					aux2->sig = aux1;
					_grafo = aux1;
					_countNodos--;

					return true;

				}
				aux2 = aux2->sig;
			}
			return false;

		}
		else
		{
			return false;
		}


	}

	bool Delete(T dato) {


		int index = IndexOf(dato);

		if (index >= 0)
		{
			return  Delete(index, false);
		}
		else
		{
			return false;
		}

	}

	void Add(T dato) {


		NodoG<T>* temp = new NodoG<T>();


		temp->dato = dato;

		if (_grafo == NULL)
		{
			_grafo = temp;
			_countNodos++;


		}
		else
		{
			NodoG<T>* aux = _grafo;

			while (aux->sig != NULL)
			{
				aux = aux->sig;

			}

			aux->sig = temp;
			_countNodos++;
			 
		}


	}

	

	void CreateConexion(T init, T end) {

		Arista<T>* temp = new Arista<T>();

		NodoG<T>* aux, *aux2;

		if (_grafo == NULL)
		{
			cout << endl << "Grafo vacio..." << endl;
			return;
		}

		temp->sig = NULL;

		aux = _grafo;
		aux2 = _grafo;

		while (aux2 != NULL)
		{
			if (aux2->dato == end)
			{
				break;//Si se encuentra en nodo, se detiene
			}

			aux2 = aux2->sig;

		}

		while (aux != NULL)
		{
			if (aux->dato == init)
			{
				Arista<T>* _temp;

				if (aux->arista == NULL)//Nodo sin aristas
				{
					aux->arista = temp;
					temp->destino = aux2;
				}
				else
				{
					_temp = aux->arista;//iniciando la lista de aristas
					while (_temp->sig != NULL)
					{
						_temp = _temp->sig;//se recorre la lista de aristas


					}
					temp->destino = aux2;
					_temp->sig = temp;
				}
				return;
			}

			aux = aux->sig;

		}

		_countAristas++;
	}

	ostream& Print(ostream& out = cout) {

		NodoG<T>* aux;
		aux = _grafo;

		Arista<T>* arista;

		out << endl << "* * * G R A F O * * *" << endl;

		while (aux != NULL)
		{
			out << aux->dato << " ";

			if (aux->arista != NULL)
			{
				arista = aux->arista;
				while (arista != NULL)
				{
					out << arista->destino->dato<<" ";
					arista = arista->sig;
				}
			}
			aux = aux->sig;

			out << endl;


		}
		return out;
	}

private:

	NodoG<T>* _grafo;

	size_t _countNodos;
	size_t _countAristas;

};

template<class T>
ostream& operator <<(ostream& out, Grafo<T>* g) {

	return g->Print(out);
}




