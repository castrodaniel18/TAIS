
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

#include "ARM_Kruskal.h"  // propios o los de las estructuras de datos de clase

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
class Islas{
public:
    Islas(GrafoValorado<int> const &grafo):conectados(0), visitados(grafo.V(), false){
        dfs(grafo, 0);
    }

    int calcula_puentes(GrafoValorado<int> const &grafo){
        ARM_Kruskal<int> arm(grafo);
        return arm.costeARM();
    }

    bool es_conexo(int V){ return conectados == V; }

private:
    int conectados;
    vector<bool> visitados;

    void dfs(GrafoValorado<int> const &grafo, int v){
        visitados[v] = true;
        conectados++;
        for(auto arista: grafo.ady(v)){
            int w = arista.otro(v);
            if(!visitados[w]){
                dfs(grafo, w);
            }
        }
    }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int V, A, v, w, k;
    // leer los datos de la entrada
    cin >> V >> A;

    if (!std::cin)  // fin de la entrada
        return false;

    GrafoValorado<int> grafo(V);    
    for(int i = 0; i < A; i++){
        cin >> v >> w >> k;
        grafo.ponArista({v - 1, w - 1, k});
    }

    Islas islas(grafo);

    // escribir sol
    if(islas.es_conexo(grafo.V())) cout << islas.calcula_puentes(grafo) << "\n";
    else cout << "No hay puentes suficientes\n";

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
