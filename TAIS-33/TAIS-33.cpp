
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct restaurante {
    int ini;
    int fin;
};

bool operator<(restaurante const& a, restaurante const& b) {
    return a.ini < b.ini;
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(vector<restaurante>& restaurantes, int L) {
    int fin_tramo = 0, i = 0, sol = 0;
    bool imposible = false;
    while (fin_tramo < L && !imposible) {
        int temp = fin_tramo;
        while (i < restaurantes.size() && restaurantes[i].ini <= fin_tramo) {
            if (restaurantes[i].fin > temp) {
                temp = restaurantes[i].fin;
            }
            i++;
        }
        if (temp > fin_tramo) {
            fin_tramo = temp;
            sol++;
        }
        else imposible = true;
    }
    if (imposible) return -1;
    return restaurantes.size() - sol;
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int L, N, x, r;
    // leer los datos de la entrada
    cin >> L >> N;
    if (!std::cin) // fin de la entrada
        return false;
    vector<restaurante> restaurantes;
    for (int i = 0; i < N; i++) {
        cin >> x >> r;
        restaurantes.push_back({ x - r, x + r });
    }
    sort(restaurantes.begin(), restaurantes.end());
    int sol = resolver(restaurantes, L);
    // escribir sol
    cout << sol << "\n";
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
