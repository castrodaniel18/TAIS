
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
void resolver(PriorityQueue<long long int, less<long long int>>& v, vector<long long int>& total) {
   if (v.size() > 1) {
      long long int coste = v.top();
      v.pop();
      coste += v.top();
      v.pop();
      v.push(coste);
      total.push_back(coste);
      resolver(v, total);
   }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
   long long int n, elem, sol = 0;
   cin >> n;
   if (n == 0)
      return false;
   //if (n == 1) return n;
   PriorityQueue<long long int, less<long long int>> v;
   vector<long long int> total;
   for (int i = 0; i < n; i++) {
      cin >> elem;
      v.push(elem);
   }
   resolver(v, total);
   while(!total.empty()) {
      sol += total.back();
      total.pop_back();
   }
   // escribir sol
   cout << sol << endl;
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
