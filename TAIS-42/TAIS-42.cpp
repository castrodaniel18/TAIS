// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

using namespace std;
const int INF = 100000000;

void Floyd(Matriz<int> const& G, Matriz<int> & C, Matriz<int> & A) {
   int V = G.numfils(); // número de vértices de G
   // inicialización
   int sol = 0;
   C = G;
   A = Matriz<int>(V, V, -1);
   for (int i = 0; i < V; ++i) {
      for (int j = 0; j < V; ++j) {
         if (i != j && G[i][j] != INF)
            A[i][j] = i;
      }
   }
   for (int k = 0; k < V; ++k) {
      for (int i = 0; i < V; ++i) {
         for (int j = 0; j < V; ++j) {
            auto temp = C[i][k] + C[k][j];
            if (temp < C[i][j]) { // es mejor pasar por k
               C[i][j] = temp;
               A[i][j] = A[k][j];
            }
         }
      }
   }
}

int buscarMax(Matriz<int> & C){
   int max = 0;
   for (int i = 0; i < C.numfils(); i++){
      for (int j = 0 ; j < C.numcols(); j++){
         if (i != j){
            if (C[i][j] == INF) return INF;
            if (C[i][j] > max) max = C[i][j];
         }
      }
   }
   return max;
}
//@ <answer>

bool resuelveCaso() {
   
   int N, M;
   string valor;
   unordered_map<string,int> entrada;
   cin >>N;
   if (!std::cin)  // fin de la entrada
      return false;
   cin >> M;
   Matriz<int> datos(N,N,INF);
   Matriz <int> C(N,N,INF);
   Matriz <int> A;
   int indice = 0;
   for (int i = 0; i <M; i++){
       cin >> valor;
       if (entrada.find(valor) == entrada.end()){
           entrada.insert({valor,indice});
           indice ++;
       }
       string aux = valor;
       cin >> valor;
       if (entrada.find(valor) == entrada.end()){
           entrada.insert({valor,indice});
           indice ++;
       }
       datos[entrada[aux]][entrada[valor]] = 1;
      datos[entrada[valor]][entrada[aux]] = 1;
   }

   Floyd(datos,C,A);
   int sol = buscarMax(C);
   if (sol == INF) cout << "DESCONECTADA\n";
   else cout << sol << "\n";
   // resolver el caso posiblemente llamando a otras funciones
   // escribir la solución

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
