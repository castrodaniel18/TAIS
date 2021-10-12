
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <queue>

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
class Redes{
public:
    Redes(Grafo const& grafo,int v, int ttl): visitados(grafo.V(), false), TTL(ttl), V(v), distancias(grafo.V()) {
        sol = grafo.V() - bfs(grafo, v, TTL);
    }

    int const solucion(){ return sol; }

private:
    vector<bool> visitados;
    vector<int> distancias;
    int TTL;
    int sol;
    int V;

    int bfs(Grafo const& grafo, int v, int ttl){
        queue<int> q;
        int cont = 1;
        visitados[v] = true;
        distancias[v] = 0;
        q.push(v);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int w : grafo.ady(v)) {
                if (!visitados[w] && distancias[v] + 1 <= ttl) {
                    visitados[w] = true;
                    distancias[w] = distancias[v] + 1;
                    q.push(w);
                    cont++;
                }
            }
        }
        return cont;
    }

};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   int n, ttl, v;
   // leer los datos de la entrada
   Grafo grafo(cin);
   if (!std::cin)  // fin de la entrada
      return false;
   cin >> n;
   for(int i = 0; i < n; i++){
     cin >> v >> ttl;
     Redes redes (grafo, v - 1, ttl);   
     cout << redes.solucion() << "\n";
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
