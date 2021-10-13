
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
   Guardias(Grafo const& grafo): visitados(grafo.V(), false), colocados(grafo.V(), false), distancias(grafo.V(), -1), pelean(false), min(-1), V(grafo.V()){}

   bool esPosible(Grafo const& grafo){
      int aux, i = 1;
      while (i < grafo.V() && !pelean){
         if (!visitados[i]) {
            aux = bfs(grafo, i);
            if (!pelean) {
                  if (min == -1) min = aux;
                  else min += aux;
                  soluciones.push(aux);
               }
         }
         i++;
      }
      return min != -1;
   }

   int const minimo() { 
      min = 0;
      while (!soluciones.empty()) {
         min += soluciones.front() < V - soluciones.front()? soluciones.front(): V - soluciones.front();
         soluciones.pop();
      }
      return min;
   }

private: 
   int min;
   int V;
   vector<int> distancias; 
   vector<bool> colocados;
   vector<bool> visitados;
   queue<int> soluciones;
   bool pelean;

   int bfs(Grafo const& grafo, int ini){
      int guardias = 0;
      if (!grafo.ady(ini).empty()) guardias++;
      colocados[ini] = true;
      distancias[ini] = 0;
      queue<int> cola;
      cola.push(ini);
      while(!cola.empty()){
         if(pelean)
            return -1;
         int v = cola.front();
         cola.pop();
         for(int w: grafo.ady(v)){
            if(distancias[w] == -1){
               distancias[w] = distancias[v] + 1;
               if(distancias[w] % 2 == 0) {
                  colocados[w] = true;
                  guardias++;
               }
            }
            else if ((colocados[w] && colocados[v])|| (!colocados[w] && !colocados[v])){
               pelean = true;
            }
            if(!visitados[w]) cola.push(w);
         }
         visitados[v] = true;
      }
      return guardias;
   }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
   Grafo grafo(cin);

   if (!std::cin)  // fin de la entrada
      return false;
   
   Guardias guardias(grafo);
   
   // escribir sol
   if(guardias.esPosible(grafo)) cout << guardias.minimo() << "\n";
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
