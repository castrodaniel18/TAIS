
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

const int INF = 1000000000;

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
   vector<int> luces(PMax + 1, INF);
   luces[0] = 0;

   for(int i = 1; i <= bombillas.size(); i++){
      for(int j = bombillas[i - 1].potencia; j <= PMax; j++){
         luces[j] = min(luces[j], luces[j - bombillas[i - 1].potencia] + bombillas[i - 1].coste);
      }
   }
   int sol = INF, ind = 0;
   for(int i = PMin; i <= PMax; i++){
      if(luces[i] < sol){
         sol = luces[i];
         ind = i;
      }
   }
   return {sol, ind};
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
   if(sol.first != INF) cout << sol.first << " " << sol.second << "\n";
   else cout << "IMPOSIBLE\n";

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
