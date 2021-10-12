
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>  // propios o los de las estructuras de datos de clase
#include <queue>

using namespace std;

const int MAX = 10000;

int sig(int v, int i){
   switch(i){
      case 0: return (v + 1) % MAX;
      case 1: return (v * 2) % MAX;
      case 2: return v / 3;
   }
}

int bfs(int origen, int destino){
   if(origen == destino) return 0;
   vector<int> distancias(MAX, -1);
   distancias[origen] = 0;
   queue<int> cola;
   cola.push(origen);
   while(!cola.empty()){
      int v = cola.front();
      cola.pop();
      for(int i = 0; i < 3; i++){
            int w = sig(v, i);
            if(distancias[w] == -1){
               distancias[w] = distancias[v] + 1;
               if(w == destino) return distancias[w];
               cola.push(w);
            }
      }
   }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   int origen, destino;
   // leer los datos de la entrada
   cin >> origen >> destino;

   if (!std::cin)  // fin de la entrada
      return false;
   
   // escribir sol

   cout << bfs(origen, destino) << "\n";
   
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
