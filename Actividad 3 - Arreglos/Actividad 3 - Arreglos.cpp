// Actividad 3 - Arreglos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

char letras[200];
int repeticiones[27];

void fill() {
	for (size_t i = 0; i < 200; i++)
	{
		int random = (97 + rand() % (123 - 97));
		letras[i] = (char)random;
	}
}

void print() {

	for (size_t i = 0; i < 200; i++)
	{
		cout << "Letra: " << letras[i] << endl;
	}
}

void findLetter(char l) {

	int cont = 0;
	if (l >= 97 && l <= 122)
	{
		for (size_t i = 0; i < 200; i++)
		{
			if (letras[i] == l)
			{
				cout << "Letra " << l << " encontrada en la posicion: " << i << endl;
				cont++;
			}

		}
		if (cont == 0)
		{
			cout << "No se encontro la letra " << l << " en el arreglo" << endl;
		}
		
	}
	else
	{
		cout << "No es una letra minuscula, por lo tanto no se encuentra en esta lista" << endl;
	}
}

void Repeticiones() {

	for (size_t i = 0; i < 27; i++)
	{
		repeticiones[i] == 0;
	}

	for (size_t i = 0; i < 200; i++)
	{
		repeticiones[letras[i] - 'a'] ++;
	}

	for (size_t x = 0; x < 26; x++)
	{
		
		cout << (char)(x + 'a') << ": " << repeticiones[x] << " repeticiones" << endl;
		
	}
}

// 97 -- 122
int main()
{
	char busqueda;
	


    srand(time(NULL));
	fill();
	print();
	cout << endl<< endl;

	cout << "Introduce una letra minuscula a buscar " << endl;
	cin >> busqueda;

	findLetter(busqueda);
	cout << endl << endl;
	Repeticiones();



    
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
