
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
   int N, V, pila;
   // leer los datos de la entrada
   vector<int> pilas;
   cin >> N >> V;
   for(int i = 0; i < N; i++){
      cin >> pila;
      pilas.push_back(pila);
   }

   sort(pilas.begin(), pilas.end());
   int suma, ini = 0, fin = N - 1, coches = 0;
   bool salir = false;
   while(ini < fin){
      suma = pilas[fin] + pilas[ini];
      if(suma >= V){
         coches++;
         fin--;
      }
      ini++;
   }

   // escribir solución
   cout << coches << "\n";

}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
