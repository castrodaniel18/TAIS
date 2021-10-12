
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <stack>
#include <string>

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

using namespace std;

class Tareas{
public:
   Tareas(Digrafo const &grafo): visitados(grafo.V(), false), apilados(grafo.V(), false), anteriores(grafo.V()), hayCiclo(false){
      for(int i = 1; i < grafo.V(); i++){
         if(!visitados[i]){
            dfs(grafo, i);
         }
      }
   }

   string const solucion(){ 
      string sol = "";
      if(hayCiclo) return "Imposible";
      while(!camino.empty()){
         sol = sol + to_string(camino.top()) + " ";
         camino.pop();
      } 
      return sol;
   }

private:
   vector<bool> visitados;
   vector<bool> apilados;
   vector<int> anteriores;
   stack<int> camino;
   bool hayCiclo;

   void dfs(Digrafo const& g, int v) {
      apilados[v] = true;
      visitados[v] = true;
      for (int w : g.ady(v)) {
         if (hayCiclo) // si hemos encontrado un ciclo terminamos
            return;
         if (!visitados[w]) { // encontrado un nuevo vértice, seguimos
            anteriores[w] = v; 
            dfs(g, w);
         } 
         else if (apilados[w]) { // hemos detectado un ciclo
            hayCiclo = true;
         }
      }
      camino.push(v);
      apilados[v] = false;
   }

};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
   Digrafo grafo(cin);

   if (!std::cin)  // fin de la entrada
      return false;
   
   Tareas tareas(grafo);
   
   // escribir sol
      cout << tareas.solucion() << "\n";
   
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
