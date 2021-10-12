
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "Grafo.h"  // propios o los de las estructuras de datos de clase

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

class Amigos{
public:
    Amigos(Grafo const& g): visitados(g.V(), false), max(0) {
        int cont = 0;
        for(int i = 1; i < g.V(); i++){
            if(!visitados.at(i)){
                dfs(g, i, cont);
                if(cont > max) max = cont;
                cont = 0;
            }
        }
    }
    int maximo() { return max; }
private:
    vector<bool> visitados;
    int max;

    void dfs(Grafo const& g, int v, int& cont){
        Adys ady = g.ady(v);
        visitados[v] = true;
        for(int i = 0; i < ady.size(); i++){
            int n = ady[i];
            if(!visitados[n]) dfs(g, n, cont); 
        }
        cont++;
    }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    Grafo g(cin);
    // leer los datos de la entrada
    Amigos amigos(g);
    // escribir solución
    cout << amigos.maximo() << "\n";
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
