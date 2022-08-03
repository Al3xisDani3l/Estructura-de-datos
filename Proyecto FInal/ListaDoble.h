
#include <iostream>


using namespace std;

#pragma region Lista doble enlazada

#pragma region Definicion del NodoLD doble

template<typename T>
struct NodoLD
{
    T Dato;
    NodoLD<T>* Siguiente = NULL;
    NodoLD<T>* Anterior = NULL;

    NodoLD(T value) {
        Dato = value;
    }


};


template<typename T>
class ListaDoble
{
public:

    ListaDoble() {
        _cabeza = NULL;
        _final = NULL;
        _count = 0;
    }

    T& operator[](int index) {

        if (!isEmptyList()) {
            if (!isArrayOutOfBounds(index)) {
                int actualIndex = 0;
                for (NodoLD<T>* node = _cabeza; node != NULL; node = node->Siguiente) {
                    if (index == actualIndex) {
                        return (node->Dato);
                    }
                    actualIndex++;
                }
            }
        }

    }

    void AddFirst(T value) {
        NodoLD<T>* aux = new NodoLD<T>(value);

        if (IsEmpty())
        {
            _cabeza = aux;

            _final = aux;

            _count++;

        }
        else
        {
            aux->Siguiente = _cabeza;
            _cabeza->Anterior = aux;
            _cabeza = aux;
            _count++;
        }

    }

    void AddLast(T value) {

        NodoLD<T>* aux = new NodoLD<T>(value);
        if (IsEmpty()) {
            _cabeza = aux;
            _final = aux;
            _count++;
        }
        else
        {
            aux->Anterior = _final;
            _final->Siguiente = aux;
            _final = aux;
            _count++;
        }
    }


    void Add(int index, T value) {
        if (index == Count()) {
            AddLast(value);
        }
        else {
            if (!isEmptyList()) {
                if (!isArrayOutOfBounds(index)) {
                    int actualIndex = 0;
                    for (NodoLD<T>* actualNode = _cabeza; actualNode != NULL; actualNode = actualNode->Siguiente) {
                        if (actualIndex == index) {
                            if (actualNode == _cabeza) {
                                AddFirst(value);
                                break;
                            }
                            else {
                                NodoLD<T>* newNode = new NodoLD<T>(value);
                                actualNode->Anterior->Siguiente = newNode;
                                newNode->Anterior = actualNode->Anterior;
                                newNode->Siguiente = actualNode;
                                actualNode->Anterior = newNode;
                                _count++;
                                break;
                            }
                        }
                        actualIndex++;
                    }
                }
            }
        }
    }


    T GetFirst() {
        if (!IsEmpty())
        {
            return _cabeza->Dato;
        }
        else
        {
            return (T)NULL;
        }

    }

    T GetLast() {
        if (!IsEmpty())
        {
            return _final->Dato;
        }
        else
        {
            return (T)NULL;
        }

    }

    T Get(int index) {
        if (!isEmptyList()) {
            if (!isArrayOutOfBounds(index)) {
                int actualIndex = 0;
                for (NodoLD<T>* node = _cabeza; node != NULL; node = node->Siguiente) {
                    if (index == actualIndex) {
                        return node->Dato;
                    }
                    actualIndex++;
                }
            }
        }
        return (T)NULL;
    }


    int IndexOf(T value) {
        if (!isEmptyList()) {
            int index = 0;
            for (NodoLD<T>* node = _cabeza; node != NULL && index < _count; node = node->Siguiente) {
                if (node->Dato == value) {
                    return index;
                }
                index++;
            }
        }
        return -1;
    }

    void RemoveFirst() {
        if (!isEmptyList()) {

            NodoLD<T>* node = _cabeza;
            if (_cabeza == _final) {
                _cabeza = NULL;
                _final = NULL;
                _count--;
            }
            else {
                _cabeza = node->Siguiente;
                node->Siguiente->Anterior = NULL;
                _count--;
            }
            delete node;
        }


    }
    void RemoveLast() {
        if (!isEmptyList()) {
            NodoLD<T>* node = _final;
            if (_cabeza == _final) {
                _cabeza = NULL;
                _final = NULL;
                _count--;
            }
            else {
                _final = node->Anterior;
                node->Siguiente = NULL;
                _count--;
            }
            delete node;
        }


    }
    void RemoveIndex(int index) {
        if (!isEmptyList()) {
            if (!isArrayOutOfBounds(index)) {
                int actualIndex = 0;
                for (NodoLD<T>* node = _cabeza; node != NULL; node = node->Siguiente) {
                    if (actualIndex == index) {
                        remove(node);

                        break;
                    }
                    actualIndex++;
                }
            }
        }
    }

    void RemoveValue(T value) {
        if (!isEmptyList()) {
            for (NodoLD<T>* node = _cabeza; node != NULL; node = node->Siguiente) {
                if (node->Dato == value) {
                    remove(node);

                    break;
                }
            }
        }
    }

    bool IsEmpty() {
        return _cabeza == NULL && _final == NULL && _count == 0;
    }
    void Clear() {
        if (!IsEmpty()) {
            int length = Count();
            for (int i = 0; i < length; i++) {
                RemoveFirst();
            }
        }
    }

    int Count() {
        if (IsEmpty()) {
            return 0;
        }
        else {
            int size = 1;
            for (NodoLD<T>* node = _cabeza; node != _final; node = node->Siguiente) {
                size++;
            }
            if (size != _count) {

                string err = "Incoherencia de conteo interno, revisar los metodos!";
                throw err;
            }
            return _count;
        }
    }


