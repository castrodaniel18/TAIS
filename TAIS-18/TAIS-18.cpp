
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
class Sumidero{
public:
    Sumidero(const vector<vector<int>>& grafo, int v): sumidero(-1), V(v){
        sumidero = 0;
        for(int i = 1; i < V; i++){
            if(hayArista(sumidero, i, grafo)) 
                sumidero = i;
        }
        int j = 0;
        while(sumidero != -1 && j < V){
            if(hayArista(sumidero, j, grafo)) 
                sumidero = -1;
        }   
    }

    int const solucion(){ return sumidero;}

private:
    int sumidero;
    int V;

    bool hayArista(int a, int b, const vector<vector<int>>& grafo){
        return grafo[a][b] == 1;
    }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int V, A, v, w;
    // leer los datos de la entrada
    cin >> V;
    if (!std::cin)  // fin de la entrada
    return false;

    vector<vector<int>> grafo(V * V);
    cin >> A;
    cin >> v >> w;
    for(int i = 1; i < A; i++){
        cin >> v >> w;
    }

    Sumidero sumidero(grafo, V);
    int sol = sumidero.solucion();

// escribir sol

    if(sol != -1) cout << "SI " << sol << "\n";
    else cout << "NO" << "\n";

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
