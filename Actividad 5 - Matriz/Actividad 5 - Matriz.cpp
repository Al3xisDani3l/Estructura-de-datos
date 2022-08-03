// Actividad 5 - Matriz.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

class Matriz
{
public:

	void Fill() {
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				_matriz[i][j] = rand() % 10;
			}
		}
	}

	void Show() {
		for (size_t i = 0; i < 3; i++)
		{
			cout << endl;
			for (size_t j = 0; j < 4; j++)
			{
				cout <<setw(3)<< _matriz[i][j] <<" ";
			}
			cout << endl;
		}
	}

	void MultiplicacionEscalar(int x) {
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				_MatrizMultiplicada[i][j] = x * _matriz[i][j];

			}
		}
		_Show(_MatrizMultiplicada);
	}

	void Transpuesta() {

		for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				_matrizTranspuesta[j][i] = _MatrizMultiplicada[i][j];
			}
		}

		cout << endl;
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 3; j++)
			{
				cout << setw(3)  << _matrizTranspuesta[i][j]<<" ";
			}
			cout << endl;
		}


	}



	Matriz();
	~Matriz();

private:

	int _matriz[3][4];
	int _MatrizMultiplicada[3][4];
	int _matrizTranspuesta[4][3];

	void _Show(int matriz[3][4]) {
		cout << endl;
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				cout << setw(3)<< matriz[i][j] << " ";
			}
			cout << endl;
		}
	}



};



int main()
{
    srand(time(NULL));

	Matriz* _matriz = new Matriz();
	int escalar;
	 
	_matriz->Fill();
	cout << "<<Matriz Rellenada>>" << endl;
	_matriz->Show();
	cout << "Introduce un numero para multiplicar la matriz entera" << endl;
	cin >> escalar;
	cout << "<<Matriz Multiplicada>>" << endl;
	_matriz->MultiplicacionEscalar(escalar);
	cout << "<<Matriz transpuesta de la matriz multiplicada>>";
	_matriz->Transpuesta();

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
