// Guia - Parcial II - Agenda.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Alexis Daniel Hernandez Gamez 
//Matricula: 180263
//Fecha: 16/04/2021

#include <iostream>
#include <string>

#include <algorithm>

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

    void Add(T dato) {

        Nodo<T>* aux = new Nodo<T>;

        aux->dato = dato;

        aux->Siguiente = _lista;

        _lista = aux;

        _count++;

    }

    bool Add(T dato, size_t pos) {

        Nodo<T>* aux1 = new Nodo<T>;
        Nodo<T>* aux2 = new Nodo<T>;

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
          /*  return NULL;*/
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


        Nodo<T>* p = _lista;

        Nodo<T>* ant = NULL;

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

        //Nodo<T>* aux1 = _lista;
        //Nodo<T>* aux2 = _lista;

        //Nodo<T>* recolector;

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

    T& operator [](int index) {

       
        if (index >= _count || index < 0)
        {
            throw new exception("Indice Fuera de rango");
        }

        T result = this->Get(index);

        return result;
       
    }

   const T& operator [](int index) const {


        if (index >= _count || index < 0)
        {
            throw new exception("Indice Fuera de rango");
        }

          auto value = const_cast<Lista<T>*>(this)->Get(index);

       

          return value;

    }


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
            bool isInsertable = Add(dato, pos);

            return isDeleteable && isInsertable;

        }
        else
        {
            return false;
        }


    }

    template<typename Func>
    void Edit(size_t pos, Func func) {

        T valueModifie = Get(pos);

        func(valueModifie);


    }

    template<typename Func>

    Lista<T>* Where(Func func) {

        /*vector<T> aux;

        vector<T> result;*/

        Lista<T>* auxLista = new Lista<T>;


        for (size_t i = 0; i < _count; i++)
        {
            T dato = Get(i);
            if (func(dato))
            {
                auxLista->Add(dato);
            }
        }


        //for (size_t i = 0; i < _count ; i++)
        //{
        //    aux.push_back(Get(i));
        //}

        //for (T itr = aux.begin(), end = aux.end(); itr != end; ++itr)
        //{
        //    if (func(itr))
        //    {
        //        result.push_back(itr);
        //        
        //    }
        //}
       
      
      
        return auxLista;

    }

    template<typename Func>
    T First(Func func) {

        for (size_t i = 0; i < _count; i++)
        {
            T dato = Get(i);
            if (func(dato))
            {
                return dato;
            }
        }
        return NULL;

    }

    
private:
    Nodo<T>* _lista;

    size_t _count;
};

template<typename T>
ostream& operator <<(ostream& out, Lista<T>* in) {

    return in->Show(out);

}




#pragma endregion


#pragma region Estructuras

struct Fecha
{
    Fecha() :Fecha(1, 1, 1900) {};

    Fecha(size_t dia, size_t mes, size_t year) {

        if (year < 1900 || year >2100)
        {
            throw new exception("EL year esta fuera de rango 1900 - 2100");
        }
        this->year = year;
        if (mes < 1 || mes >12)
        {
            throw new exception("EL mes esta fuera de rango 1 - 12");
        }
        this->Mes = mes;
        if (dia < 1 || dia >31)
        {
            throw new exception("EL dia esta fuera de rango 1 - 31");
        }
        this->Dia = dia;

    }



    size_t year;
    size_t Mes;
    size_t Dia;

    string ToString() {

        string formato = std::to_string(Dia) + "-" + to_string(Mes) + "-" + to_string(year);

        return formato;


    };






};

struct Contacto
{

    Contacto() :Contacto("Null", "Null") {};

    Contacto(string nombre, string telefono, string correo, Fecha fechaN) {

        Nombre = nombre;
        Telefono = telefono;
        Correo = correo;
        FNacimiento = fechaN;
    }

    Contacto(string nombre, string telefono) :Contacto(nombre, telefono, "Null", Fecha(1, 1, 1900)) {


    };

    string Nombre;
    string Telefono;
    string Correo;
    Fecha FNacimiento;


};

#pragma endregion


#pragma region Sobre cargas

bool operator ==(const Fecha& f1, const Fecha& f2) {

    return f1.year == f2.year && f1.Mes == f2.Mes && f1.Dia == f2.Dia;


}



ostream& operator << (ostream& o, Fecha& f) {

    o << f.ToString();
    return o;
}

istream& operator >>(istream& i, Fecha& f) {

    size_t year;
    size_t Mes;
    size_t Dia;
    char scape;

    i >> Dia >> scape >> Mes >> scape >> year;

    f = Fecha(Dia, Mes, year);

    return i;

}

