
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
int devoradora(vector<int>const &cubos, int ini, int fin) {
   if(ini == fin)
      return cubos[ini];
   else if(ini + 1 == fin)
      return max(cubos[ini], cubos[fin]);
   else {
      int aux1, aux2;
      if(cubos[ini] > cubos[fin - 1])
         aux1 = devoradora(cubos, ini + 1, fin - 1) + cubos[fin];
      else 
         aux1 = devoradora(cubos, ini, fin - 2) + cubos[fin];
      if(cubos[ini + 1] < cubos[fin])
         aux2 = devoradora(cubos, ini + 1, fin - 1) + cubos[ini];
      else 
         aux2 = devoradora(cubos, ini + 2, fin) + cubos[ini];

      return max(aux1, aux2);
   }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   int N, cubo;
   // leer los datos de la entrada
   cin >> N;
   if (N == 0)  // fin de la entrada
      return false;
   
   vector<int> cubos;
   for(int i = 0; i < N; i++){
      cin >> cubo;
      cubos.push_back(cubo);
   }
   int sol = devoradora(cubos, 0, N - 1);
   
   // escribir sol
   cout << sol << "\n";

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
