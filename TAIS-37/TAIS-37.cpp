
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
pair<int, int> resolver_tablero(Matriz<int>const &tablero) {
   Matriz<int> sol(tablero.numfils(), tablero.numcols(), 0);
   for(int i = 0; i < tablero.numfils(); i++)
      sol[0][i] = tablero[0][i];

   for(int i = 1; i < sol.numfils(); i++){
      for(int j = 0; j < sol.numcols(); j++){
         //arriba a la izquierda
         if(j - 1 >= 0)
            if(sol[i - 1][j - 1] + tablero[i][j] > sol[i][j]) 
               sol[i][j] = sol[i - 1][j - 1] + tablero[i][j];
         //arriba
         if(sol[i - 1][j] + tablero[i][j] > sol[i][j]) 
            sol[i][j] = sol[i - 1][j] + tablero[i][j];
         //arriba a la derecha
         if(j + 1 < sol.numcols())
            if(sol[i - 1][j + 1] + tablero[i][j] > sol[i][j]) 
               sol[i][j] = sol[i - 1][j + 1] + tablero[i][j];
      }
   }

   int max = 0, pos = 0; 
   for(int i = 0; i < sol.numcols(); i++){
      if(max < sol[sol.numcols() - 1][i]){
         max = sol[sol.numcols() - 1][i];
         pos = i; 
      }
   }
   return {max, pos + 1};
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   int N, v;
   // leer los datos de la entrada
   cin >> N;
   if (!std::cin)  // fin de la entrada
      return false;

   Matriz<int> tablero(N, N);
   for(int i = 0; i < N; i++){
         for(int j = 0; j < N; j++){
            cin >> v;
            tablero[i][j] = v;
         }
   }
   pair<int, int> sol = resolver_tablero(tablero);

   // escribir sol
   cout << sol.first << " " << sol.second << "\n";

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
