
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(vector<int> jugadores, vector<int> equipaciones) {
    int sol = 0, j = 0, e = 0;
    while(j != jugadores.size()){
        if(e != equipaciones.size()){
            if(jugadores[j] == equipaciones[e] || jugadores[j] + 1 == equipaciones[e]){
                j++;
                e++;
            }
            else e++;
        }
        else {
            sol++;
            j++;
        }
    }

    return sol;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int N, M, dato;
    // leer los datos de la entrada
    cin >> N >> M;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> jugadores;
    vector<int> equipaciones;

    for(int i = 0; i < N; i++){
        cin >> dato;
        jugadores.push_back(dato);
    }
    sort(jugadores.begin(), jugadores.end());

    for(int i = 0; i < M; i++){
        cin >> dato;
        equipaciones.push_back(dato);
    }
    sort(equipaciones.begin(), equipaciones.end());

    int sol = resolver(jugadores, equipaciones);

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
