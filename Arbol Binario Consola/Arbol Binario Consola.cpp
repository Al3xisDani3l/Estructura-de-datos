// Arbol Binario Consola.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//Genesis Erisel Arteaga Rangel - 182129
//Alexis Daniel Hernandez Gamez - 180263



#include "BinaryTree.h"


using namespace std;







int main() {

	BinaryTree<int> arbol;

	
	

	//BinaryTree<int> *arbol = new BinaryTree<int>();
	int opc = 0, numero = 0;

	int ramas = 0, hojas = 0;

	do {
		system("cls");
		cout << endl << endl << "\t\t Arbol Binario" << endl
			<< "\t 1 Insertar nodo" << endl
			<< "\t 2 Mostrar el arbol plano" << endl
			<< "\t 3 Mostrar el arbol jerarquico" << endl
			<< "\t 4 Recorridos de profundidad" << endl
			<< "\t 5 Buscar elemento" << endl
			<< "\t 6 Mostrar altura del árbol" << endl
			<< "\t 7 Contar y mostrar ramas" << endl
			<< "\t 8 Contar y mostrar hojas" << endl
			<< "\t 9 Mostar sub-arbol izquierdo" << endl
			<< "\t 10 Mostar sub-arbol Derecho" << endl
			<< "\t 11 Mostrar Arbol invertir" << endl

			<< "\t 0 Salir/Terminar del programa" << endl;
		cout << "\nIngresa la opcion: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			cout << "\nIngresar el numero: ";
			cin >> numero;
			cout << endl;
			arbol << numero;
			break;
		case 2:
			
			arbol.mostrarArbolPlano();
			getchar();
			getchar();
			break;
		case 3:
			arbol.mostrarArbol();
			getchar();
			getchar();
			break;
		case 4:
			cout << endl << "\t Recorrido In Orden: ";
			arbol.recorridoInOrden();
			cout << endl << "\t Recorrido Pre Orden: ";
			arbol.recorridoPreOrden();
			cout << endl << "\t Recorrido Post Orden: ";
			arbol.recorridoPostOrden();
			getchar();
			getchar();
			break;


		case 5:
			cout << "\nIngresar el numero a buscar: ";
			cin >> numero;
			cout << endl;
			arbol.find(numero);
			getchar();
			getchar();
			
			break;	

		case 6:
			cout << "\nprofundidad :  " << arbol.height();
			getchar();
			getchar();
			break;

		case 7:
			cout << endl;
			ramas = arbol.mostrarRamas();
			cout << "\n" << ramas << " Ramas encontradas!";
			getchar();
			getchar();
			break;

		case 8:
			cout << endl;
			hojas = arbol.mostrarHojas();
			cout << "\n" << hojas << " hojas encontradas!";
			getchar();
			getchar();
			break;
		case 9:

			cout << endl;
			arbol.mostrarSoloIzquierdo();
			getchar();
			getchar();
 
			break;
		case 10:
			cout << endl;
			arbol.mostrarSoloDerecho();
			getchar();
			getchar();
			break;
		case 11:
			cout << endl;
			arbol.arbolEspejo();
			getchar();
			getchar();
			break;

		default:
			cout << "Opcion no disponible..." << endl;
			break;
		}
	

	} while (opc != 0);

	return 0;
}

