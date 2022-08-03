// Arreglo_letras.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


#include <iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

char letras[150];
int repeticiones[27];

void rellenar() {
	for (int i = 0; i < 150; i++)
	{
		int random = (97 + rand() % (26));
		letras[i] = (char)random;
	}
}
void Encontrar(char letra) {

	int cont = 0;
	cout << "La letra" << letra << " esta en esta posicion:";
	if (letra >= 97 && letra <= 122)
	{
		for (int i = 0; i < 150; i++)
		{
			if (letras[i] == letra)
			{
				cout << " "<< i ;
				cont++;
			}

		}
		if (cont == 0)
		{
			cout << "No hay ninguna letra encontrada" << endl;
		}

	}
	else
	{
		cout << "Este caracter no es valido" << endl;
	}
}
void Repeticiones() {

	for (int i = 0; i < 27; i++)
	{
		repeticiones[i] == 0;
	}

	for (int i = 0; i < 150; i++)
	{
		repeticiones[letras[i] - 'a'] ++;
	}

	for (int x = 0; x < 26; x++)
	{

		cout << (char)(x + 'a') << ": " << repeticiones[x] << " numero de letras repetidas" << endl;

	}
}
void Imprimir() {
	cout << "Letra: ";
	for (int i = 0; i < 150; i++)
	{
		cout << " "<<letras[i];
	}
}

int main()
{
	char busqueda;
	srand(time(NULL));
	rellenar();
	Imprimir();
	cout << endl << endl;

	cout << "Introduce una letra minuscula " << endl;
	cin >> busqueda;

	Encontrar(busqueda);
	cout << endl << endl;
	Repeticiones();




}

