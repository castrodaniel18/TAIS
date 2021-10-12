
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
class Papel{
public:
   Papel(Grafo const& grafo, vector<int> supermercados)
      :precios(supermercados), soluciones(grafo.V(), -1), visitados(grafo.V(), false){}

   void buscaPapel(Grafo const& grafo, int v){
      int min = -1;
      int sol = bfs(grafo, v, min);
         while(!pila.empty()){
            soluciones[pila.top()] = sol;
            pila.pop();
         }
   }

   bool sinSolucion(int v){ return !visitados[v]; }

   bool esPosible(int v){ return soluciones[v] != -1 || !visitados[v]; }

   int solucion(int v){ return soluciones[v]; }

private:
   vector<int> soluciones;
   vector<bool> visitados;
   vector<int> precios;
   stack<int> pila; 

   int bfs(Grafo const& grafo, int v, int& min){
      visitados[v] = true;
      pila.push(v);
      if((min == -1 && precios[v] != -1)|| precios[v] < min) 
         min = precios[v];

      for(int i: grafo.ady(v)){
         if(!visitados[i]) bfs(grafo, i, min);
      }
      return min;
   }

};
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   int S, K, v, p;
   // leer los datos de la entrada
   Grafo grafo(cin);
   if (!std::cin)  // fin de la entrada
      return false;

   cin >> S;
   vector<int> supermercados(grafo.V(), -1);
   for(int i = 0; i < S; i++){
      cin >> v >> p;
      supermercados[v] = p;
   }

   Papel papel(grafo, supermercados);
   cin >> K;
   for(int i = 0; i < K; i++){
      cin >> v;
      v--;
      if(papel.sinSolucion(v) && papel.esPosible(v)){
         papel.buscaPapel(grafo, v);
      }
      if(papel.esPosible(v)) 
         cout << papel.solucion(v) << "\n";
      else cout << "VAYA MARRON\n";
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
