
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

#include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "Dijkstra.h"

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
class Paginas{
public:
    Paginas(DigrafoValorado<int> const &grafo, vector<int>const &tiempos_carga): sol(-1){
        Dijkstra<int> dijkstra(grafo, tiempos_carga, 0);
        if(dijkstra.hayCamino(grafo.V() - 1))
            sol = dijkstra.distancia(grafo.V() - 1);
    }

    int solucion(){ return sol; }

private:
    int sol;

};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int N, t, A, v, w, k;
    // leer los datos de la entrada
    cin >> N;
    if (N == 0)
        return false;

    vector<int> tiempos_carga(N);
    for(int i = 0; i < N; i++){
        cin >> t;
        tiempos_carga[i] = t;
    }

    DigrafoValorado<int> grafo(N);
    cin >> A;
    for(int i = 0; i < A; i++){
        cin >> v >> w >> k;
        grafo.ponArista({v - 1, w - 1, k});
    }
    Paginas paginas(grafo, tiempos_carga);

    // escribir sol
    if(paginas.solucion() != -1) cout << paginas.solucion() + tiempos_carga[0] << "\n";
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
