
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <algorithm>

#include "EnterosInf.h"  // propios o los de las estructuras de datos de clase
#include "Matriz.h"

using namespace std;

struct cordel{
    long long int longitud;
    long long int precio;
};

struct ordena_longitud{
    bool operator()(cordel const &a, cordel const& b){
        return a.longitud < b.longitud;
    }
};

struct ordena_precio{
    bool operator()(cordel const &a, cordel const& b){
        return a.precio < b.precio;
    }
};

bool es_posible(vector<cordel> const &c, long long int L){
    vector<bool> posible(L + 1, false);
    posible[0] = true;
    for(long long int i = 1; i < c.size(); i++){
        for(long long int j = L; j >= c[i].longitud; j--){
            posible[j] = posible[j - c[i].longitud] || posible[j];
        }
    }
    return posible[L];
}

EntInf resuelve_matematico(vector<cordel> const &c, long long int L){
    long long int n = c.size();
    Matriz<EntInf> cuerdas(n+1, L+1, Infinito);
    cuerdas[0][0] = 0;
    for (long long int i = 1; i <= n; ++i) {
        cuerdas[i][0] = 0;
        for (long long int j = 0; j <= L; ++j){
            if (c[i-1].longitud > j)
                cuerdas[i][j] = cuerdas[i-1][j];
            else {
                if(j - c[i - 1].longitud > -1){
                    cuerdas[i][j] = cuerdas[i - 1][j - c[i - 1].longitud];
                }
                if(cuerdas[i - 1][j] != Infinito){
                    cuerdas[i][j] = cuerdas[i][j] + cuerdas[i - 1][j];
                }
            }
            if (c[i-1].longitud == j) cuerdas[i][j] = cuerdas[i][j] + 1;
        }
    }
    return cuerdas[n][L];
}

EntInf resuelve_ingeniero(vector<cordel> const &c, long long int L){
    long long int n = c.size();
    Matriz<EntInf> cuerdas(n+1, L+1, Infinito);
    cuerdas[0][0] = 0;
    for (long long int i = 1; i <= n; ++i) {
        cuerdas[i][0] = 0;
        for (long long int j = 1; j <= L; ++j)
            if (c[i-1].longitud > j)
                cuerdas[i][j] = cuerdas[i-1][j];
            else
                cuerdas[i][j] = min(cuerdas[i-1][j], cuerdas[i][j - c[i-1].longitud] + 1);
    }
    return cuerdas[n][L];
}

EntInf resuelve_economista(vector<cordel> const &c, long long int L){
    long long int n = c.size();
    Matriz<EntInf> cuerdas(n+1, L+1, Infinito);
    cuerdas[0][0] = 0;
    for (long long int i = 1; i <= n; ++i) {
        cuerdas[i][0] = 0;
        for (long long int j = 1; j <= L; ++j)
            if (c[i-1].longitud > j)
                cuerdas[i][j] = cuerdas[i-1][j];
            else
                cuerdas[i][j] = min(cuerdas[i-1][j], cuerdas[i - 1][j - c[i-1].longitud] + c[i-1].precio);
    }
    return cuerdas[n][L];
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    long long int N, L, l, c;
    // leer los datos de la entrada
    cin >> N >> L;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<cordel> cuerdas;
    for(long long int i = 0; i < N; i++){
        cin >> l >> c;
        cuerdas.push_back({l, c});
    }

    if(es_posible(cuerdas, L)){
        cout << "SI ";

        sort(cuerdas.begin(), cuerdas.end(), ordena_longitud());

        EntInf sol = resuelve_matematico(cuerdas, L);
        cout << sol << " ";

        sol = resuelve_ingeniero(cuerdas, L);
        cout << sol << " ";

        sort(cuerdas.begin(), cuerdas.end(), ordena_precio());
        sol = resuelve_economista(cuerdas, L);
        cout << sol << "\n";

    }
    else cout << "NO\n";
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
