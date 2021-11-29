
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

#include "Matriz.h"  // propios o los de las estructuras de datos de clase
using namespace std;

int aibofobia(string const& palabra, int i, int j, Matriz<int> & patin) {
    int & res = patin[i][j];
    if (res == -1) {
        if (i > j) res = 0;
        else if (i == j) res = 0;
        else if (palabra[i] == palabra[j])
            res = aibofobia(palabra, i+1, j-1, patin);
        else
            res = min(aibofobia(palabra, i+1, j, patin)+1,aibofobia(palabra, i, j-1, patin)+1);
    }
    return res;
}

string reconstruir(string const& palabra, Matriz<int> const& patin,int i, int j) {
   if (i > j) return {};
   if (i == j) return { palabra[i] };
   if (palabra[i] == palabra[j])
   return palabra[i] + reconstruir(palabra, patin, i+1, j-1) + palabra[j];
   else if (patin[i][j] == patin[i][j-1]+1)
      return palabra[j] + reconstruir(palabra, patin, i, j-1) + palabra[j];
   else
      return palabra[i] + reconstruir(palabra, patin, i+1, j)+ palabra[i];
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   string palabra;

   // leer los datos de la entrada
   cin >> palabra;
   if (!std::cin)  // fin de la entrada
      return false;
   Matriz<int> M(palabra.size(), palabra.size(), -1);
   int sol = aibofobia(palabra, 0, palabra.size() - 1, M);

   // escribir sol
   cout << sol << " " << reconstruir(palabra, M, 0, palabra.size() - 1) << "\n";
   
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
