// Proyecto FInal.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Alexis Daniel Hernandez Gamez - 180263
// Genesis Erisel Arteaga Rangel - 182129


#include "myPila.h"
#include "Cola.h"
#include "ListaSencilla.h"
#include "ListaDoble.h"
#include "ArbolBinario.h"
#include "Grafo.h"
#include <iostream>
#include <random>


#define SIZE 20

using namespace std;

int numeros[SIZE];

void fill(int* num, int size);

int main()
{
    srand(time(NULL));

    //Rellenamos con numeros aleatorios 
    fill(numeros, SIZE);

    int opc;

    do
    {
        system("cls");
        cout << endl << "           Menu de opciones" << endl <<endl<<
            "  Metodo de desplazamiento " << endl <<
            "1 Cifrado " << endl <<
            "2 Desifrado" << endl <<
            "  Metodo de desplazamiento" << endl <<
            "3 Cifrado" << endl <<
            "4 Desifrado" << endl <<
            
            "0 Salir" << endl << endl;
        cout << "Opcion: ";
        cin >> opc;

        switch (opc)
        {
        case 1://pila
            PilaInit(numeros, SIZE);
            break;
        case 2://cola
            ColaInit(numeros, SIZE);
            break;
        case 3://lista sencilla
            ListaSencillaInit(numeros, SIZE);
            break;
        case 4://lista doble
            ListaDobleInit(numeros, SIZE);
            break;
        case 5://arbol
            ArbolBinarioInit(numeros, SIZE);
            break; 
        case 6://grafo
            GrafoInit(numeros, SIZE);
            break;
        case 0:
            cout << endl << "Saliendo..." << endl;
            break;
        default:
            break;
        }


    } while (opc != 0);





    
}



void fill(int* num, int size) {

    for (size_t i = 0; i < size; i++)
    {
        num[i] = rand() % 100 + 1;
    }
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
