
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <queue>

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

using namespace std;

enum Color{blanco, negro, sin_color};

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
class Guardias{
public:
   Guardias(Grafo const& grafo): guardias(grafo.V(), sin_color), visitados(grafo.V(), false), pelean(false), min(-1), V(grafo.V()){}

   bool esPosible(Grafo const& grafo){
      int i = 1;
      pair<int, int> sol_parcial;
      while (i < grafo.V() && !pelean){
         if (!visitados[i]) {
            sol_parcial = bfs(grafo, i);
            if (!pelean) {
                  if (min == -1) min = sol_parcial.second;
                  else min += sol_parcial.second;
                  soluciones.push(sol_parcial);
               }
         }
         i++;
      }
      return min != -1;
   }

   int calcula_minimo() { 
      pair<int, int> aux;
      min = 0;
      while (!soluciones.empty()) {
         aux = soluciones.front();
         min += minimo(aux.second, aux.first - aux.second);
         soluciones.pop();
      }
      return min;
   }

private: 
   int min;
   int V;
   vector<bool> visitados;
   vector<Color> guardias;
   queue<pair<int, int>> soluciones;
   bool pelean;

   int minimo(int a, int b){
      if (a <= b) return a;
      return b;
   }

   pair<int, int> bfs(Grafo const& grafo, int ini){
      int num_guardias = 0;
      int componentes = 0;
      if (!grafo.ady(ini).empty()) {
         num_guardias++;
         guardias[ini] = negro;
      }
      else guardias[ini] = blanco;
      queue<int> cola;
      cola.push(ini);
      while(!cola.empty()){
         if(pelean)
            return {-1, -1};
         int v = cola.front();
         cola.pop();
         for(int w: grafo.ady(v)){
            if(guardias[w] == sin_color){
               if(guardias[v] == blanco) {
                  guardias[w] = negro;
                  num_guardias++;
               }
               else guardias[w] = blanco;
            }
            else if (guardias[v] == guardias[w]){
               pelean = true;
            }
            if(!visitados[w]) cola.push(w);
         }
         visitados[v] = true;
         componentes++;
      }
      return {componentes, num_guardias};
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
   if(guardias.esPosible(grafo)) cout << guardias.calcula_minimo() << "\n";
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