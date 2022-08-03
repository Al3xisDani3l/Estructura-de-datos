#pragma once

#include <iostream>

using namespace std;



#pragma region Lista

template<typename T>
struct NodoL
{

    T dato;

    struct NodoL<T>* Siguiente = NULL;

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

        NodoL<T>* aux = new NodoL<T>;

        aux->dato = dato;

        aux->Siguiente = _lista;

        _lista = aux;

        _count++;

    }

    bool Insert(T dato, size_t pos) {

        NodoL<T>* aux1 = new NodoL<T>;
        NodoL<T>* aux2 = new NodoL<T>;

        aux1->dato = dato;

        aux2 = _lista;

        if (pos < _count)
        {

            for (size_t i = _count - 1; i >= 0; i--)
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
        }
        else
        {
            return false;
        }


        /*  if (pos == 0)
          {
              aux1->Siguiente = _lista;
              _lista = aux1;
              _count++;
              return true;
          }
          else
          {
              aux2 = _lista;

              for (size_t i = 0; aux2 != NULL; i--)
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
          }*/



    }

    T Get(size_t pos) {

        NodoL<T>* aux = _lista;
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


        NodoL<T>* p = _lista;

        NodoL<T>* ant = NULL;

        if (_lista != NULL)
        {

            for (size_t i = _count - 1; i >= 0 || p != NULL; i--)
            {

                if (i == pos)
                {
                    if (p == _lista)
                    {
                        _lista = _lista->Siguiente;
                    }
                    else
                    {
                        ant->Siguiente = p->Siguiente;
                        delete(p);
                        _count--;
                        return true;
                    }
                }

                ant = p;
                p = p->Siguiente;
            }
            return false;

        }
        else
        {
            return false;
        }

        //NodoL<T>* aux1 = _lista;
        //NodoL<T>* aux2 = _lista;

        //NodoL<T>* recolector;

        //bool dele = false;

        //size_t con = _count;

        //if (pos < _count)
        //{


        //    for (size_t i = _count -1; i >= 0; i--)
        //    {

        //        if (i != pos)
        //        {

        //            recolector = aux1;
        //           
        //           
        //        }
        //        else
        //        {

        //        }
        //        aux1 = aux1->Siguiente;

        //    }

        //    for (size_t i = _count -1; i >=0; i--)
        //    {
        //        if (i != pos)
        //        {
        //           aux2 = aux2->Siguiente;
        //           aux1->Siguiente = aux2;
        //            aux2->Siguiente = aux1;
        //            _lista = aux1;
        //            _count--;
        //            dele = true;
        //            return dele;

        //        }
        //      //aux2 = aux2->Siguiente;

        //    }
        //    
        //}
        //return dele;


    }

    //Elimina el primer dato que coincida en la lista
    //Retorna falso en caso de que ningun dato sea eliminado.
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




    T Sum() {

        /*NodoL<T>* aux = _lista;*/
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

    int IndexOf(T dato) {

        int index = -1;

        size_t cont = _count;

        NodoL<T>* aux = _lista;

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

        NodoL<T>* aux = _lista;

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


        NodoL<T>* aux;
        while (_lista != NULL)
        {
            aux = _lista;
            _lista = aux->Siguiente;
            delete(aux);
            _count--;
        }

    }

    T Mayor() {

        T mayor = NULL;

        if (Count() > 0)
        {

            mayor = Get(0);

            for (size_t i = 1; i < _count; i++)
            {
                T dato = Get(i);

                if (dato > mayor)
                {
                    mayor = dato;
                }


            }

        }
        return mayor;
    }

    T Minor() {

        T menor = NULL;

        if (Count() > 0)
        {

            menor = Get(0);

            for (size_t i = 1; i < _count; i++)
            {
                T dato = Get(i);

                if (dato < menor)
                {
                    menor = dato;
                }


            }

        }
        return menor;
    }

    bool Edit(T dato, size_t pos) {

        if (pos < _count)
        {





            bool isDeleteable = Delete(pos, true);
            bool isInsertable = Insert(dato, pos);

            return isDeleteable && isInsertable;

        }
        else
        {
            return false;
        }


    }



private:
    NodoL<T>* _lista;

    size_t _count;
};

template<typename T>
ostream& operator <<(ostream& out, Lista<T>* in) {

    return in->Show(out, false);

}


#pragma endregion


void ListaSencillaInit(int* nums, int size) {

    Lista<int>* lista = new Lista<int>();


    for (size_t i = 0; i < size; i++)
    {
        lista->Insert(nums[i]);
    }


    int dato = 0, opc = 0, pos = 0;
    int posi = 0;
    int menor;
    int mayor;





    do {
        system("cls");
        cout << endl << endl << "Menu Lista Sencilla" << endl <<
            "1 Insertar al inicio de la lista" << endl <<
            "2 Insertar al final de la lista" << endl <<
            "3 Insertar en una posicion de la lista" << endl <<
            "4 Mostrar la lista" << endl <<
            "5 Eliminar lista" << endl <<
            "6 Buscar un dato" << endl <<
            "7 Editar una posicion" << endl <<
            "8 Cantidad de datos insertados" << endl <<
            "9 Sumatoria de todos los datos agregados" << endl <<
            "10 Dato Mayor de la lista" << endl <<
            "11 Dato Menor de la lista" << endl <<
            "0 Salir" << endl << endl;
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << endl << endl << "Ingresa el dato: ";
            cin >> dato;
            lista->Insert(dato, 0);

            break;
        case 2:
            cout << endl << endl << "Ingresa el dato: ";
            cin >> dato;
            lista->Insert(dato);
            /*
                lista->NodoL3 - NodoL2 - NodoL1 - NodoL4 - NodoL5
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
        case 7:

            cout << endl << "Introduce la posicion del dato a cambiar: ";
            cin >> pos;
            if (pos < lista->Count() && lista->Count() > 1)
            {
                cout << endl << "Cambiar " << lista->Get(pos) << " por :";
                cin >> dato;
                lista->Edit(dato, pos);

                cout << endl << "Dato cambiado por:  " << lista->Get(pos) << endl;
            }
            else
            {
                cout << endl << "La posicion se encuentra fuera de rango no hay ningun elemento insertado aun" << endl;
            }



            break;
        case 8:
            cout << endl << "Cantidad de datos incertados : " << lista->Count() << endl;
            break;
        case 9:

            cout << endl << "Sumatoria de : " << lista << " = " << lista->Sum() << endl;

            break;
        case 10:
            mayor = lista->Mayor();
            if (mayor != NULL || lista->Count() > 0)
            {
                cout << endl << "El dato mayor de la lista es: " << mayor << endl;
            }
            else
            {
                cout << "Ningun dato en la lista aun, agregue mas datos";
            }

            break;
        case 11:
            menor = lista->Minor();
            if (menor != NULL || lista->Count() > 0)
            {
                cout << endl << "El dato menor de la lista es: " << menor << endl;
            }
            else
            {
                cout << "Ningun dato en la lista aun, agregue mas datos";
            }
            break;
        default:
            cout << endl << endl << "Opcion no encontrada..." << endl;
            break;
        }
        system("pause");
    } while (opc != 0);

}