ostream& operator << (ostream& o, Contacto& t) {


    o << "Nombre: " << t.Nombre << endl;
    o << "Telefono:" << t.Telefono << endl;
    o << "Correo: " << t.Correo << endl;
    o << "Fecha de nacimiento: " << t.FNacimiento << endl;
    return o;


}

ostream& operator << (ostream& o, Contacto* t) {


    o << "Nombre: " << t->Nombre << endl;
    o << "Telefono:" << t->Telefono << endl;
    o << "Correo: " << t->Correo << endl;
    o << "Fecha de nacimiento: " << t->FNacimiento << endl;
    return o;


}


istream& operator >>(istream& in, Contacto* t) {

    string Nombre;
    string Telefono;
    string Correo;
    Fecha FNacimiento;

    cout << endl << "Nombre: ";
    in >> Nombre;
    cout << endl << "Telefono: ";
    in >> Telefono;
    cout << endl << "Correo: ";
    in >> Correo;
    cout << endl << "Fecha de nacimiento (dd-mm-AAAA): ";
    in >> FNacimiento;

    t = new Contacto(Nombre, Telefono, Correo, FNacimiento);

    return in;

}

istream& operator >>(istream& in, Contacto& t) {

    string Nombre;
    string Telefono;
    string Correo;
    Fecha FNacimiento;

    cout << endl << "Nombre: ";
    in >> Nombre;
    cout << endl << "Telefono: ";
    in >> Telefono;
    cout << endl << "Correo: ";
    in >> Correo;
    cout << endl << "Fecha de nacimiento (dd-mm-AAAA): ";
    in >> FNacimiento;

    t.Nombre = Nombre;
    t.Correo = Correo;
    t.Telefono = Telefono;
    t.FNacimiento = FNacimiento;

    return in;

}

#pragma endregion


#pragma region Funciones de soporte


string ToLower(string str) {

    string result = str;

    std::for_each(result.begin(), result.end(), [](char& c) {
        c = tolower(c);
        });
    return result;
}

#pragma endregion












