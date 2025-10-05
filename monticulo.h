#ifndef __MONTICULO_H__
#define __MONTICULO_H__

#include <vector>
#include <list>
#include <algorithm>

template <class T>
class Monticulo
{
private:
    std::vector<T> heap; // Contenedor para almacenar los elementos del montículo

public:
    Monticulo();                         // Constructor
    void insertar(const T &val);         // Inserta un elemento en el montículo
    void eliminar(const T &val);         // Elimina un elemento específico del montículo
    const T &obtenerRaiz() const;        // Devuelve la raíz del montículo
    bool esVacio() const;                // Verifica si el montículo está vacío
    void inorden(std::list<T> &lista) const; // Genera un recorrido inorden y lo guarda en una lista
};

#include "monticulo.hxx"

#endif