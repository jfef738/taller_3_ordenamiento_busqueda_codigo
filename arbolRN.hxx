#include "arbolRN.h"

template <class T>
arbolRN<T>::arbolRN() {}

template <class T>
arbolRN<T>::~arbolRN() {}

template <class T>
bool arbolRN<T>::insertar(const T& v) {
    std::pair<typename std::set<T>::iterator,bool> r = arbol.insert(v);
    return r.second;
}

template <class T>
bool arbolRN<T>::eliminar(const T& v) {
    return arbol.erase(v) > 0;
}

template <class T>
bool arbolRN<T>::buscar(const T& v) const {
    return arbol.find(v) != arbol.end();
}

template <class T>
std::size_t arbolRN<T>::tamano() const {
    return arbol.size();
}

template <class T>
void arbolRN<T>::InOrden(std::list<T>& lista) const {
    typename std::set<T>::const_iterator it = arbol.begin();
    for ( ; it != arbol.end(); ++it) {
        lista.push_back(*it);
    }
}