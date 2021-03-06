
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(priority_queue<int, vector<int>, less<int>> alturas, priority_queue<int, vector<int>, less<int>> esquis) {
    int sol = 0;
    bool derrota = false;
    while(!alturas.empty() && !derrota){
        sol += abs(alturas.top() - esquis.top());
        alturas.pop();
        esquis.pop();
    }
    return sol;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n, dato;
    // leer los datos de la entrada
    cin >> n;
    if (n == 0)
        return false;
    priority_queue<int, vector<int>, less<int>> alturas;
    priority_queue<int, vector<int>, less<int>> esquis;

    for(int i = 0; i < n; i++){
        cin >> dato;
        alturas.push(dato);
    }
    for(int i = 0; i < n; i++){
        cin >> dato;
        esquis.push(dato);
    }
    int sol = resolver(alturas, esquis);

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
