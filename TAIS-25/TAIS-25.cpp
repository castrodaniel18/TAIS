
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <queue>

#include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "Dijkstra.h"

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   int N, C, K, v, w, k;
   // leer los datos de la entrada
   cin >> N >> C;

   if (!std::cin)  // fin de la entrada
      return false;

   DigrafoValorado<int> grafo(N);
   for(int i = 0; i < C; i++){
      cin >> v >> w >> k;
      v--;
      w--;
      grafo.ponArista({v, w, k});
      grafo.ponArista({w, v, k});
   }
   cin >> K;
   for(int i = 0; i < K; i++){
      cin >> v >> w;
      Dijkstra<int> caminos(grafo, v - 1, w - 1);
      if(caminos.hayCamino(w - 1)){
         cout << caminos.distancia(w - 1) << " ";
         if(caminos.min_aristas_bfs() == caminos.min_aristas_dijkstra()) cout << "SI\n";
         else cout << "NO\n";
      }
      else cout << "SIN CAMINO\n";
   }

   cout << "---\n";

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
