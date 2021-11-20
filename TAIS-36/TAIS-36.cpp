
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

#include "Matriz.h"  // propios o los de las estructuras de datos de clase
#include "EnterosInf.h"

using namespace std;

bool es_posible(vector<int>const &diana, int V){
    vector<bool> posible(V + 1, false);
    posible[0] = true;
    for(int i = 0; i < diana.size(); i++){
        for(int j = V; j >= diana[i]; j--){
            posible[j] = posible[j - diana[i]] || posible[j];
        }
    }
    return posible[V];
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
pair<EntInf, vector<EntInf>> resolver(vector<int>const &diana, int V) {
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

    int puntos = V, i = n, j = V;
    vector<EntInf> sol;
    while(puntos > 0){
        if(cuerdas[i - 1][j - diana[i - 1]] != Infinito){
            sol.push_back(diana[i - 1]);
            puntos -= diana[i - 1];
            j -= diana[i - 1];
        }
        else{
            i--;
        }
    }
    return {cuerdas[n][V], sol};
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

    // escribir sol
    if(es_posible(diana, V)){
        auto sol = resolver(diana, V);
        cout << sol.first << ": ";
        for(int i = 0; i < sol.second.size(); i++){
            cout << sol.second[i] << " ";
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
