
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

#include "Matriz.h"  // propios o los de las estructuras de datos de clase
#include "EnterosInf.h"

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
vector<EntInf> resolver(vector<int>const &diana, int V) {
    int n = diana.size();
    Matriz<EntInf> cuerdas(n+1, V+1, Infinito);
    cuerdas[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        cuerdas[i][0] = 0;
        for (int j = 1; j <= V; ++j)
            if (diana[i-1] > j)
                cuerdas[i][j] = cuerdas[i-1][j];
            else
                cuerdas[i][j] = min(cuerdas[i-1][j], cuerdas[i][j - diana[i-1]] + 1);
    }
    vector<EntInf> sol;
    if (cuerdas[n][V] != Infinito) {
        int i = n, j = V;
        while (j > 0) { // no se ha pagado todo
            if (diana[i-1] <= j && (cuerdas[i][j - diana[i-1]] + 1 < cuerdas[i-1][j] || cuerdas[i][j - diana[i-1]] + 1 == cuerdas[i-1][j])) {
                // tomamos una moneda de tipo i
                sol.push_back(diana[i-1]); j = j - diana[i-1];
            } else // no tomamos más monedas de tipo i
                --i;
        }
    }
    return sol;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int V, S, p;
    // leer los datos de la entrada
    cin >> V >> S;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> diana;
    for(int i = 0; i < S; i++){
        cin >> p;
        diana.push_back(p);
    }

    auto sol = resolver(diana, V);
    // escribir sol
    if(!sol.empty()){
        cout << sol.size() << ": ";
        for(int i = 0; i < sol.size(); i++){
            cout << sol[i] << " ";
        }
        cout << "\n";
    }
    else cout << "Imposible\n";

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
