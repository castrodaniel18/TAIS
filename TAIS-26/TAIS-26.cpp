
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

#include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "Dijkstra.h"

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
class Ratones{
public:
   Ratones(DigrafoValorado<int>& grafo, int S, int T): ratones(0){
      Dijkstra<int> dijkstra(grafo, S);
      for(int v = 0; v < grafo.V(); v++){
         if( v != S && dijkstra.distancia(v) <= T) ratones++;
      }
   }

   int salida(){ return ratones; }

private:
   int ratones;
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   int N, S, T, P, A, B, K;
   // leer los datos de la entrada
   cin >> N >> S >> T >> P;
   if (!std::cin)  // fin de la entrada
      return false;
   
   DigrafoValorado<int> grafo(N);
   for(int i = 0; i < P; i++){
      cin >> A >> B >> K;
      A--; B--;
      grafo.ponArista({B, A, K});
   }
   
   Ratones ratones(grafo, S - 1, T);

   // escribir sol
   cout << ratones.salida() << "\n";

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
