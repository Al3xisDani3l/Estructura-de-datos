// Actividad 2 - Documentacion.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Author: Alexis Daniel Hernandez Gamez
// Version: 23/08/2021 C

#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>

using namespace std;

#pragma region Codigo de la Pila



/// <summary>
//Tipo de dato que lleva el control de la ubicacion del dato actual y el dato siguiente en memoria.
//Esta estructura es generica y acepta cualquier tipo de dato.
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T> struct Nodo
{
	T Dato;
    struct Nodo<T>* Siguiente = NULL;

};



/// <summary>
// Clase que engloba toda la logica de una pila, ademas de llevar un control interno de la misma.
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T> class Pila
{
public:
	/// <summary>
	/// Clase que engloba toda la logica de una pila, ademas de llevar un control interno de la misma.
	/// </summary>
	Pila();

	~Pila();
	/// <summary>
    ///Inserta un nuevo dato en la sima de la cola
	/// </summary>
	/// <param name="in"></param>
	void Push(T in);
	/// <summary>
	// Extrae el ultimo dato ingresado en la cola
	/// </summary>
	/// <returns></returns>
	T Pop();
	/// <summary>
	///Devuelve la cantidad de elementos de introducidos en la cola
	/// </summary>
	/// <returns></returns>
	int Lenght();
	/// <summary>
	///Muestra en pantalla los elementos de la cola
	/// </summary>
	/// <param name="salida"></param>
	ostream& ShowAll(ostream& salida = cout);
	/// <summary>
	///Limpia el contenido de la cola hasta dejarla en cero
	/// </summary>
	void Clear();
	/// <summary>
	///Devuelve el primer elemento de la cola sin eliminarlo
	/// </summary>
	/// <returns></returns>
	T First();
	/// <summary>
	///Devuelvel el ultimo elemento de la cola sin eliminarlo
	/// </summary>
	/// <returns>ultimo elemento</returns>
	T Last();
	Nodo<T>* _pila;

private:
    //Lleva el control de cuantos elementos contienen la pila.
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
    //creamos un nuevo nodo generico y le asignamos la pila actual en siguiente para dejar hasta al principio el nodo introducido.
	Nodo<T>* aux = new Nodo<T>();
	aux->Dato = in;
	aux->Siguiente = _pila;
	_pila = aux;
	contador++;

}

template<typename T>
T Pila<T>::Pop() {

	//Extraemos el ultimo elemento de la pila y eliminamos el nodo que lo contenia.
	Nodo<T>* aux = _pila;

	T Dato = aux->Dato;
	_pila = aux->Siguiente;

	delete(aux);

	contador--;
	return Dato;


}


template<typename T>
int Pila<T>::Lenght() {
    //retornamos el contenido del contador interno
	return contador;
}

template<typename T>
ostream& Pila<T>::ShowAll(ostream& salida) {

    //a travez de la salida que nosotros pidamos
    //se mostraran los datos de la pila de manera consecutiva
	Nodo<T>* aux = _pila;

	while (aux != NULL)
	{
		*salida << " " << aux->Dato << " ";
		aux = aux->Siguiente;
	}
    //retornamos la salida para dar compatibilidad con la consola.
    return salida;

}


template<typename T>
void Pila<T>::Clear() {
    //Recorremos cada nodo y lo vamos eliminando, tambien lo descontamos del contador.
	Nodo<T>* aux;
	while (_pila != NULL)
	{
		aux = _pila;
		_pila = aux->Siguiente;
		delete(aux);
		contador--;
	}
}

template<typename T>
T Pila<T>::Last() {
    //solo mandamos el dato.
	return _pila->Dato;
}

template<typename T>
T Pila<T>::First() {

    //recorremos la lista hasta llegar al ultimo nodo (el primero en ser introducido) y lo retornamos.
	Nodo<T>* ultimo = _pila;

	Nodo<T>* aux = _pila;

	if (contador == 0)
	{
		return NULL;
	}
	while (aux != NULL)
	{
		ultimo = aux;
		aux = aux->Siguiente;
	}

	return ultimo->Dato;



}

/// <summary>
/// Sobrecarga del operador de salida para que muestre la lista directamente sin necesidad
/// de llamar a una funcion, solo llamando a la variable instanciada.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="o"></param>
/// <param name="p"></param>
/// <returns></returns>
template<typename T>
ostream& operator << (ostream& o, Pila<T> *p) {

    return p->ShowAll(o);
}



#pragma endregion

#pragma region Codigo de la cola

