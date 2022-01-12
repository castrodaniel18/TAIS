
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

using namespace std;

const int INF = 1000000000;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int realiza_cortes(vector<int> const& D, Matriz<int> & P) { 
    int n = D.size() - 1;
    bool puede_cortar;
    Matriz<int> matrices(n+1,n+1,0); 
    P = Matriz<int>(n+1,n+1,0); 
    for (int d = 1; d <= n-1; ++d) // recorre diagonales
        for (int i = 1; i <= n - d; ++i) { // recorre elementos de diagonal 
            int j = i + d;
            matrices[i][j] = INF;
            for (int k = i; k <= j-1; ++k) {
               if(i < D[k] && D[k] < j){
                  int temp = matrices[i][D[k]] + matrices[D[k]+1][j] + 2*(j-i +1); 
                  if (temp < matrices[i][j]) { // es mejor partir por k
                     matrices[i][j] = temp;  
                     P[i][j] = k;
                  }
               }
            }
         }
    return matrices[1][n];
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   int L, N, c;
   // leer los datos de la entrada
   cin >> L >> N;
   if (!std::cin)  // fin de la entrada
      return false;
    vector<int> cortes;
   for(int i = 0; i < N; i++){
       cin >> c;
       cortes.push_back(c);
   }
   Matriz<int> sol;
   cout << realiza_cortes(cortes, sol) << "\n";
   
   // escribir sol
   
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
