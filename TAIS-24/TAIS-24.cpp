
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
class Cole{
public:
    Cole(DigrafoValorado<int> const& grafo){
        Dijkstra dijkstra(grafo, 0);
        sol = dijkstra.numCaminos();
    }

    int solucion(){ return sol; }

private:
    int sol;

};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int N, C, v, w, k;
    // leer los datos de la entrada
    cin >> N >> C;
    if (!std::cin)  // fin de la entrada
        return false;
        
    DigrafoValorado<int> grafo(N);
    for(int i = 0; i < C; i++){
        cin >> v >> w >> k;
        v--;
        w--;
        grafo.ponArista({v, w, k});
        grafo.ponArista({w, v, k});
    }
    Cole cole(grafo);

    // escribir sol
    cout << cole.solucion() << "\n";

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
