#include "monticulo.h"

template <class T>
Monticulo<T>::Monticulo() : heap() {}

template <class T>
void Monticulo<T>::insertar(const T &val)
{
    // Insertar SIN duplicados y manteniendo orden
    typename std::vector<T>::iterator it = std::lower_bound(heap.begin(), heap.end(), val);
    if (it == heap.end() || *it != val) {
        heap.insert(it, val);
    }
}

template <class T>
void Monticulo<T>::eliminar(const T &val)
{
    // Borrar si existe (una vez)
    typename std::vector<T>::iterator it = std::lower_bound(heap.begin(), heap.end(), val);
    if (it != heap.end() && *it == val) {
        heap.erase(it);
    }
}

template <class T>
const T &Monticulo<T>::obtenerRaiz() const
{
    return heap.front();
}

template <class T>
bool Monticulo<T>::esVacio() const
{
    return heap.empty();
}

template <class T>
void Monticulo<T>::inorden(std::list<T> &lista) const
{
    lista.clear();
    lista.insert(lista.end(), heap.begin(), heap.end());
}

// eof - monticulo.hxx