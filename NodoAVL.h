#ifndef __NODOAVL_H__
#define __NODOAVL_H__

template< class T >
class NodoAVL {
private:
    T dato;
    NodoAVL<T>* hijoIzq;
    NodoAVL<T>* hijoDer;
public:
    NodoAVL();
    NodoAVL(T val);
    ~NodoAVL();
    T obtenerDato();
    void fijarDato(T val);
    NodoAVL<T>* obtenerHijoIzq();
    NodoAVL<T>* obtenerHijoDer();
    void fijarHijoIzq(NodoAVL<T>* izq);
    void fijarHijoDer(NodoAVL<T>* der);
    bool esHoja();
};

#include "NodoAVL.hxx"

#endif