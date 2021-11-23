
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

using namespace std;

struct bombilla {
   int potencia;
   int coste;
};

bool operator<(bombilla const& a, bombilla const &b){
   return a.potencia < b.potencia;
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
pair<int, int> resolver_bombillas(vector<bombilla>const &bombillas, int PMax, int PMin) {
   Matriz<int> sol (bombillas.size() + 1, PMax + 1, INT_MAX);
   sol[0][0] = 0;
   for(int i = 1; i <= bombillas.size(); i++){
      sol[i][0] = 0;
      for(int j = 1; j <= PMax; j++){
         if(sol.posCorrecta(i - 1, j - bombillas[i - 1].potencia))
            sol[i][j] = min(sol[i - 1][j], sol[i - 1][j - bombillas[i - 1].potencia] + bombillas[i - 1].coste);
         else sol[i][j] = sol[i - 1][j];
      }
   }
   int min = sol[bombillas.size()][PMin], pos = PMin;
   for(int i = PMin + 1; i <= PMax; i++){
      if(sol[bombillas.size()][i] < min){
         min = sol[bombillas.size()][i];
         pos = i;
      }
   }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   int N, PMax, PMin, p, c;

   // leer los datos de la entrada
   cin >> N >> PMax >> PMin;
   if (!std::cin)  // fin de la entrada
      return false;

   vector<bombilla> bombillas(N);
   for(int i = 0; i < N; i++){
      cin >> p;
      bombillas[i].potencia = p;
   }

   for(int i = 0; i < N; i++){
      cin >> c;
      bombillas[i].coste = c;
   }
   sort(bombillas.begin(), bombillas.end());
   pair<int, int> sol = resolver_bombillas(bombillas, PMax, PMin);
   
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
