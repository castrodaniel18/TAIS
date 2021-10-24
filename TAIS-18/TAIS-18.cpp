
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include "Digrafo.h"

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
class Sumidero{
public:
<<<<<<< HEAD
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
=======
    Sumidero(Digrafo const & grafo): sumidero(-1){
        sumidero = 0;
        for(int i = 1; i < grafo.V(); i++){
            if(grafo.hayArista(sumidero, i))
                sumidero = i;
        }
        for(int i = 0; i < grafo.V() && sumidero != -1; i++){
            if(i != sumidero && (grafo.hayArista(sumidero, i) || !grafo.hayArista(i, sumidero)))
                sumidero = -1;
        }
    }

    int haySumidero(){ return sumidero; }
private:
    int sumidero;

>>>>>>> 02f30f3b977642f51279495cdedec820c45b3136
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    Digrafo grafo(cin);

    if (!std::cin)  // fin de la entrada
    return false;

<<<<<<< HEAD
    vector<vector<int>> grafo(V * V);
    cin >> A;
    cin >> v >> w;
    for(int i = 1; i < A; i++){
        cin >> v >> w;
    }

    Sumidero sumidero(grafo, V);
    int sol = sumidero.solucion();
=======
    Sumidero sumidero(grafo);

    int sol = sumidero.haySumidero();
    if(sol != -1) cout << "SI " << sol << "\n";
    else cout << "NO" << "\n";
>>>>>>> 02f30f3b977642f51279495cdedec820c45b3136

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
