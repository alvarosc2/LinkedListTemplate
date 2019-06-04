//nodoLista.h
//Definición de la plantilla de clase nodoLista.
#ifndef NODOLISTA_H
#define NODOLISTA_H

//Declaración anticipada de la clase Lista
template<class TIPONODO>class Lista;

template<class TIPONODO>
class NodoLista
{
	friend class Lista<TIPONODO>;
	
	public:
		NodoLista(const TIPONODO &);
		TIPONODO obtenerDatos() const;
		
	private:
		TIPONODO datos;
		NodoLista<TIPONODO> *siguientePtr;
};

template<class TIPONODO>
NodoLista<TIPONODO>::NodoLista(const TIPONODO &info):datos(info), siguientePtr(0)
{
	//cuerpo vacio
}

template<class TIPONODO>
TIPONODO NodoLista<TIPONODO>::obtenerDatos() const
{
	return datos;
}

#endif
