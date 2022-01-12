// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int bizcocho_rec(vector<int> frutas, int i, int j, Matriz<int>& bizcocho) {
    int& res = bizcocho[i][j];
    if (res == -1) {
        if (i == j - 1) {
            if (frutas[i] != frutas[j] || frutas[i] == 0)
                res = 0;
            else if (frutas[i] == frutas[j])
                res = 1;
        }
        else if (frutas[i] == frutas[j] && frutas[i] != 0)
            res = bizcocho_rec(frutas, i + 1, j - 1, bizcocho) + 1;
        else
            if (frutas[i] == 0 && frutas[j] == 0) res = bizcocho_rec(frutas, i + 1, j - 1, bizcocho);
            else if (frutas[i] == 0 && frutas[i + 1] == 0) res = bizcocho_rec(frutas, i + 2, j, bizcocho);
            else if (frutas[j] == 0 && frutas[j - 1] == 0) res = bizcocho_rec(frutas, i, j - 2, bizcocho);
            else res = max(bizcocho_rec(frutas, i + 1, j - 1, bizcocho), max(bizcocho_rec(frutas, i, j - 2, bizcocho), bizcocho_rec(frutas, i + 2, j, bizcocho)));
    }
    return res;
}


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   int N, fruta;
   // leer los datos de la entrada
   cin >> N;
   if (!std::cin)  // fin de la entrada
      return false;

	vector<int> frutas(N);
   for(int i = 0; i < N; i++){
		cin >> fruta;
		frutas[i] = fruta;
   }

	Matriz<int> bizcocho(N, N, -1);
   
   // escribir sol
		cout << bizcocho_rec(frutas, 0, N-1, bizcocho) << '\n';
   
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