    ostream& Show(ostream& out, bool vertical = false) {
        size_t lenght = Count();
        if (vertical)
        {
            for (size_t i = 0; i < lenght; i++)
            {
                out << Get(i) << endl;
            }
        }
        else
        {
            if (IsEmpty())
            {
                out << "NULL <-> NULL";
            }
            else
            {
                out << "Null <- ";
                for (size_t i = 0; i < lenght; i++)
                {
                    if (i == lenght - 1)
                    {
                        out << Get(i) << " -> NULL";
                    }
                    else
                    {
                        out << Get(i) << " <-> ";
                    }


                }
            }

        }

        return out;
    }

    void Edit(T dato, size_t pos) {

        if (pos < _count)
        {





            RemoveIndex(pos);
            Add(pos, dato);

        }


    }

    T Sum() {
        T sum = NULL;

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
        if (sum == NULL)
        {
            return 0;
        }
        else
        {
            return sum;
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



    ~ListaDoble() {
        Clear();
    }

private:

    NodoLD<T>* _cabeza;
    NodoLD<T>* _final;
    size_t _count;

    bool isEmptyList() {
        if (IsEmpty()) {
            std::string msg = "La lista se encuentra vacia";
            throw msg;
        }
        return false;
    }

    bool isArrayOutOfBounds(int index) {
        if (index >= Count() || index < 0) {
            std::string msg = "El indice se encuentra fuera de los limites";
            throw  msg;
        }
        return false;
    }

    void remove(NodoLD<T>* node) {

        if (node == _cabeza) {
            RemoveFirst();
        }
        else if (node == _final) {
            RemoveLast();
        }
        else {
            node->Anterior->Siguiente = node->Siguiente;
            node->Siguiente->Anterior = node->Anterior;
            delete(node);
            _count--;
        }
    }


};


template<typename T>
ostream& operator <<(ostream& out, ListaDoble<T>* list) {

    return list->Show(out);
}

template<typename T>
istream& operator >>(istream& in, ListaDoble<T>* list) {

    T dato;

    in >> dato;

    list->AddLast(dato);

    return in;

}



#pragma endregion



#pragma endregion


void ListaDobleInit(int* nums, int size) {

    ListaDoble<int>* lista = new ListaDoble<int>();


    for (size_t i = 0; i < size; i++)
    {
        lista->AddLast(nums[i]);
    }

    int dato = 0, opc = 0, pos = 0;
    int posi = 0;
    int menor;
    int mayor;







    do {
        system("cls");

        cout << endl << endl << "<----Estado Actual de la lista---->" << endl << endl;

        cout << endl << "     " << lista << endl;

        cout << endl << endl << "<--------------------------------->" << endl << endl << endl;

        cout << endl << endl << "Menu Lista doblemente enlazada" << endl <<
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
            "13 Borrar un NodoLD segun su posicion" << endl <<
            "14 Borrar un NodoLD segun su numero" << endl <<
            "15 Borrar el primer NodoLD de la lista" << endl <<
            "16 Borrar el ultimo NodoLD de la lista" << endl <<
            "0 Salir" << endl << endl;
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << endl << endl << "Ingresa el dato: ";
            cin >> dato;
            lista->AddFirst(dato);

            break;
        case 2:
            cout << endl << endl << "Ingresa el dato: ";
            cin >> lista;

            /*
                lista->NodoLD3 - NodoLD2 - NodoLD1 - NodoLD4 - NodoLD5
            */
            break;
        case 3:
            cout << endl << endl << "Ingresa el dato: ";
            cin >> dato;
            cout << "Ingresa posicion: ";
            cin >> pos;
            lista->Add(pos, dato);
            break;
        case 4:

            cout << lista << endl;
            break;

        case 5:
            cout << endl << "Limpiando lista..." << endl;
            lista->Clear();
            cout << "Lista limpiada" << endl;
            cout << lista << endl;
            break;

        case 6:

            cout << endl << endl << "Introduce el numero a buscar: ";
            cin >> dato;
            posi = lista->IndexOf(dato);
            if (posi >= 0)
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
        case 12:
            cout << endl << "Introduce la posicion del dato a cambiar: ";
            cin >> pos;
            if (pos < lista->Count() && lista->Count() > 1)
            {
                cout << endl << "Cambiar " << &lista[pos] << " por :";
                cin >> dato;
                lista->Edit(dato, pos);

                cout << endl << "Dato cambiado por:  " << lista->Get(pos) << endl;
            }
            else
            {
                cout << endl << "La posicion se encuentra fuera de rango no hay ningun elemento insertado aun" << endl;
            }
        case 13:
            cout << endl << "Introdusca la posicion del NodoLD a eliminar: ";
            cin >> pos;
            cout << endl << "Se eliminara el dato " << lista->Get(pos) << " !" << endl;
            lista->RemoveIndex(pos);
            cout << "Dato Eliminado" << endl;;
            break;
        case 14:
            cout << endl << "Introdusca el dato a eliminar: ";
            cin >> dato;
            cout << endl << "Se eliminara el NodoLD en la posicion " << lista->IndexOf(dato) << " !" << endl;
            lista->RemoveValue(dato);
            cout << "Dato Eliminado" << endl;;
            break;
        case 15:
            cout << endl << "El primer dato de la lista sera eliminado!";
            lista->RemoveFirst();
            break;
        case 16:
            cout << endl << "El ultimo dato de la lista sera eliminado!";
            lista->RemoveLast();
            break;

        default:
            cout << endl << endl << "Opcion no encontrada..." << endl;
            break;
        }
        cout << endl << endl << endl << endl;
        system("pause");

    } while (opc != 0);
}