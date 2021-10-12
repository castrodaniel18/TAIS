
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <stack>

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
class Noticias{
public:
   Noticias(Grafo const& grafo): visitados(grafo.V(), false), sol(grafo.V()){
      for (int i = 0; i < sol.size(); i++) sol[i] = 0;

      for(int i = 0; i < grafo.V(); i++){
          if (sol[i] == 0) {
              sol[i] = dfs(grafo, i, i);
              while (!pila.empty()) {
                  sol[pila.top()] = sol[i];
                  pila.pop();
              }
          }
      }
   }

   vector<int> const solucion(){ return sol; }

private:
   vector<bool> visitados;
   vector<int> sol;
   stack<int> pila;

   int dfs(Grafo const& grafo, int v, int a){
      visitados[v] = true;
      pila.push(v);
      int cont = 1;
      for(int nuevo: grafo.ady(v)){
         if(!visitados[nuevo]){
            cont += dfs(grafo, nuevo, v);
         }
      }
      return cont;
   }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   int V, G, tam, v, w;
   // leer los datos de la entrada
   cin >> V;
   cin >> G;

   if (!std::cin)  // fin de la entrada
      return false;

   Grafo grafo(V);
   for (int i = 0; i < G; i++) {
       cin >> tam;
       if (tam > 0) {
           cin >> v;
           for (int j = 0; j < tam - 1; j++) {
               cin >> w;
               grafo.ponArista(v - 1, w - 1);
               v = w;
           }
       }
   }

   
   Noticias noticias(grafo);
   
   // escribir sol
   for(int e: noticias.solucion())
      cout << e << " ";
   cout << "\n";
   
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
