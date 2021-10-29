
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(priority_queue<int, vector<int>, less<int>>& enemigos, priority_queue<int, vector<int>, less<int>> &defensas) {
    int derrotas = 0;
    while(!enemigos.empty()){
        if(defensas.empty() || defensas.top() < enemigos.top())
            derrotas++;
        else 
            defensas.pop();
        enemigos.pop();
    }
    return derrotas;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   int N, dato;

   // leer los datos de la entrada
   cin >> N;

   if (!std::cin)  // fin de la entrada
      return false;
   
    priority_queue<int, vector<int>, less<int>> enemigos;
    priority_queue<int, vector<int>, less<int>> defensas;

    for(int i = 0; i < N; i++){
        cin >> dato;
        enemigos.push(dato);
    }

    for(int i = 0; i < N; i++){
        cin >> dato;
        defensas.push(dato);
    }

   int sol = resolver(enemigos, defensas);
   
   // escribir sol
   cout << N - sol << '\n';
   
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
