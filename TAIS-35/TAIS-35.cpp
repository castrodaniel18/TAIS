
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

const long long int INF = 10000000000;

struct cordel{
    long long int longitud;
    long long int precio;
};

bool es_posible(vector<cordel> const &c, long long int L){
    vector<bool> posible(L + 1, false);
    posible[0] = true;
    for(long long int i = 1; i <= c.size(); i++){
        for(long long int j = L; j >= c[i-1].longitud; j--){
            posible[j] = posible[j - c[i-1].longitud] || posible[j];
        }
    }
    return posible[L];
}

long long int resuelve_matematico(vector<cordel> const &c, long long int L){
    vector<long long int> cuerdas(L+1, 0);
    cuerdas[0] = 1;
    for(long long int i = 1; i <= c.size(); i++){
        for(long long int j = L; j >= c[i-1].longitud; j--){
            cuerdas[j] = cuerdas[j] + cuerdas[j - c[i-1].longitud];
        }
    }
    return cuerdas[cuerdas.size()-1];
}

long long int resuelve_ingeniero(vector<cordel> const &c, long long int L){
    vector<long long int> cuerdas(L+1, INF);
    cuerdas[0] = 0;
    for(long long int i = 1; i <= c.size(); i++){
        for(long long int j = L; j >= c[i-1].longitud; j--){
            cuerdas[j] = min(cuerdas[j], cuerdas[j - c[i-1].longitud] + 1);
        }
    }
    return cuerdas[cuerdas.size() - 1];
}

long long int resuelve_economista(vector<cordel> const &c, long long int L){
    vector<long long int> cuerdas(L+1, INF);
    cuerdas[0] = 0;
    for(long long int i = 1; i <= c.size(); i++){
        for(long long int j = L; j >= c[i-1].longitud; j--){
            cuerdas[j] = min(cuerdas[j], cuerdas[j - c[i-1].longitud] + c[i-1].precio);
        }
    }
    return cuerdas[cuerdas.size() - 1];
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    long long int N, L, l, c;
    // leer los datos de la entrada
    cin >> N >> L;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<cordel> cuerdas(N);
    for(long long int i = 0; i < N; i++){
        cin >> l >> c;
        cuerdas[i] = {l, c};
    }

    if(es_posible(cuerdas, L)){
        cout << "SI ";

        cout << resuelve_matematico(cuerdas, L) << " ";

        cout << resuelve_ingeniero(cuerdas, L) << " ";

        cout << resuelve_economista(cuerdas, L) << "\n";

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
