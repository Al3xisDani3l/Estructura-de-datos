#pragma once

#include <iostream>
#include "BinaryTree.h"

using namespace std;

template <class T> struct GraphRelation;

template <class T>
struct GraphNode {
	T value;
	GraphNode* next;
	GraphRelation<T>* link;
	bool hasBeenPrinted;
};

template <class T>
struct GraphRelation {
	GraphNode<T>* dest;
	GraphRelation<T>* next;
};

template <class T>
class Graph {
public:
	GraphNode<T>* root;

	Graph() {
		this->root = NULL;
	}

	void Add(T value) {
		GraphNode<T>* aux = NULL;
		GraphNode<T>* newNode = new GraphNode<T>;

		// Inicializar campos.
		newNode->value = value;
		newNode->next = NULL;
		newNode->link = NULL;

		// Realizar si es el primer nodo.
		if (this->root == NULL) {
			this->root = newNode;
			return;
		}

		// Nodo nuevo (no es el primero).
		aux = this->root;
		while (aux->next != NULL) {
			aux = aux->next;
		} // Recorrer hasta el final
		aux->next = newNode;
	}

	void CreateConexion(T start, T end) {
		GraphRelation<T>* newRelation = new GraphRelation<T>;
		GraphNode<T>* aux1;
		GraphNode<T>* aux2;

		if (this->root == NULL) {
			cout << endl << "Grafo vacio..." << endl;
			return;
		}
			

		newRelation->next = NULL;

		aux1 = this->root;
		aux2 = this->root;

		while (aux2 != NULL) {
			if (aux2->value == end) break;
			aux2 = aux2->next;
		}

		if (aux2 == NULL)
			cout<<endl<< "[*] El nodo de fin no existe."<<endl;

		while (aux1 != NULL) {
			if (aux1->value == start) {
				GraphRelation<T>* tmp;

				// Verificar si es la primer arista del nodo.
				if (aux1->link == NULL) {
					aux1->link = newRelation;
					newRelation->dest = aux2;
				}
				else {
					tmp = aux1->link;

					while (tmp->next != NULL) {
						tmp = tmp->next;
					} // Recorrer hasta el final.

					newRelation->dest = aux2;
					tmp->next = newRelation;
				}

				return;
			}

			aux1 = aux1->next;
		}

		
	}

	void Delete(T value) {
		GraphNode<T>* auxI, * auxJ;

		if (this->root == NULL)
			throw "[*] El grafo está vacío.";

		for (auxI = this->root; auxI != NULL; auxI = auxI->next) {
			for (auxJ = this->root; auxJ != NULL; auxJ = auxJ->next) {
				// Eliminar las relaciones que contengan el nodo a eliminar.
				if (auxI->value == value || auxJ->value == value) {
					DeleteConexion(auxI->value, auxJ->value);
				}
			}
		}

		auxI = this->root;

		// Verificar el primer nodo.
		if (auxI->value == value) {
			auxJ = auxI;
			this->root = auxI->next;
			delete auxJ;
		}

		// Recorrer nodos restantes.
		while (auxI != NULL) {
			if (auxI->next == NULL) break; // Nada más por verificar.

			if (auxI->next->value == value) {
				auxJ = auxI->next; // El que se va a eliminar.
				auxI->next = auxJ->next; // Se salta 1.
				delete auxJ;
			}

			auxI = auxI->next;
		}
	}

	void matrix() {
		GraphNode<T>* auxI, * auxJ;
		GraphRelation<T>* auxRel;

		// Print header.
		cout << "  ";
		for (auxI = this->root; auxI != NULL; auxI = auxI->next) {
			cout << auxI->value << " ";
		}
		cout << endl;

		// Print rows;
		for (auxI = this->root; auxI != NULL; auxI = auxI->next) {
			cout << auxI->value << " ";

			// Print columns;
			for (auxJ = this->root; auxJ != NULL; auxJ = auxJ->next) {
				auxRel = auxI->link;

				// Iterate relations list.
				while (auxRel != NULL) {
					if (auxRel->dest == auxJ) {
						// Relation found.
						cout << 1;
						break;
					}

					auxRel = auxRel->next;
				}

				// Check if while loop got to the end.
				if (auxRel == NULL) {
					cout << 0;
				}

				cout << " ";
			}

			cout << endl; // Next row;
		}
	}

	void unprint() {
		for (GraphNode<T>* aux = this->root; aux != NULL; aux = aux->next) {
			aux->hasBeenPrinted = false;
		}

		
	}

	

	void DeleteConexion(T start, T end) {
		GraphNode<T>* aux1;
		GraphRelation<T>* auxRel, * auxRel2;

		if (this->root == NULL)
			throw "[*] El grafo está vacío.";

		aux1 = this->root;

		// Encontrar el nodo de inicio.
		while (aux1 != NULL) {
			if (aux1->value == start) break;
			aux1 = aux1->next;
		}

		if (aux1 == NULL)
			throw "[*] El nodo de inicio no existe.";

		auxRel = aux1->link;

		if (auxRel == NULL) return;

		// Verificar el primer nodo.
		if (auxRel->dest->value == end) {
			// Eliminar relación.
			aux1->link = auxRel->next;
		}

		// Recorrer aristas.
		while (auxRel != NULL) {
			if (auxRel->next == NULL) break; // No hay más por verificar.

			// Verificar el nodo siguiente (conserva acceso al nodo anterior).
			if (auxRel->next->dest->value == end) {
				auxRel2 = auxRel->next; // El que se va a eliminar realmente.
				auxRel->next = auxRel2->next; // El siguiente del siguiente (salta 1).
				delete auxRel2;
			}

			auxRel = auxRel->next;
		}
	}

	void tree() {
		BinaryTree<T>* tree = new BinaryTree<T>();
		unprint();
		newTree(root, tree);

		tree->mostrarArbol();

		delete tree;

	}

	friend ostream& operator<<(ostream& output, const Graph& g) {
		GraphNode<T>* aux = g.root;
		GraphRelation<T>* rel = NULL;

		// El grafo no tiene ningún nodo.
		if (aux == NULL) {
			output << "<empty Graph>";
			return output;
		}

		// Hay nodos en el grafo.
		while (aux != NULL) {
			// Mostrar el nodo.
			output << aux->value;

			// Mostrar relaciones (aristas).
			if (aux->link != NULL) {
				rel = aux->link;

				while (rel != NULL) {
					output << " " << rel->dest->value;
					rel = rel->next;
				}
			}

			aux = aux->next;
			if (aux != NULL) output << endl;
		}

		return output;
	}
	private:
		void tree(GraphNode<T>* root, int offset = 0) {
			GraphRelation<T>* aux;

			// Recorrido de profundidad.
			for (int i = 0; i < offset; i++)
				cout << "  ";
			cout << root->value << endl;

			root->hasBeenPrinted = true;

			for (aux = root->link; aux != NULL; aux = aux->next) {
				if (!aux->dest->hasBeenPrinted) {
					this->tree(aux->dest, offset + 1);
				}
			}
		}
		void newTree(GraphNode<T>* root, BinaryTree<T> * tree) {
			GraphRelation<T>* aux;
			tree->insert(root->value);
			root->hasBeenPrinted = true;

			for (aux = root->link; aux != NULL; aux = aux->next) {
				if (!aux->dest->hasBeenPrinted) {
					this->newTree(aux->dest,tree);
				}
			}

		}

		
};