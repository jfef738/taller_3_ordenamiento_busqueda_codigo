/*
  --------------------------------
  Taller 3: Comparación de árboles
  --------------------------------
  Clase de Estructuras de Datos
  Modificado por: Ing. Alejandro Castro Martinez
  Pontificia Universidad Javeriana
  Bogotá, Colombia
*/

#include <ctime>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>
#include <iomanip> // std::setw, std::fixed, std::setprecision

// TODO #01: Incluir cabecera de la implementación propia del árbol AVL
#include "ArbolAVL.h"

// TODO #06: Incluir cabecera de la STL correspondiente al árbol rojinegro
#include "arbolRN.h"

// TODO #11: Incluir cabecera de la STL correspondiente al montículo
// #include "monticulo.h"

typedef std::list<std::string> TList;

// TODO #02: Definir árbol AVL de tipo std::string
typedef ArbolAVL<std::string> TAVL;

// TODO #07: Definir árbol rojinegro de tipo std::string
typedef arbolRN< std::string > TRN;

// TODO #12: Definir Montículo de tipo std::string
// typedef monticulo< std::string > THeap;

struct ReadStats
{
  std::size_t ops_total = 0;
  std::size_t ops_add = 0;
  std::size_t ops_del = 0;
  double secs_total = 0.0;
  double secs_add = 0.0;
  double secs_del = 0.0;
};

template <class TArbol>
bool LeerArbol(TArbol &arbol, const std::string &nomArch, bool medirCadaOperacion, ReadStats &stats);

static inline double to_ms(double seconds) { return seconds * 1000.0; }

void ImprimirResumen(const std::string &titulo, const ReadStats &s, bool detalle)
{
  std::cout << "\n============================================================\n";
  std::cout << " " << titulo << "\n";
  std::cout << "------------------------------------------------------------\n";
  std::cout << std::fixed << std::setprecision(3);

  std::cout << " Operaciones procesadas : " << s.ops_total << "\n";
  std::cout << " Tiempo TOTAL           : " << to_ms(s.secs_total) << " ms\n";

  if (detalle)
  {
    std::cout << "------------------------------------------------------------\n";
    std::cout << " Detalle por operación:\n";
    std::cout << "   add -> " << std::setw(6) << s.ops_add
              << " ops | " << std::setw(9) << to_ms(s.secs_add) << " ms";
    if (s.ops_add)
    {
      std::cout << " | promedio: " << to_ms(s.secs_add / double(s.ops_add)) << " ms/op";
    }
    std::cout << "\n";

    std::cout << "   del -> " << std::setw(6) << s.ops_del
              << " ops | " << std::setw(9) << to_ms(s.secs_del) << " ms";
    if (s.ops_del)
    {
      std::cout << " | promedio: " << to_ms(s.secs_del / double(s.ops_del)) << " ms/op";
    }
    std::cout << "\n";
  }
  std::cout << "============================================================\n";
}

