//LinkedList.cpp
//Programa para probar la clase Lista
#include <iostream>

using std::cin;
using std::endl;

#include<string>

using std::string;

#include "lista.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
template<class T>
void probarLista(Lista<T> &objetoLista, const string &nombreTipo);

void instrucciones();

int main(int argc, char** argv) {
	//probar lista de valores integer
	Lista<int>listaInteger;
	probarLista(listaInteger, "integer");
	
	//probar lista de valores double
	Lista<double>listaDouble;
	probarLista(listaDouble, "double");
	
	return 0;
}

//función para probar una Lista
template<class T>
void probarLista(Lista<T> &objetoLista, const string &nombreTipo)
{
	cout << "Probando una lista de valores " << nombreTipo << " \n";
	
	instrucciones();
	
	int opciones;
	T valor;
	
	do
	{
		cout << "? ";
		cin >> opciones;
		
		switch(opciones)
		{
			case 1:
				cout << "Escriba " << nombreTipo << ": ";
				cin >> valor;
				objetoLista.insertarAlFrente(valor);
				objetoLista.imprimir();
				break;
				
			case 2:
				cout << "Escriba " << nombreTipo << ": ";
				cin >> valor;
				objetoLista.insertarAlFinal(valor);
				objetoLista.imprimir();
				break;
				
			case 3:
				if (objetoLista.quitarDelFrente(valor))
					cout << valor << " se quito de la lista\n";
					
				objetoLista.imprimir();
				break;
				
			case 4:
				if (objetoLista.quitarDelFinal(valor))
					cout << valor << " se quito de la lista\n";
									
				objetoLista.imprimir();
				break;
		}
	}while (opciones != 5);
	
	cout << "Fin de prueba de la lista\n\n";
}

//mostrar instrucciones del programa al usuario
void instrucciones()
{
	cout << "Escriba una de las siguiente opciones:\n"
	     << "   1 para insertar en la parte frontal de la lista\n"
	     << "   2 para insertar en la parte final de la lista\n"
	     << "   3 para eliminar de la parte frontal de la lista\n"
	     << "   4 para eliminar de la parte final de la lista\n"
	     << "   5 para finalizar el procesamiento de la lista\n";
}
