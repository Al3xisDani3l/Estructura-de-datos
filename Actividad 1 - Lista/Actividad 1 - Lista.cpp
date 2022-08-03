// Actividad 1 - Lista.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;



#pragma region Lista

template<typename T>
struct Nodo
{

    T dato;

    struct Nodo<T>* Siguiente = NULL;

};

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

    void Insert(T dato) {
       
        Nodo<T>* aux = new Nodo<T>;

        aux->dato = dato;

        aux->Siguiente = _lista;

        _lista = aux;

        _count++;

    }
    
    bool Insert(T dato, size_t pos) {

        Nodo<T>* aux1 = new Nodo<T>;
        Nodo<T>* aux2 = new Nodo<T>;

        aux1->dato = dato;

        if (pos == 0 )
        {
            aux1->Siguiente = _lista;
            _lista = aux1;
            _count++;
            return true;
        }
        else
        {
            aux2 = _lista;

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
     
    T Get(size_t pos) {
        
        Nodo<T>* aux = _lista;
        if (pos < _count)
        {
            for (size_t i = _count - 1; aux != NULL; i--)
            {
                if (i == pos)
                {
                    T dato = aux->dato;
                    return dato;
                }
                aux = aux->Siguiente;
            }
        }
        else
        {
            return NULL;
        }

    }
   
    ostream& Show(ostream& out = cout, bool vertical = true ) {

        if (vertical)
        {
            for (size_t i = 0; i < _count; i++)
            {
                out << Get(i)<<endl;
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

            for (size_t i = 1;aux2!= NULL ; i++)
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
    bool Delete(T dato) {
       

        int index = IndexOf(dato);

        if (index >= 0)
        {
            return  Delete(index,false);
        }
        else
        {
            return false;
        }
        
    }

   
    

    T Sum() {

        /*Nodo<T>* aux = _lista;*/
        T sum;

        for (size_t i = 0; i < _count; i++)
        {
            if ( i == 0 )
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

    int IndexOf(T dato) {

        int index = -1;
    
        size_t cont = _count;

        Nodo<T>* aux = _lista;

        while (aux != NULL && cont > 0)
        {
            cont--;
            if (aux->dato == dato)
            {
                index = cont;
            }
            aux = aux->Siguiente;
            
        }

       
        return index;

    }

    int LastIndexOf(T dato) {

        int index = -1;

        int cont = _count;

        Nodo<T>* aux = _lista;

        while (aux != NULL && cont > 0)
        {
            cont--;
            if (aux->dato == dato)
            {
                index = cont;

                return index;
            }
            aux = aux->Siguiente;

        }
        return -1;

       
    }

    size_t Count() {
        return _count;
    }

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

template<typename T>
ostream& operator <<(ostream& out, Lista<T>* in) {

    return in->Show(out,false);

}


#pragma endregion


int main()
{
    Lista<int>* lista = new Lista<int>();
   



    int dato = 0, opc = 0, pos = 0;
    int posi = 0;

    do {
        system("cls");
        cout << endl << endl << "Menu Lista Sencilla" << endl <<
            "1 Insertar al inicio de la lista" << endl <<
            "2 Insertar al final de la lista" << endl <<
            "3 Insertar en una posicion de la lista" << endl <<
            "4 Mostrar la lista" << endl <<
            "5 Eliminar lista" << endl <<
            "6 Buscar un dato" << endl <<
            "0 Salir" << endl<<endl;
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << endl << endl << "Ingresa el dato: ";
            cin >> dato;
            lista->Insert(dato,0);
            
            break;
        case 2:
            cout << endl << endl << "Ingresa el dato: ";
            cin >> dato;
            lista->Insert(dato);
            /*
                lista->nodo3 - nodo2 - nodo1 - nodo4 - nodo5
            */
            break;
        case 3:
            cout << endl << endl << "Ingresa el dato: ";
            cin >> dato;
            cout << "Ingresa posicion: ";
            cin >> pos;
            lista->Insert(dato, pos);
            break;
        case 4:
          
            cout << lista << endl;
            break;

        case 5:
            cout << endl << "Limpiando lista..." << endl;
            lista->clear();
            cout << "Lista limpiada" << endl;
            break;

        case 6:

            cout << endl << endl << "Introduce el numero a buscar: ";
            cin >> dato;
            posi = lista->IndexOf(dato);
            if (pos >= 0)
            {
                cout << endl << "Dato encontrado en la posicion : " << posi << endl;
            }
            else
            {
                cout << "No se encontro ningun dato";
            }
            
            break;
        
        default:
            cout << endl << endl << "Opcion no encontrada..." << endl;
            break;
        }
        system("pause");
    } while (opc != 0);


   



   


}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
