#ifndef __ARBOLRN_H__
#define __ARBOLRN_H__

#include <set>
#include <list>

template <class T>
class arbolRN {
private:
    std::set<T> arbol;              // Implementado como árbol rojinegro (std::set)
public:
    arbolRN();
    ~arbolRN();

    bool insertar(const T& v);
    bool eliminar(const T& v);
    bool buscar(const T& v) const;
    std::size_t tamano() const;

    void InOrden(std::list<T>& lista) const;       // Recorre y guarda (inorden natural del set)
};

#include "arbolRN.hxx"

#endif