int main()
{

    Lista<Contacto*>* Agenda = new Lista<Contacto*>();

    int dato = 0, opc = 0, pos = 0,opcE = 0;
    int posi = 0;
    int menor;
    int mayor;



#pragma region Datos de prueba

    Agenda->Add(new Contacto("Alexis", "6562538679", "al180263@alumnos.uacj.mx", Fecha(23, 04, 1998)));
    Agenda->Add(new Contacto("Daniel", "6562538678", "al180264@alumnos.uacj.mx", Fecha(24, 04, 1997)));
    Agenda->Add(new Contacto("Gilberto", "6562538677", "al180265@alumnos.uacj.mx", Fecha(25, 04, 1998)));
    Agenda->Add(new Contacto("Pedro", "6562538676", "al180266@alumnos.uacj.mx", Fecha(26, 05, 1998)));
    Agenda->Add(new Contacto("Alberto", "6562538675", "al180267@alumnos.uacj.mx", Fecha(27, 03, 1999)));



#pragma endregion


   // Agenda->Edit(0, [](Contacto* cont) {cont->Nombre = "Rigoberto"; });


    Contacto* result = NULL;
    bool correct = false;
    char cont;
    Lista<Contacto*>* filter = NULL;

    string query;

  
    Contacto temp;

    do {
        system("cls");
        cout << endl << endl << "---------Menu Agenda-------" << endl<<endl <<
            "1 Agregar Contacto" << endl <<
            "2 Mostrar agenda" << endl <<
            "3 Modificar contacto " << endl <<
            "4 Eliminar contacto" << endl <<
            "5 Buscar contacto" << endl <<
            "0 Salir" << endl << endl;
        cin >> opc;


        switch (opc)
        {
        case 1:
            cout << endl << endl << "--------- Contacto nuevo ---------" << endl;
            cin >> temp;
            Agenda->Add(&temp);
            cout << endl << endl << "--------- Dato agregado con exito ---------" << endl;

            break;
        case 2:
            cout << endl << endl << "--------- Tus contactos---------" << endl << endl;
            cout << Agenda << endl;

            /*
                lista->nodo3 - nodo2 - nodo1 - nodo4 - nodo5
            */
            break;
        case 3:

            cout << endl << endl << "--------- Modificar un contacto ---------"<<endl<<endl;

            cout << "Encontrar por nombre (1) \nEncontrar por posicion (2) \nCancelar (0) \nOpcion: ";

            cin >> opcE;
            
            cout << endl << endl;
            
            switch (opcE)
            {
            case 1:
                

              
              
                do
                {
                    cout << endl << "Introdusca el nombre Exacto a buscar" << endl;
                    cout << "Nombre: ";
                    cin >> query;
                    

                    result = Agenda->First([query](Contacto* cont) {return  ToLower(cont->Nombre) == ToLower(query); });

                    if (result != NULL)
                    {
                        correct = true;
                    }
                    else
                    {
                        cout << endl << "Ningun Contacto encontrado con ese nombre, Vuelva a intentar" << endl;
                        cin.get();
                        system("cls");
                        correct = false;
                    }

                } while (!correct);


                pos = Agenda->IndexOf(result);
               
                cout << endl << "Un contacto encontrado" << endl<<endl;

                cout << result <<endl << "Desea Modificarlo? S/N:"  ;
                cin >> cont;

                if (cont == 's' || cont == 'S')
                {
                    cout << endl << endl << "Desea modificar el nombre? S/N:";
                    cin >> cont;
                    cout << endl << endl;
                    if (cont == 's' || cont == 'S')
                    {
                        Agenda->Edit(pos, [](Contacto* cont) {cout << "Nombre Nuevo: "; cin >> cont->Nombre; });
                    }

                 

                   

                    cout << endl << endl << "Desea modificar el telefono? S/N:";
                    cin >> cont;

                    cout << endl << endl;

                    if (cont == 's' || cont == 'S')
                    {
                        Agenda->Edit(pos, [](Contacto* cont) {cout << "Telefono Nuevo: "; cin >> cont->Telefono; });
                    }

                    cout << endl << endl << "Desea modificar el correo? S/N:";
                    cin >> cont;

                    cout << endl << endl;

                    if (cont == 's' || cont == 'S')
                    {
                        Agenda->Edit(pos, [](Contacto* cont) {cout << "Correo Nuevo: "; cin >> cont->Correo; });
                    }

                    cout << endl << endl << "Desea modificar la fecha de nacimiento? S/N:";
                    cin >> cont;

                    cout << endl << endl;

                    if (cont == 's' || cont == 'S')
                    {
                        Agenda->Edit(pos, [](Contacto* cont) {cout << "Fecha de nacimiento nueva: "; cin >> cont->FNacimiento; });
                    }


                    cout << endl << endl << "Contacto modificado con exito:" << endl << endl << result<<endl<<endl;

                }
                else
                {
                    cout << endl << endl << "Ningun contacto fue modificado" << endl << endl;
                    cin.get();
                    break;
                }

               

                break;
            case 2:
                
                
                do
                {
                    cout << endl << "Introdusca la posicion del contacto a modificar" << endl<<endl;
                    cout << "Posicion: ";
                    cin >> pos;

                    result = Agenda->Get(pos);

                    if (result != NULL)
                    {
                        correct = true;
                    }
                    else
                    {
                        cout << endl << "Ningun Contacto encontrado en ese indice, Vuelva a intentar" << endl;
                        cin.get();
                        system("cls");
                        correct = false;
                    }

                } while (!correct);


                cout << endl << "Un contacto encontrado" << endl << endl;

                cout << result << endl << "Desea Modificarlo? S/N:";
                cin >> cont;

                if (cont == 's' || cont == 'S')
                {
                    cout << endl << endl << "Desea modificar el nombre? S/N:";
                    cin >> cont;
                    cout << endl << endl;
                    if (cont == 's' || cont == 'S')
                    {
                        Agenda->Edit(pos, [](Contacto* cont) {cout << "Nombre Nuevo: "; cin >> cont->Nombre; });
                    }





                    cout << endl << endl << "Desea modificar el telefono? S/N:";
                    cin >> cont;

                    cout << endl << endl;

                    if (cont == 's' || cont == 'S')
                    {
                        Agenda->Edit(pos, [](Contacto* cont) {cout << "Telefono Nuevo: "; cin >> cont->Telefono; });
                    }

                    cout << endl << endl << "Desea modificar el correo? S/N:";
                    cin >> cont;

                    cout << endl << endl;

                    if (cont == 's' || cont == 'S')
                    {
                        Agenda->Edit(pos, [](Contacto* cont) {cout << "Correo Nuevo: "; cin >> cont->Correo; });
                    }

                    cout << endl << endl << "Desea modificar la fecha de nacimiento? S/N:";
                    cin >> cont;

                    cout << endl << endl;

                    if (cont == 's' || cont == 'S')
                    {
                        Agenda->Edit(pos, [](Contacto* cont) {cout << "Fecha de nacimiento nueva: "; cin >> cont->FNacimiento; });
                    }




                }
                else
                {
                    cout << endl << endl << "Ningun contacto fue modificado" << endl << endl;
                    cin.get();
                    break;
                }
                break;
            default:
                
                break;
            }

           
            

            break;
        case 4:
            cout << endl << endl << "--------- Eliminar un contacto ---------" << endl << endl;

            cout << "Eliminar por nombre (1) \nEliminar por posicion (2) \nCancelar (0) \nOpcion: ";

            cin >> opcE;

            cout << endl << endl;
            

            switch (opcE)
            {
            case 1:




                do
                {
                    cout << endl << "Introdusca el nombre Exacto a eliminar" << endl;
                    cout << "Nombre: ";
                    cin >> query;


                    result = Agenda->First([query](Contacto* cont) {return  ToLower(cont->Nombre) == ToLower(query); });

                    if (result != NULL)
                    {
                        correct = true;
                    }
                    else
                    {
                        cout << endl << "Ningun Contacto encontrado con ese nombre, Vuelva a intentar" << endl;
                        cin.get();
                        cin.get();
                        system("cls");
                        correct = false;
                    }

                } while (!correct);


                cout << endl << "Un contacto encontrado" << endl << endl;

                cout << result << endl << "Desea eliminarlo? S/N:";
                cin >> cont;

                if (cont == 's' || cont == 'S')
                {
                    if (Agenda->Delete(result)) {

                        cout << endl << endl << "Contacto eliminado con exito" << endl;

                    }
                    else
                    {
                        cout << endl << "Ha ocurrido un error inesperado, el dato no fue eliminado" << endl;
                    }
                }
                else
                {
                    cout << endl << endl << "Ningun contacto fue eliminado" << endl << endl;
                    cin.get();
                    break;
                }



                break;
            case 2:


                do
                {
                    cout << endl << "Introdusca la posicion del contacto a eliminar" << endl << endl;
                    cout << "Posicion: ";
                    cin >> pos;

                    result = Agenda->Get(pos);

                    if (result != NULL)
                    {
                        correct = true;
                    }
                    else
                    {
                        cout << endl << "Ningun Contacto encontrado en ese indice, Vuelva a intentar" << endl;
                        cin.get();
                        cin.get();
                        system("cls");
                        correct = false;
                    }

                } while (!correct);


                cout << endl << "Un contacto encontrado" << endl << endl;

                cout << result << endl << "Desea eliminarlo? S/N:";
                cin >> cont;

                if (cont == 's' || cont == 'S')
                {
                    if (Agenda->Delete(result)) {

                        cout << endl << endl << "Contacto eliminado con exito" << endl;

                    }
                    else
                    {
                        cout << endl << endl << "Ha ocurrido un error inesperado, el dato no fue eliminado" << endl;
                    }
                }
                else
                {
                    cout << endl << endl << "Ningun contacto fue eliminado" << endl << endl;
                    cin.get();
                    break;
                }
                break;
            default:

                break;
            }

           
            break;
            case 5:
                cout << endl << endl << "--------- Buscar contactos ---------" << endl << endl;

                cout << "Introduce el nombre o la inicial del usuario a buscar: ";
                cin >> query;
                cout << endl << endl;
                if (query.size() > 1)
                {
                    result = Agenda->First([query](Contacto* cont) {return  ToLower(cont->Nombre) == ToLower(query); });

                    if (result != NULL)
                    {
                        cout << endl << endl << "Contacto encontrado " << endl << endl;
                        cout << result << endl;
                    }
                    else
                    {
                        cout << endl <<endl <<" Ningun dato encontrado con el nombre \"" << query << "\"" << endl << endl;
                    }

                }
                
                else
                {
                    if (query.size() == 1)
                    {

                        filter = Agenda->Where([query](Contacto* cont) {return tolower(cont->Nombre[0]) == tolower(query[0]); });

                        if (filter->Count() > 0)
                        {
                            cout << endl << endl << "Contactos  encontrados " << endl << endl;
                            cout << filter << endl;
                        }
                        else
                        {
                            cout << endl << endl << " Ningun contacto encontrado con la inicial \""<<query<<"\"" << endl << endl;
                        }
                    }
                    else
                    {
                        cout << endl << endl << "No se introdujo ningun caracter" << endl << endl;
                    }
                       
                }
                
              



                break;

        }

        cin.get();
        cin.get();


    }while (opc != 0);

};






        // auto result =  Agenda->Where([comparador](Contacto* cont) {return  cont->FNacimiento == comparador; });











    




// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