int main(int argc, char *argv[])
{
  if (argc < 3)
  {
    std::cerr << "Uso: " << argv[0] << " archivo_entrada  Y|N\n";
    return (-1);
  }

  const std::string archivo = argv[1];
  const char modo = std::toupper(static_cast<unsigned char>(argv[2][0]));
  if (modo != 'Y' && modo != 'N')
  {
    std::cerr << "Error: el segundo parametro debe ser 'Y' o 'N'.\n";
    return (-1);
  }
  const bool medirCadaOperacion = (modo == 'Y');

  // TODO #03: Definir variable tipo árbol AVL.
  TAVL miArbolAVL;

  // TODO #08: Definir variable tipo árbol rojinegro.
  TRN miArbolRN;

  // TODO #13: Definir variable tipo Montículo.
  // THeap miMonticulo;

  ReadStats statsAVL;
  std::chrono::steady_clock::time_point t0AVL = std::chrono::steady_clock::now();
  bool lecturaAVL = LeerArbol(miArbolAVL, archivo, medirCadaOperacion, statsAVL);
  std::chrono::steady_clock::time_point t1AVL = std::chrono::steady_clock::now();
  double tiempoLecturaAVL = std::chrono::duration<double>(t1AVL - t0AVL).count();
  statsAVL.secs_total = tiempoLecturaAVL;

  ReadStats statsRN;
  std::chrono::steady_clock::time_point t0RN = std::chrono::steady_clock::now();
  bool lecturaRN = LeerArbol(miArbolRN, archivo, medirCadaOperacion, statsRN);
  std::chrono::steady_clock::time_point t1RN = std::chrono::steady_clock::now();
  double tiempoLecturaRN = std::chrono::duration<double>(t1RN - t0RN).count();
  statsRN.secs_total = tiempoLecturaRN;

  ReadStats statsHeap;
  std::chrono::steady_clock::time_point t0Heap = std::chrono::steady_clock::now();
  // bool lecturaHeap = LeerArbol(miMonticulo, archivo, medirCadaOperacion, statsHeap);
  std::chrono::steady_clock::time_point t1Heap = std::chrono::steady_clock::now();
  double tiempoLecturaHeap = std::chrono::duration<double>(t1Heap - t0Heap).count();
  statsHeap.secs_total = tiempoLecturaHeap;

  /*
    =============================================
    Comparar los árboles y mostrar el resultado
    =============================================
  */
  TList inordenAVL, inordenRN, inordenHeap;

  // TODO #05: Llamar la función que genera el recorrido en inorden del árbol AVL y lo guarda en una lista dada como parámetro.
  miArbolAVL.InOrden(inordenAVL); // muestra y guarda en lista 
  // TODO #10: Llamar la función que genera el recorrido en inorden del árbol rojinegro y lo guarda en una lista dada como parámetro.
  miArbolRN.InOrden(inordenRN);
  // TODO #15: Llamar la función que genera el recorrido en inorden del montículo y lo guarda en una lista dada como parámetro.
  // miMonticulo.inordenEnLista(inordenHeap);

  std::size_t sizeAVL = inordenAVL.size();
  std::size_t sizeRN = inordenRN.size();
  std::size_t sizeHeap = inordenHeap.size();

  std::size_t minSize = std::min({sizeAVL, sizeRN, sizeHeap});

  std::cout << "\n------------------ Resumen de tamaños (inorden) ------------------\n";
  std::cout << " AVL               : " << sizeAVL << " elementos\n";
  std::cout << " Árbol Rojo-Negro  : " << sizeRN << " elementos\n";
  std::cout << " Heap              : " << sizeHeap << " elementos\n";

  if (sizeAVL == sizeRN && sizeRN == sizeHeap)
  {
    std::cout << " ==> Las tres estructuras tienen la misma cantidad de elementos.\n";
  }
  else
  {
    std::cout << " ==> La estructura con menos elementos tiene " << minSize << " elemento(s).\n";
  }

  /*
    ===============================================================
    Comparar los elementos y su posición de cada uno de los árboles
    ===============================================================
  */

  // TODO #16: Crear iteradores para recorrer cada una de las estructuras lineales
  // TList::iterator itAVL  = inordenAVL.begin();
  // TList::iterator itRN   = inordenRN.begin();
  // TList::iterator itHeap = inordenHeap.begin();

  // TODO #17: Recorrer las estructuras lineales y comparar elemento a elemento la igualdad o desigualdad
  // bool todosIguales = true;
  // for (std::size_t i = 0; i < minSize; ++i, ++itAVL, ++itRN, ++itHeap) {
  //   if (!(*itAVL == *itRN && *itRN == *itHeap)) {
  //     std::cout << " Diferencia en la posicion " << i
  //               << " | AVL: " << *itAVL
  //               << " | RN: "  << *itRN
  //               << " | Heap: "<< *itHeap << "\n";
  //     todosIguales = false;
  //   }
  // }

  // TODO #18: Informar si los árboles coinciden en la totalidad de los elementos teniendo en cuenta su posición
  // if (todosIguales && sizeAVL == sizeRN && sizeRN == sizeHeap) {
  //   std::cout << " ==> Coincidencia total: los tres recorridos inorden son idénticos.\n";
  // } else if (todosIguales) {
  //   std::cout << " ==> Coincidencia parcial: igualdad en posiciones comparadas, pero tamaños distintos.\n";
  // } else {
  //   std::cout << " ==> No hay coincidencia total entre las tres estructuras.\n";
  // }

  ImprimirResumen("ESTADÍSTICAS ÁRBOL AVL", statsAVL, medirCadaOperacion);
  
  ImprimirResumen("ESTADÍSTICAS ÁRBOL ROJO-NEGRO", statsRN, medirCadaOperacion);
  
  // ImprimirResumen("ESTADÍSTICAS MONTÍCULO", statsHeap, medirCadaOperacion);

  return (0);
}

template <class TArbol>
bool LeerArbol(TArbol &arbol, const std::string &nomArch, bool medirCadaOperacion, ReadStats &stats)
{
  std::ifstream entrada(nomArch.c_str());
  if (!entrada)
    return false;

  std::string codigo, valor;
  using clock_t = std::chrono::steady_clock;
  while (entrada >> codigo >> valor)
  {
    std::chrono::steady_clock::time_point t0 = clock_t::now();

    if (codigo == "add")
    {
      arbol.insertar(valor);
      std::chrono::steady_clock::time_point t1 = clock_t::now();
      if (medirCadaOperacion)
      {
        double secs = std::chrono::duration<double>(t1 - t0).count();
        stats.secs_add += secs;
      }
      ++stats.ops_add;
      ++stats.ops_total;
    }
    else if (codigo == "del")
    {
      arbol.eliminar(valor);
      std::chrono::steady_clock::time_point t1 = clock_t::now();
      if (medirCadaOperacion)
      {
        double secs = std::chrono::duration<double>(t1 - t0).count();
        stats.secs_del += secs;
      }
      ++stats.ops_del;
      ++stats.ops_total;
    }
  }

  entrada.close();
  return true;
}

// eof - taller_3_ordenamiento_busqueda.cxx
