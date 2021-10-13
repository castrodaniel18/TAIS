
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int V, A, v, w;
    // leer los datos de la entrada
    cin >> V;
    if (!std::cin)  // fin de la entrada
    return false;

    vector<vector<int>> grafo(V * V + 1);

    cin >> A;
    for(int i = 0; i < A; i++){
        cin >> v >> w;
        grafo[v][w] = 1;
    }

    //Solucion sol = resolver(datos);

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
