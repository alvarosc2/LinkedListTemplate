//lista.h
//Definición de la plantilla de clase Lista.
#ifndef LISTA_H
#define LISTA_H

#include <iostream>

using std::cout;

#include <new>
#include "nodolista.h"

template<class TIPONODO>
class Lista
{
	public:
		Lista();
		~Lista();
		void insertarAlFrente(const TIPONODO &);
		void insertarAlFinal(const TIPONODO &);
		bool quitarDelFrente(TIPONODO &);
		bool quitarDelFinal(TIPONODO &);
		bool estaVacia() const;
		void imprimir() const;
		
	private:
		NodoLista<TIPONODO> *primerPtr; //apuntador al primer nodo
		NodoLista<TIPONODO> *ultimoPtr;	//apuntador al ultimo nodo
		//función de utiliería para asignar nuevo nodo
		NodoLista<TIPONODO> *obtenerNuevoNodo(const TIPONODO &);
};

template<class TIPONODO>
Lista<TIPONODO>::Lista():primerPtr(0), ultimoPtr(0)
{
	//cuerpo vacio
}

template<class TIPONODO>
Lista<TIPONODO>::~Lista()
{
	if (!estaVacia())
	{
		cout << "Destruyendo nodos ...\n";
		
		NodoLista<TIPONODO> *actualPtr = primerPtr;
		NodoLista<TIPONODO> *tempPtr;
		
		while (actualPtr != 0) //eliminar nodos restantes
		{
			tempPtr = actualPtr;
			cout << tempPtr->datos << '\n';
			actualPtr = actualPtr->siguientePtr;
			delete tempPtr;
		}
	}
	
	cout << "Se destruyeron todos los nodos\n\n";
}

//insertar nodo en parte frontal de la lista
template<class TIPONODO>
void Lista<TIPONODO>::insertarAlFrente(const TIPONODO &valor)
{
	NodoLista<TIPONODO> *nuevoPtr = obtenerNuevoNodo(valor);
	
	if (estaVacia()) //Lista está vacía
		primerPtr = ultimoPtr = nuevoPtr;
	else //Lista no está vacía
	{
		nuevoPtr->siguientePtr = primerPtr;
		primerPtr = nuevoPtr;
	}
}

//insertar nodo en parte final de la lista
template<class TIPONODO>
void Lista<TIPONODO>::insertarAlFinal(const TIPONODO &valor)
{
	NodoLista<TIPONODO> *nuevoPtr = obtenerNuevoNodo(valor);
	
	if (estaVacia()) //la lista esta vacía
		primerPtr = ultimoPtr = nuevoPtr;
	else //lista no esta vacía
	{
		ultimoPtr->siguientePtr = nuevoPtr;
		ultimoPtr = nuevoPtr;
	}
}

//eliminar nodo de parte forntal de la lista
template<class TIPONODO>
bool Lista<TIPONODO>::quitarDelFrente(TIPONODO &valor)
{
	if (estaVacia())  //Lista está vacía
		return false; //operación delete no exitosa
	else
	{
		NodoLista<TIPONODO> *tempPtr = primerPtr;
		
		if (primerPtr == ultimoPtr)
			primerPtr = ultimoPtr = 0;
		else
			primerPtr = primerPtr->siguientePtr;
		
		valor = tempPtr->datos; //los datos se van a quitar
		delete tempPtr;
		
		return true;
	}
}

//eliminar nodo de parte final de la lista
template<class TIPONODO>
bool Lista<TIPONODO>::quitarDelFinal(TIPONODO &valor)
{
	if (estaVacia())
		return false;
	else
	{
		NodoLista<TIPONODO> *tempPtr = ultimoPtr;
		if(primerPtr == ultimoPtr)
			primerPtr = ultimoPtr = 0;
		else
		{
			NodoLista<TIPONODO> *actualPtr = primerPtr;
			
			//localizar elemento anterior al último
			while (actualPtr->siguientePtr != ultimoPtr)
				actualPtr = actualPtr->siguientePtr;
				
			ultimoPtr = actualPtr;
			actualPtr->siguientePtr = 0;
		}
		
		valor = tempPtr->datos;
		delete tempPtr;
		
		return true;
	}
}

//evaluar si la lista está vacía
template<class TIPONODO>
bool Lista<TIPONODO>::estaVacia() const
{
	return primerPtr == 0;
}

//devolver apuntador a nodo recien asignado
template<class TIPONODO>
NodoLista<TIPONODO> *Lista<TIPONODO>::obtenerNuevoNodo(const TIPONODO &valor)
{
	return new NodoLista<TIPONODO>(valor);
}

//mostrar contenido de Lista
template<class TIPONODO>
void Lista<TIPONODO>::imprimir() const
{
	if (estaVacia())
	{
		cout << "La lista esta vacía\n\n";
		return;
	}
	
	NodoLista<TIPONODO> *actualPtr = primerPtr;
	cout << "La lista es: ";
	
	while (actualPtr != 0)
	{
		cout << actualPtr->datos << ' ';
		actualPtr = actualPtr->siguientePtr;
	}
	
	cout << "\n\n";
}

#endif