/// <summary>
/// Clase generica que engloba toda la logica de una cola (FIFO).
/// </summary>
/// <typeparam name="T">Tipo generico</typeparam>
template<typename T> class Cola
{

public:

	/// <summary>
	/// Agrega un nuevo elemento en el tope de la cola
	/// </summary>
	/// <param name="in"></param>
	void Encolar(T in) {
        //agreagamos un nuevo nodo y le asignamos el dato
        
		Nodo<T>* _aux = new Nodo<T>;
		_aux->Dato = in;
		if (IsEmpty())
		{
            //lo agregamos al principio y final de la cola en dado caso de ser el primero
			_primero = _aux;
			_Ultimo = _primero;
			CantidadEle++;
		}
		else
		{

            //lo agregamos al final de la cola.
			_Ultimo->Siguiente = _aux;
			_Ultimo = _Ultimo->Siguiente;

			CantidadEle++;
		}

	}

	/// <summary>
	/// Debuelve el primer elemento de la cola.
	/// </summary>
	/// <returns></returns>
	T Desencolar() {

		Nodo<T>* _Aux;

		T _Dato;

        //determinamos si la cola no esta vacia

		if (!IsEmpty())
		{
            //devolvemos el primer elemento de la cola
            // y eleminamos el nodo
			_Dato = _primero->Dato;
			_Aux = _primero;
			_primero = _primero->Siguiente;
			delete _Aux;
			CantidadEle--;
			return _Dato;

		}




	}

	/// <summary>
	///retorna el primer dato sin alterar la cola
	/// </summary>
	/// <returns></returns>
	T Primero() {
		return _primero->Dato;

	}
    /// <summary>
    ///retorna el ultimo dato sin alterar la cola
    /// </summary>
    /// <returns></returns>
	T Ultimo() {
		return _Ultimo->Dato;
	}

	/// <summary>
	///Edita el primer nodo
	/// </summary>
	/// <param name="in"></param>
	void Primero(T in) {
		_primero->Dato = in;
	}
    
	/// <summary>
	/// Edita el ultimo nodo
	/// </summary>
	/// <param name="in"></param>
	void Ultimo(T in) {
		_Ultimo->Dato = in;
	}

    //Limpia la cola hasta dejar en cero su contenido.
	void Clear() {
		while (!IsEmpty())
		{
			Desencolar();
		}
	}

    //Determina si la cola esta vacia.
	bool IsEmpty() const {
		return _primero == NULL;
	}

    //Retorna la cantidad de elementos actual en la cola
	int Length() {
		return CantidadEle;
	}

    //Muestra el contenido de la cola en la consola.
	void MostrarTodo(ostream* salida) {

		Nodo<T>* _aux = _primero;

		while (_aux != NULL)
		{
			*salida << "\n" << _aux->Dato << "\n";
			_aux = _aux->Siguiente;
		}


	}

    //Devuelve una cola con el contenido invertido de la cola actual
	Cola<T>* Invertir() {
        //hacemos uso de la ayuda de la estructua de la pila para invertir la cola.
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

#pragma region Codigo de la Lista

/// <summary>
/// Clase generica que engloba toda la logica de una lista
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
class Lista
{
public:

    Lista() {
        _count = 0;
    }

    ~Lista() {
        clear();
    }

    /// <summary>
    /// Insertamos un nuevo dato indexado
    /// </summary>
    /// <param name="Dato"></param>
    void Insert(T Dato) {

        Nodo<T>* aux = new Nodo<T>;

        aux->Dato = Dato;

        aux->Siguiente = _lista;

        _lista = aux;

        _count++;

    }
    
    
    /// <summary>
    //Insertamos un nuevo dato en la posicion indicada
    /// </summary>
    /// <param name="Dato"></param>
    /// <param name="pos"></param>
    /// <returns>Retorna si el dato se incerto correctamente</returns>
    bool Insert(T Dato, size_t pos) {

        Nodo<T>* aux1 = new Nodo<T>;
        Nodo<T>* aux2 = new Nodo<T>;

        aux1->Dato = Dato;

        if (pos == 0)
        {
            aux1->Siguiente = _lista;
            _lista = aux1;
            _count++;
            return true;
        }
        else
        {
            aux2 = _lista;
            //buscamos la posicion indicada
            for (size_t i = 1; aux2 != NULL; i++)
            {
                if (i == pos)
                {
                    aux1->Siguiente = aux2->Siguiente;
                    aux2->Siguiente = aux1;
                    _count++;
                    return true;

                }
                aux2 = aux2->Siguiente;
            }
            return false;
        }



    }

    /// <summary>
    /// Obtenemos el dato de la posicion indicada
    /// </summary>
    /// <param name="pos"></param>
    /// <returns></returns>
    T Get(size_t pos) {

        Nodo<T>* aux = _lista;
        if (pos < _count)
        {
            for (size_t i = _count - 1; aux != NULL; i--)
            {
                if (i == pos)
                {
                    T Dato = aux->Dato;
                    return Dato;
                }
                aux = aux->Siguiente;
            }
        }
        else
        {
            return NULL;
        }

    }

    /// <summary>
    /// Mostramos los datos en consola.
    /// </summary>
    /// <param name="out"></param>
    /// <param name="vertical">Determina si se muestran vertical u horizontalmente los datos en consola</param>
    /// <returns></returns>
    ostream& Show(ostream& out = cout, bool vertical = true) {

        if (vertical)
        {
            for (size_t i = 0; i < _count; i++)
            {
                out << Get(i) << endl;
            }
            return out;
        }
        else
        {
            for (size_t i = 0; i < _count; i++)
            {
                out << Get(i) << " ";
            }
            return out;
        }

    }

    //Elimina el dato de la poscion indicada
     //Retorna falso en caso de que ningun dato sea eliminado.
    bool Delete(size_t pos, bool isInt = false) {


        Nodo<T>* aux2 = _lista;
        Nodo<T>* aux1 = _lista;


        size_t con = _count;

        if (pos < _count)
        {

            for (size_t i = 1; aux2 != NULL; i++)
            {
                if (i == pos)
                {
                    aux1->Siguiente = aux2->Siguiente;
                    aux2->Siguiente = aux1;
                    _lista = aux1;
                    _count--;

                    return true;

                }
                aux2 = aux2->Siguiente;
            }
            return false;

        }
        else
        {
            return false;
        }


    }

    //Elimina el primer dato que coincida en la lista
    //Retorna falso en caso de que ningun dato sea eliminado.
    bool Delete(T Dato) {


        int index = IndexOf(Dato);

        if (index >= 0)
        {
            return  Delete(index, false);
        }
        else
        {
            return false;
        }

    }



    /// <summary>
    /// Suma o concatena todos los datos de la fila
    /// para que sea aceptado debe estar sobrecargado el operador +=
    /// </summary>
    /// <returns></returns>
    T Sum() {

        /*Nodo<T>* aux = _lista;*/
        T sum;

         
        for (size_t i = 0; i < _count; i++)
        {
            if (i == 0)
            {
                sum = Get(i);
            }
            else
            {
                sum += Get(i);
            }

        }
        /*
          if (aux!= NULL)
           {
               sum = aux->dato;
               aux = aux->Siguiente;
               while (aux != NULL)
               {
                   sum += aux->dato;
                   aux = aux->Siguiente;
               }
           }*/

        return sum;
    }

    /// <summary>
    /// Devuelve la posicion de la primera coincidencia del dato solicitado
    /// </summary>
    /// <param name="Dato"></param>
    /// <returns>retorna el indice en base 0, retorna -1 en caso de no encontrarse el dato</returns>
    int IndexOf(T Dato) {

        int index = -1;

        size_t cont = _count;

        Nodo<T>* aux = _lista;

        while (aux != NULL && cont > 0)
        {
            cont--;
            if (aux->Dato == Dato)
            {
                index = cont;
            }
            aux = aux->Siguiente;

        }


        return index;

    }

    /// <summary>
    /// Devuelve la posicion de la ultima coincidencia del dato solicitado
    /// </summary>
    /// <param name="Dato"></param>
    /// <returns>retorna el indice en base 0, retorna -1 en caso de no encontrarse el dato</returns>
    int LastIndexOf(T Dato) {

        int index = -1;

        int cont = _count;

        Nodo<T>* aux = _lista;

        while (aux != NULL && cont > 0)
        {
            cont--;
            if (aux->Dato == Dato)
            {
                index = cont;

                return index;
            }
            aux = aux->Siguiente;

        }
        return -1;


    }
    /// <summary>
    /// retorna la cantidad de elementos de la lista
    /// </summary>
    /// <returns></returns>
    size_t Count() {
        return _count;
    }

    /// <summary>
    /// Limpia la lista 
    /// </summary>
    void clear() {


        Nodo<T>* aux;
        while (_lista != NULL)
        {
            aux = _lista;
            _lista = aux->Siguiente;
            delete(aux);
            _count--;
        }

    }



private:
    Nodo<T>* _lista;

    size_t _count;
};

/// <summary>
/// Sobrecarga del operador de salida, para mostrar la lista sin 
/// necesidad de funciones.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="out"></param>
/// <param name="in"></param>
/// <returns></returns>
template<typename T>
ostream& operator <<(ostream& out, Lista<T>* in) {

    return in->Show(out, false);

}


#pragma endregion

int main()
{
    //--Modo de uso--//
    //Instanciamos las clases y empezamos a utilizar sus metodos, definimos el tipo 
    //de dato que recibira
    Pila<string>* pila = new Pila<string>();

    Cola<double>* cola = new Cola<double>();

    Lista<int>* lista = new Lista<int>();

   //Llamada a sus metodos

    pila->Push("hola");
    cola->Encolar(16.4);
    lista->Insert(12);

}

