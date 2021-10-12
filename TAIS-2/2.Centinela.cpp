
// Nombre y Apellidos Daniel Castro López

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
/*
    En TreeSet_AVL.h se encuentra la función que realmenrte resuelve el problema.
    En el cpp nos limitamos a leer los datos y guardarlos en un arbol AVL para posteriormente poder hallar su elemento k-esimo 
    y capturar una excepcion en caso de que el elemento k-esimo no exista.

    Añadimos a la clase Set un nuevo atributo llamado tam_i, que nos indicará el tamaño del hijo izquierdo de un nodo más el mismo.
    La variable se inicializa a 1 y es necesario copiarla tambien con el resto de variables en el constructor de copia.
    Para ir calculando tam_i con cada inserción, aumentamos en 1 siempre que se inserte por la izquierda y la variable crece sea true, además
    debemos calcular como cambia tam_i para cada nodo cuando se producen rotaciones.

    La funcaion k-esimo, llama a una función protegida que hallará la solución al problema:
    Si la k buscada coincide con tamaño i, hemos hallado la solución,
    Si es menor, llamamos a la funcion recursivamente para resolver el lado izquierdo.
    Si es mayor, llamamos a la funcion recursivamente para resolver el lado derecho con k menos el tam_i del nodo actual.
    (descartamos todos los valores que estan a la izquierda)
*/

#include <iostream>
#include <fstream>
#include "TreeSet_AVL.h"

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   // leer los datos de la entrada
    int elem, act;
    cin >> elem;
   if (elem == 0)
      return false;
   Set<int> arbol;
   for (int i = 0; i < elem; i++){
       cin >> act;
       arbol.insert(act);
   }
   cin >> elem;
   for (int i = 0; i < elem; i++) {
      cin >> act;
      try {
          cout << arbol.kesimo(act) << endl;
      }
      catch (out_of_range& ex) {
          cout << ex.what() << endl;
      }
   }
   cout << "---" << endl;
   return true;
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   while (resuelveCaso());
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
