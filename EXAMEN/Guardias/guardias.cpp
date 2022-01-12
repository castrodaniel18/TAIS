
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <queue>

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
class Guardias{
   public:
      Guardias(Grafo const& g) : visit(g.V(), false), dist(g.V()), posible(true), minGuardias(0){
         int i = 0; 
         while(posible && i < g.V()){
            if (!visit[i]){
               bfs(g, i);
            }
            i++;
         }
      }

      bool es_posible(){ return posible; }
      int min_guardias(){ return minGuardias; }

   private:
      vector<bool> visit;
      vector<int> dist;
      int minGuardias;
      bool posible;

      void bfs(Grafo const& g, int s) { 
         int guardias_par = 0, guardias_impar = 0;
         queue<int> q;
         dist[s] = 0; 
         visit[s] = true; 
         guardias_par++;
         q.push(s);
         while (posible && !q.empty()) {
            int v = q.front(); q.pop(); 
            for (int w : g.ady(v)) {
               if (!visit[w]) {
                  dist[w] = dist[v] + 1; visit[w] = true; q.push(w);
                  if(dist[w] % 2 == 0) guardias_par++;
                  else guardias_impar++;
               } 
               else if(dist[w] % 2 == dist[v] % 2) posible = false;
            }
         }
         if(posible) minGuardias += min(guardias_par, guardias_impar);
      }
   };

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   int V, A, a, b;
   // leer los datos de la entrada
   cin >> V >> A;
   if (!std::cin)  // fin de la entrada
      return false;
   Grafo grafo(V);
   for(int i = 0; i < A; i++){
      cin >> a >> b;
      grafo.ponArista(a - 1, b - 1);
   }
   Guardias guardias(grafo);
   
   // escribir sol
   if(guardias.es_posible()) cout << guardias.min_guardias() << "\n";
   else cout << "IMPOSIBLE\n";
   
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
