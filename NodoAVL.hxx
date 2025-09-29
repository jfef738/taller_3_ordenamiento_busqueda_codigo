template< class T >
NodoAVL<T>::NodoAVL(){
    this->hijoIzq = nullptr;
    this->hijoDer = nullptr;
}

template< class T >
NodoAVL<T>::NodoAVL(T val){
    this->dato = val;
    this->hijoIzq = nullptr;
    this->hijoDer = nullptr;
}

template< class T >
NodoAVL<T>::~NodoAVL(){
        this->hijoIzq = nullptr;
        this->hijoDer = nullptr;
}

template< class T >
T NodoAVL<T>::obtenerDato(){
    return this->dato;
}

template< class T >
void NodoAVL<T>::fijarDato(T val){
    this->dato = val;
}

template< class T >
NodoAVL<T>* NodoAVL<T>::obtenerHijoIzq(){
    return this->hijoIzq;
}

template< class T >
NodoAVL<T>* NodoAVL<T>::obtenerHijoDer(){
    return this->hijoDer;
}

template< class T >
void NodoAVL<T>::fijarHijoIzq(NodoAVL<T>* izq){
    this->hijoIzq = izq;
}

template< class T >
void NodoAVL<T>::fijarHijoDer(NodoAVL<T>* der){
    this->hijoDer = der;
}

template< class T >
bool NodoAVL<T>::esHoja(){
    return (this->hijoIzq == nullptr && this->hijoDer == nullptr);
}