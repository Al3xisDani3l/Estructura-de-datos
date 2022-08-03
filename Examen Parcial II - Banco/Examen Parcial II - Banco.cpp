//Examen Parcial II - Banco.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//Alexis Daniel Hernandez Gamez
//Matricula: 180263
//Fecha: 20/04/2021


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <wchar.h>
#include <locale.h>
#include <windows.h>
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
    Lista<T>* Delete(Func func) {

        Lista<T>* auxLista = new Lista<T>;


        for (size_t i = 0; i < _count; i++)
        {
            T dato = Get(i);
            if (!func(dato))
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

#pragma region Fecha

struct Fecha
{

    Fecha() {

        Fecha ac = Now();

        year = ac.year;

        Mes = ac.Mes;

        Dia = ac.Dia;

        Hora = ac.Hora;

        Minutos = ac.Minutos;

        Segundos = ac.Segundos;
    }

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

    Fecha Now() {
        auto t = time(NULL);

        tm* timePtr = localtime(&t);





        int year = timePtr->tm_year + 1900;

        int mes = timePtr->tm_mon + 1;

        int day = timePtr->tm_mday;



        Fecha f(day, mes, year);

        f.Hora = timePtr->tm_hour;
        f.Minutos = timePtr->tm_min;
        f.Segundos = timePtr->tm_sec;

        return f;


    }

public:
    size_t year;
    size_t Mes;
    size_t Dia;
    size_t Hora;
    size_t Minutos;
    size_t Segundos;

    string ToString() {

        string formato = std::to_string(Dia) + "-" + to_string(Mes) + "-" + to_string(year) + "  " + to_string(Hora) + ":" + to_string(Minutos) + ":" + to_string(Segundos);

        return formato;


    };






};

bool operator ==(const Fecha& f1, const Fecha& f2) {

    return f1.year == f2.year && f1.Mes == f2.Mes && f1.Dia == f2.Dia;


}


bool operator <(const Fecha& f1, const Fecha& f2) {


    if (f1.year < f2.year)
    {
        return true;
    }

    if (f1.Mes < f2.Mes)
    {
        return true;
    }
    if (f1.Dia < f2.Dia)
    {
        return true;
    }

    return false;


}

bool operator >(const Fecha& f1, const Fecha& f2) {


    if (f1.year > f2.year)
    {
        return true;
    }

    if (f1.Mes > f2.Mes)
    {
        return true;
    }
    if (f1.Dia > f2.Dia)
    {
        return true;
    }

    return false;


}

bool operator <=(const Fecha& f1, const Fecha& f2) {



    return f1 == f2 || f1 < f2;


}

bool operator >=(const Fecha& f1, const Fecha& f2) {

    return f1 == f2 || f1 > f2;
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

#pragma endregion




#pragma region Estructuras

enum class Entidad
{
    Salir,
    Debito,
    Credito


};

enum class Options
{
    Salir,
    Consultar,
    Retirar,
    Depositar,
    Eliminar,
    Historial

};

enum TransaccionType
{
    Consulta = 1,
    Retiro,
    Deposito,




};



struct Transaccion
{
    Transaccion(TransaccionType type, size_t amount) :Transaccion(type, "", amount, Fecha()) {};

    Transaccion(TransaccionType type, string informacionA) :Transaccion(type, informacionA, 0, Fecha()) {};

    Transaccion(TransaccionType type, string informacionA, size_t amount, Fecha f) {
        Type = type;
        InformacionAdicional = informacionA;
        Amount = amount;
        FechaDeRealizacion = f;


    }

    TransaccionType Type;

    size_t Amount;

    string InformacionAdicional;

    Fecha FechaDeRealizacion;

    string ToString() {



        string cadena = "-----------";


        switch (Type)
        {
        case TransaccionType::Consulta:
            cadena += "Consulta-------------\n";

            if (InformacionAdicional.size() > 0)
            {

                cadena += InformacionAdicional;
                cadena += "\n";
            }
            else
            {
                cadena += "Cantidad de dinero Actualmente: -" + to_string(Amount) + " MXN\n";
                cadena += "\nFecha de realizacion: " + FechaDeRealizacion.ToString() + "\n";
            }

            break;
        case TransaccionType::Retiro:

            cadena += "-Retiro--------------\n";

            if (InformacionAdicional.size() > 0)
            {

                cadena += InformacionAdicional;
                cadena += "\n";
            }
            else
            {
                cadena += "Cantidad de dinero retirado: -" + to_string(Amount) + " MXN\n";
                cadena += "\nFecha de realizacion: " + FechaDeRealizacion.ToString() + "\n";
            }



            break;
        case TransaccionType::Deposito:
            cadena += "Deposito-------------\n";
            if (InformacionAdicional.size() > 0)
            {

                cadena += InformacionAdicional;
                cadena += "\n";
            }
            else
            {
                cadena += "Cantidad de dinero depositado: " + to_string(Amount) + " MXN\n";
                cadena += "\nFecha de realizacion: " + FechaDeRealizacion.ToString() + "\n";
            }

            break;
        default:
            break;
        }






        return cadena;
    }



};

struct BancOperation
{
public:

    BancOperation(Entidad enty = Entidad::Debito) {

        type = enty;

        switch (type)
        {
        case Entidad::Debito:
            Saldo = 2500;
            break;
        case Entidad::Credito:
            CreditoTotal = 10000;
            Saldo = 2500;
            break;
        default:
            type = Entidad::Debito;
            Saldo = 2500;
            break;
        }

        _historial = new Lista<Transaccion*>();
    }

    ~BancOperation() {
        _historial->clear();
        delete(_historial);
    }

    virtual void consultar() {






        Fecha f;

        cout << "\t\t\tConsulta de saldo\n\n";

        string info;

        switch (type)
        {
        case Entidad::Debito:
            info = "Fecha: " + f.ToString() + "\nSaldo disponible: " + to_string(Saldo) + " MXN";

            cout << info;
            break;
        case Entidad::Credito:
            info = "Fecha: " + f.ToString() + "\nSaldo Total: " + to_string(CreditoTotal) + " MXN\n" +
                "Saldo disponible: " + to_string(CreditoTotal - Saldo) + " MXN\n" +
                "Deuda a pagar: " + to_string(Saldo) + " MXN\n";
            ;

            cout << info;
            break;
        default:
            break;
        }



        Transaccion* con = new Transaccion(Consulta, "Consulta de saldo:\n" + info, Saldo, f);

        this->_historial->Add(con);

    }

    virtual void Retirar() {

        size_t monto;

        bool validation = false;

        cout << "\t\t\tRetiro de efectivo\n\n";

        do
        {
            validation = false;

            cout << "Monto a retirar: ";
            cin >> monto;
            cout << endl;



            if (type == Entidad::Debito && monto % 50 != 0)
            {
                cout << "\n La cantidad a retirar debe se multiplo de 50!\n";
                getchar();
                getchar();
                validation = true;
            }
            else if (type == Entidad::Debito && Saldo - (int)monto < 0) {
                cout << "\n La cantidad a retirar supera su saldo actual!\n";
                getchar();
                getchar();
                validation = true;
            }
            else if (type == Entidad::Credito && ((CreditoTotal - Saldo) - (int)monto) < 0) {
                cout << "\n La cantidad a retirar supera el credito disponible!\n";
                getchar();
                getchar();
                validation = true;
            }




        } while (validation);


        Fecha f;

        string info = "";

        switch (type)
        {
        case Entidad::Debito:
            Saldo -= monto;

            info = "Fecha: " + f.ToString() + "\nSaldo retirado: " + to_string(monto) + " MXN";
            info += "\nSaldo disponible: " + to_string(Saldo) + " MXN";
            break;
        case Entidad::Credito:
            Saldo += monto;
            info = "Fecha: " + f.ToString() + "\nSaldo retirado: " + to_string(monto) + " MXN";
            info += "\nCredito disponible: " + to_string(CreditoTotal - Saldo) + " MXN";
            break;
        default:
            break;
        }





        cout << info;

        this->_historial->Add(new Transaccion(Retiro, info, monto, f));



    }

    virtual  void Depositar() {

        size_t monto;

        bool validation = false;

        cout << "\t\t\tDeposito de efectivo\n\n";

        do
        {
            validation = false;

            cout << "Monto a depositar: ";
            cin >> monto;
            cout << endl;




        } while (validation);


        Fecha f;

        string info = "";


        switch (type)
        {
        case Entidad::Debito:
            Saldo += monto;

            info = "Fecha: " + f.ToString() + "\nSaldo depositado: " + to_string(monto) + " MXN";
            info += "\nSaldo disponible: " + to_string(Saldo) + " MXN";
            break;
        case Entidad::Credito:
            if (Saldo - (int)monto < 0)
            {
                int cambio = Saldo - (int)monto;

                info = "Fecha: " + f.ToString() + "\nSaldo Abonado: " + to_string(monto) + " MXN";
                info += "\nCredito disponible: " + to_string(CreditoTotal) + " MXN";
                info += "\nCambio: " + to_string(-cambio) + " MXN";
                Saldo = 0;
                _historial->clear();
                break;
            }
            if (Saldo - monto == 0)
            {
                Saldo -= monto;
                info = "Fecha: " + f.ToString() + "\nSaldo Abonado: " + to_string(monto) + " MXN";
                info += "\nCredito disponible: " + to_string(CreditoTotal - Saldo) + " MXN";
                info += "\nEnhora buena tu credito esta pagado, eliminaremos el historial de este mes, buen trabajo";
                _historial->clear();
                break;

            }
            Saldo -= monto;
            info = "Fecha: " + f.ToString() + "\nSaldo Abonado: " + to_string(monto) + " MXN";
            info += "\nCredito disponible: " + to_string(CreditoTotal - Saldo) + " MXN";
            break;
        default:
            break;
        }





        cout << info;

        this->_historial->Add(new Transaccion(Deposito, info, monto, f));
    }

    virtual void Eliminar() {


        size_t monto;

        TransaccionType tran;
        TransaccionType quer;

        Fecha f1;

        Fecha f2;

        bool validation = false;

        int opc;
        int cant;

        cout << "\t\t\tEliminar registros\n\n";

        cout << "Eliminar por monto: 1" << endl;
        cout << "Eliminar por tipo de transaccion: 2" << endl;
        cout << "Eliminar por Rango de fechas: 3" << endl;
        cout << "Eliminar todo: 4" << endl;
        cout << "Cancelar operacion: 0" << endl;
        cin >> opc;

        switch (opc)
        {
        case 1:

            cout << endl << endl << "Introduce el monto a eliminar:";
            cin >> monto;
            cant = _historial->Count();
          _historial = _historial->Delete([monto](Transaccion* t) { return t->Amount == monto; });

           cout << endl << cant << " registros eliminados!\n";
            break;
        case 2:
            cout << endl << endl << "Introduce el tipo de transaccion a eliminar:" << endl;
            cout<<"Consulta : 1"<<endl;
            cout<<"Retiro : 2"<<endl;
            cout << "Deposito : 3" << endl;
            cout << "Cancelar : 0" << endl;
            cin >> monto;

            if (monto == 0 || monto > 3)
            {
                break;
            }

            quer = (TransaccionType)monto;
            cant = _historial->Count();
            _historial = _historial->Delete([quer](Transaccion* t) { return t->Type == quer; });

            cout << endl << cant - _historial->Count() << " registros eliminados!\n";



            break;
        case 3:
            cout << endl << endl << "Introduce el rango de fecha a eliminar:" << endl;
            cout << "Desde: ";
            cin >> f1;
            cout << endl;
            cout << "Hasta: ";
            cin >> f1;

            cant = _historial->Count();
            _historial = _historial->Delete([f1,f2](Transaccion* t) { return t->FechaDeRealizacion >= f1 || t->FechaDeRealizacion <= f2; });

            cout << endl << cant - _historial->Count() << " registros eliminados!\n";

            break;
        case 4:
            cout << endl << endl << "Se eliminaran todos los registros y se reiniciaran las cuentas!" << endl;

            cout << endl << _historial->Count() << " registros eliminados!\n";

            _historial->clear();

            if (type == Entidad::Credito)
            {
                this->CreditoTotal = 10000;
                this->Saldo = 0;
            }

            break;

        default:
            break;

            getchar();
            getchar();
            system("cls");
            break;
        }
       
    }

    virtual void Historial() {
        cout <<endl <<"           Historial\n\n";
        cout << _historial;
    }



private:


protected:

    int Saldo;
    int CreditoTotal;

    Entidad type;
    Lista<Transaccion*>* _historial;
};

struct Cliente
{
    Cliente() {
        Credito = new BancOperation(Entidad::Credito);
        Debito = new BancOperation();
    }

    BancOperation* Debito;
    BancOperation* Credito;

};


#pragma endregion

#pragma region Sobrecargas





ostream& operator << (ostream& o, Transaccion* t) {

    o << t->ToString();
    return o;
}

#pragma endregion


int main()
{
    setlocale(LC_ALL, "spanish"); // Cambiar locale - Suficiente para máquinas Linux
    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows

    locale::global(locale("spanish"));

    Cliente _cliente;

    

    int dato = 0, opci = 0, pos = 0, opcE = 0;
    int posi = 0;
    string query;
    Options opc = Options::Salir;
    Entidad ent = Entidad::Salir;
   


    do
    {
        system("cls");

        cout << endl << "       Bienvenido!" << endl << endl;
        cout << " ¿En que entidad desea operar?" << endl << endl;
        cout << "Debito : 1" << endl << "Credito : 2"<<endl << "Salir : 0" <<endl << endl <<"Opcion: ";
        cin >> opci;

        ent = (Entidad)opci;

        switch (ent)
        {
        case Entidad::Salir:
            break;
        case Entidad::Debito:

            do
            {
                system("cls");

                cout << endl << endl << "---------Targeta de debito-------" << endl << endl;
            
                cout << "Consultar : " << (int)Options::Consultar << endl;
                cout << "Retirar : " << (int)Options::Retirar << endl;
                cout << "Depositar : " << (int)Options::Depositar << endl;
                cout << "Eliminar : " << (int)Options::Eliminar << endl;
                cout << "Historial : " << (int)Options::Historial << endl;
                cout << "Salir : " << (int)Options::Salir << endl << endl;
               
                cout << "Opcion: ";
                cin >> opci;

                opc = (Options)opci;


                switch (opc)
                {
                case Options::Salir:
                    break;
                case Options::Consultar:

                    _cliente.Debito->consultar();

                    break;
                case Options::Retirar:
                    _cliente.Debito->Retirar();
                    break;
                case Options::Depositar:
                    _cliente.Debito->Depositar();
                    break;
                case Options::Eliminar:
                    _cliente.Debito->Eliminar();
                    break;
                case Options::Historial:
                    _cliente.Debito->Historial();
                    break;
                default:
                    break;
                }


                getchar();
                getchar();


            } while (opc != Options::Salir);
            break;
        case Entidad::Credito:
            do
            {
                system("cls");

                cout << endl << endl << "---------Targeta de Credito-------" << endl << endl;

                cout << "Consultar : " << (int)Options::Consultar << endl;
                cout << "Retirar : " << (int)Options::Retirar << endl;
                cout << "Depositar : " << (int)Options::Depositar << endl;
                cout << "Eliminar : " << (int)Options::Eliminar << endl;
                cout << "Historial : " << (int)Options::Historial << endl;
                cout << "Salir : " << (int)Options::Salir << endl << endl;

                cout << "Opcion: ";
                cin >> opci;

                opc = (Options)opci;


                switch (opc)
                {
                case Options::Salir:
                    break;
                case Options::Consultar:

                    _cliente.Credito->consultar();

                    break;
                case Options::Retirar:
                    _cliente.Credito->Retirar();
                    break;
                case Options::Depositar:
                    _cliente.Credito->Depositar();
                    break;
                case Options::Eliminar:
                    _cliente.Credito->Eliminar();
                    break;
                case Options::Historial:
                    _cliente.Credito->Historial();
                    break;
                default:
                    break;
                }


                getchar();
                getchar();

            } while (opc != Options::Salir);
            break;
        default:
            break;
        }




        




    } while (ent!= Entidad::Salir);


}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto,vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
