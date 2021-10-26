
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
class Camiones{
public:
    Camiones(GrafoValorado<int>const &grafo, int ini, int fin, int ancho)
    : hayCamino(false), visitados(grafo.V(), false){
        dfs(grafo, ini, fin, ancho);
    }

    bool pasaCamion(){ return hayCamino; }

private:
    vector<bool> visitados;
    bool hayCamino;

    void dfs(GrafoValorado<int>const &grafo, int ini, int fin, int ancho){
        visitados[ini] = true;
        for(auto arista: grafo.ady(ini)){
            if(!visitados[fin]){
                int w = arista.otro(ini);
                if(ancho <= arista.valor()){
                    if(!visitados[w]){
                        if(w == fin) {
                            hayCamino = true;
                            return;
                        }
                        else dfs(grafo, w, fin, ancho);
                    }
                }
            }
        }
    }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int K, v, w, ancho;
   // leer los datos de la entrada
    GrafoValorado<int> grafo(cin);
    if (!std::cin)  // fin de la entrada
        return false;
  
   // escribir sol
    cin >> K;
    for (int i = 0; i < K; i++){
        cin >> v >> w >> ancho;
        Camiones camiones(grafo, v, w, ancho);
        if(camiones.pasaCamion()) cout << "SI\n";
        else cout << "NO\n";
    }
    
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
