
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
class Necronomicon{
public:
   Necronomicon(Digrafo const &grafo):visitados(grafo.V(), false), marcados(grafo.V(), false), ciclos(false){
      dfs(grafo, 0);
   }

   bool fin(){ return visitados[visitados.size() - 1]; }

   bool hay_ciclos(){ return ciclos; }

private:
   vector<bool> visitados;
   vector<bool> marcados;
   bool ciclos;

   void dfs(Digrafo const &grafo, int v){
      visitados[v] = true;
      marcados[v] = true;
      for(auto w: grafo.ady(v)){
         if(!visitados[w]){
            dfs(grafo, w);
         }
         else if (marcados[w]){
            ciclos = true;
         }
      }
      marcados[v] = false;
   }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   int L, v, w;
   string tipo;
   // leer los datos de la entrada
   cin >> L;

   if (!std::cin)  // fin de la entrada
      return false;

   Digrafo grafo(L + 1);
   v = 0;
   for(int i = 0; i < L; i++){
      cin >> tipo;
      if(tipo == "A"){
         grafo.ponArista(v, v + 1);
      }
      else if(tipo == "J"){
         cin >> w;
         grafo.ponArista(v, w - 1);
      }
      else if(tipo == "C"){
         cin >> w;
         grafo.ponArista(v, w - 1);
         grafo.ponArista(v, v + 1);
      }
      v++;
   }

   Necronomicon necronomicon(grafo);

   //escribir la solucion
   if(!necronomicon.fin()) cout << "NUNCA\n";
   else{
      if(necronomicon.hay_ciclos()) cout << "A VECES\n";
      else cout << "SIEMPRE\n";
   }
   
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
