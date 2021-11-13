
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

#include "EnterosInf.h"  // propios o los de las estructuras de datos de clase
#include "Matriz.h"

using namespace std;

EntInf resuelve_matematico(vector<pair<int, int>> const &c, int L){
    int n = c.size();
    Matriz<EntInf> cuerdas(n+1, L+1, Infinito);
    cuerdas[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        cuerdas[i][0] = 0;
        for (int j = 0; j <= L; ++j){
            if (c[i-1].first > j)
                cuerdas[i][j] = cuerdas[i-1][j];
            else if(j == c[i-1].first) cuerdas[i][j] = 1;
            else {
                if(cuerdas[i - 1][j] == Infinito)
                    cuerdas[i][j] = cuerdas[i][j - c[i - 1].first];
                else 
                    cuerdas[i][j] = cuerdas[i - 1][j] + cuerdas[i][j - c[i - 1].first];
            }
        }
    }
    return cuerdas[n][L];
}

EntInf resuelve_ingeniero(vector<pair<int, int>> const &c, int L){
    int n = c.size();
    Matriz<EntInf> cuerdas(n+1, L+1, Infinito);
    cuerdas[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        cuerdas[i][0] = 0;
        for (int j = 1; j <= L; ++j)
            if (c[i-1].first > j)
                cuerdas[i][j] = cuerdas[i-1][j];
            else
                cuerdas[i][j] = min(cuerdas[i-1][j], cuerdas[i][j - c[i-1].first] + 1);
    }
    return cuerdas[n][L];
}

EntInf resuelve_economista(vector<pair<int, int>> const &c, int L){
    int n = c.size();
    Matriz<EntInf> cuerdas(n+1, L+1, Infinito);
    cuerdas[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        cuerdas[i][0] = 0;
        for (int j = 1; j <= L; ++j)
            if (c[i-1].second > j)
                cuerdas[i][j] = cuerdas[i-1][j];
            else
                cuerdas[i][j] = min(cuerdas[i-1][j], cuerdas[i][j - c[i-1].second] + 1);
    }
    return cuerdas[n][L];
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int N, L, l, c;
    // leer los datos de la entrada
    cin >> N >> L;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<pair<int, int>> cuerdas;
    for(int i = 0; i < N; i++){
        cin >> l >> c;
        cuerdas.push_back({l, c});
    }
    sort(cuerdas.begin(), cuerdas.end());

    EntInf sol = resuelve_matematico(cuerdas, L);
    cout << sol << " ";
    sol = resuelve_ingeniero(cuerdas, L);
    cout << sol << " ";
    sol = resuelve_economista(cuerdas, L);
    cout << sol << " ";

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
