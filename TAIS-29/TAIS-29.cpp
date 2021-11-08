
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(priority_queue<int, vector<int>, greater<int>> rivales, priority_queue<int, vector<int>, less<int>> broncos) {
    int sol = 0;
    bool derrota = false;
    while(!rivales.empty() && !derrota){
        if(rivales.top() < broncos.top()){
            sol += broncos.top() - rivales.top();
            rivales.pop();
            broncos.pop();
        }
        else derrota = true;
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
    priority_queue<int, vector<int>, greater<int>> rivales;
    priority_queue<int, vector<int>, less<int>> broncos;

    for(int i = 0; i < n; i++){
        cin >> dato;
        rivales.push(dato);
    }
    for(int i = 0; i < n; i++){
        cin >> dato;
        broncos.push(dato);
    }
    int sol = resolver(rivales, broncos);

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
