
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
    Guardias(Grafo const& grafo): visitados(grafo.V(), sin_color), sol(0), imposible(false){
        int i = 0;
        while (i < grafo.V() && !imposible){
            if(visitados[i] == sin_color){
               visitados[i] = blanco;
               auto aux = dfs(grafo, i);
               sol += minimo(aux.first, aux.second - aux.first);
            }
            i++;
        }
        if(imposible) sol = -1;
    }

    int solucion(){ return sol; }

private: 

   vector<Color> visitados;
   int sol;
   bool imposible;

   int minimo(int a, int b){
      if(a <= b) return a;
      return b;
   }

  pair<int, int> dfs(Grafo const& grafo, int v){
      int num_guardias = 0, cruces = 1;
      Adys ady = grafo.ady(v);
      for(int i = 0; i < ady.size() && !imposible; i++){
         int w = ady[i];
         if(visitados[w] == sin_color){
            if(visitados[v] == negro) {
               visitados[w] = blanco;
            }
            else{
               visitados[w] = negro;
               num_guardias++;
            } 
            auto aux = dfs(grafo, w);
            num_guardias += aux.first;
            cruces += aux.second;
         }
         else if(visitados[v] == visitados[w]) imposible = true;
      }
      return {num_guardias, cruces};
   }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   int N, A, v, w;
   // leer los datos de la entrada
   cin >> N >> A;
   if (!std::cin)  // fin de la entrada
      return false;

   Grafo grafo(N);
   for(int i = 0; i < A; i++){
      cin >> v >> w;
      grafo.ponArista(v - 1, w - 1);
   }

   Guardias guardias(grafo);
   
   // escribir sol
   int sol = guardias.solucion();
   if(sol != -1) cout << sol << "\n";
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
