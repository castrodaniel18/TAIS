
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include "Digrafo.h"

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
class Sumidero{
public:
    Sumidero(Digrafo const & grafo): sumidero(-1){
        sumidero = 0;
        for(int i = 1; i < grafo.V(); i++){
            if(grafo.hayArista(sumidero, i))
                sumidero = i;
        }
        for(int i = 0; i < grafo.V() && sumidero != -1; i++){
            if(i != sumidero && (grafo.hayArista(sumidero, i) || !grafo.hayArista(i, sumidero)))
                sumidero = -1;
        }
    }

    int haySumidero(){ return sumidero; }
private:
    int sumidero;

};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    Digrafo grafo(cin);

    if (!std::cin)  // fin de la entrada
    return false;

    Sumidero sumidero(grafo);

    int sol = sumidero.haySumidero();
    if(sol != -1) cout << "SI " << sol << "\n";
    else cout << "NO" << "\n";

// escribir sol

    if(sol != -1) cout << "SI " << sol << "\n";
    else cout << "NO" << "\n";

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
