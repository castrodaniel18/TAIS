
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

using namespace std;

struct Cofre { int peso; int valor; };
int cofres_rec(vector<Cofre> const& obj, int i, int j, Matriz<double> & cofres) {
   if (cofres[i][j] != -1) // subproblema ya resuelto
      return cofres[i][j];

   if (i == 0 || j == 0) 
      cofres[i][j] = 0;
   else if (obj[i-1].peso > j)
      cofres[i][j] = cofres_rec(obj, i-1, j, cofres);
   else
   cofres[i][j] = max(cofres_rec(obj, i-1, j, cofres),
   cofres_rec(obj, i-1, j - obj[i-1].peso, cofres)
   + obj[i-1].valor);

   return cofres[i][j];
}

pair<int, int> resuelve(vector<Cofre> const& objetos, int M, vector<bool> & sol) {
   int n = objetos.size();
   Matriz<double> cofres(n+1, M+1, -1);
   int valor = cofres_rec(objetos, n, M, cofres);
   // cálculo de los objetos
   int i = n, j = M, cont = 0; 
   sol = vector<bool>(n, false);
   while (i > 0 && j > 0) {
      if (cofres[i][j] != cofres[i-1][j]) {
         sol[i-1] = true; j = j - objetos[i-1].peso;
         cont++;
      }
      --i;
   }
   return {valor, cont};
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   int T, N, p, o;

   // leer los datos de la entrada
   cin >> T >> N;
   if (!std::cin)  // fin de la entrada
      return false;
   
   vector<Cofre> cofres(N);
   for(int i = 0; i < N; i++){
      cin >> p >> o;
      cofres[i] = {p * 3, o};
   }

   vector<bool> sol;
   pair<int, int> aux = resuelve(cofres, T, sol);
   
   // escribir sol
   cout << aux.first << "\n";
   cout << aux.second << "\n";
   for(int i = 0; i < sol.size(); i++){
      if(sol[i]) cout << cofres[i].peso/3 << " " << cofres[i].valor << "\n"; 
   }
   cout << "---\n";
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
