
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(PriorityQueue<int, greater<int>>& libros) {
    int sol = 0; 
    while(libros.size() > 2){
        libros.pop();
        libros.pop();
        sol += libros.top(); libros.pop();
    }
    return sol;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   int N, libro;
   // leer los datos de la entrada
   cin >> N;
   if (!std::cin)  // fin de la entrada
      return false;
   
   PriorityQueue<int, greater<int>> libros; 
   for(int i = 0; i < N; i++){
       cin >> libro;
       libros.push(libro);
   }
   int sol = resolver(libros);
   
   // escribir sol
   cout << sol << "\n";
   
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
